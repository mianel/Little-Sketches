//
//  ofBoids.cpp
//  06_Recreating_Flocking_A
//
//  Created by Pao G. Olea on 12/13/18.
//

#include "ofBoids.hpp"
// separation: steer to avoid crowding local flockmates
// alignment: steer towards the average heading of local flockmates
// cohesion: steer to move toward the average position of local clockmates

// mag()  == length()
// setMag() == scale() or 10 * p.normalize()
// mult() == v * 3
// sub() == v1 - v2
// div() == v1 / 2

//-------------------------------------------------------------- Setup
void ofBoids::setup(int id, float f, float s){
    m_position = ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    m_velocity = ofVec3f(ofRandom(-1,1), ofRandom(-1, 1));
    m_velocity.scale(ofRandom(2, 4)); // setMag
    m_maxForce = f;
    m_maxSpeed = s;
    m_size = ofRandom(.5, 2);
    m_z = ofRandom(0, 200);
    m_ranLen = ofRandom(50, 100);
    m_id = id;
}

//-------------------------------------------------------------- Alignment
ofVec3f ofBoids::alignment(vector<ofBoids> boids){
    int total = 0;
    ofVec3f steering; // average
    
    for(int i = 0; i < boids.size(); i++){
        float distance = m_position.distance(boids[i].m_position);
        
        if(i != m_id && distance < perceptionRadiusA){
            steering += boids[i].m_velocity;
            total++;
        }
    }
    
    if(total > 0){
        steering = steering / total;
        // Quiero ir a la dirección de mi vecino pero a max vel
        steering.scale(m_maxSpeed);
        steering = steering - m_velocity;
        steering.limit(m_maxForce);
    }
    
    return steering;
}

//-------------------------------------------------------------- Separation
ofVec3f ofBoids::separation(vector<ofBoids> boids){
    int total = 0;
    ofVec3f steering; // average
    
    for(int i = 0; i < boids.size(); i++){
        float distance = m_position.distance(boids[i].m_position);
        
        if(i != m_id && distance < perceptionRadiusS){
            ofVec3f diff = m_position - boids[i].m_position;
            diff = diff / distance;
            steering += diff;
            total++;
        }
    }
    
    if(total > 0){
        steering = steering / total;
        steering.scale(m_maxSpeed);
        steering = steering - m_velocity;
        steering.limit(m_maxForce);
    }
    
    return steering;
}


//-------------------------------------------------------------- Cohesion
ofVec3f ofBoids::cohesion(vector<ofBoids> boids){
    int total = 0;
    ofVec3f steering; // average
    
    for(int i = 0; i < boids.size(); i++){
        float distance = m_position.distance(boids[i].m_position);
        
        if(i != m_id && distance < perceptionRadiusC){
            steering += boids[i].m_position;
            total++;
        }
    }
    
    if(total > 0){
        steering = steering / total;
        steering = steering - m_position;
        steering.scale(m_maxSpeed);
        steering = steering - m_velocity;
        steering.limit(m_maxForce);
    }
    
    return steering;
}

//-------------------------------------------------------------- Edges
void ofBoids::edges(){
    /*if(m_position.x > ofGetWidth()){
        m_position.x = 0;
    } else if(m_position.x < 0){
        m_position.x = ofGetWidth();
    }
    
    if(m_position.y > ofGetHeight()){
        m_position.y = 0;
    } else if(m_position.y < 0){
        m_position.y = ofGetHeight();
    }
     */
    
    if(m_position.x > ofGetWidth()){
        m_position.x = ofGetWidth();
        m_velocity *= -1;
    } else if(m_position.x < 0){
        m_position.x = 0;
        m_velocity *= -1;
    }
    
    if(m_position.y > ofGetHeight()){
        m_position.y = ofGetHeight();
        m_velocity *= -1;
    } else if(m_position.y < 0){
        m_position.y = 0;
        m_velocity *= -1;
    }
}


//-------------------------------------------------------------- Flock
void ofBoids::flock(vector<ofBoids> boids, float al, float co, float se){
    ofVec3f align = alignment(boids);
    ofVec3f cohes = cohesion(boids);
    ofVec3f separ = separation(boids);
    
    align = align * al;
    cohes = cohes * co;
    separ = separ * se;
    
    m_acceleration += separ;
    m_acceleration += align;
    m_acceleration += cohes;
}


//-------------------------------------------------------------- Update
void ofBoids::update(float f, float s, float rA, float rC, float rS){
    m_maxForce = f;
    m_maxSpeed = s;
    perceptionRadiusA = rA;
    perceptionRadiusC = rC;
    perceptionRadiusS = rS;
    
    m_position += m_velocity;
    m_velocity += m_acceleration;
    m_velocity.limit(m_maxSpeed);
    m_acceleration.set(0, 0);
}

//-------------------------------------------------------------- Draw
void ofBoids::draw(){
    ofDrawCircle(m_position.x, m_position.y, m_size);
}
