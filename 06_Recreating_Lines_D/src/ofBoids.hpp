//
//  ofBoids.hpp
//  06_Recreating_Flocking_A
//
//  Created by Pao G. Olea on 12/13/18.
//

#pragma once

#include "ofMain.h"

class ofBoids : public ofBaseApp{
    
public:
    void setup(int id, float f, float s);
    void update(float f, float s, float rA, float rC, float rS);
    void draw();
    
    ofVec3f alignment(vector<ofBoids> boids);
    ofVec3f separation(vector<ofBoids> boids);
    ofVec3f cohesion(vector<ofBoids> boids);
    
    
    void flock(vector<ofBoids> boids, float al, float co, float se);
    void edges();
   
    ofVec3f m_position;
    ofVec3f m_velocity;
    ofVec3f m_acceleration;
    
    float m_maxForce;
    float m_maxSpeed;
    float m_z;
    
    int m_id;
    int perceptionRadiusA;
    int perceptionRadiusC;
    int perceptionRadiusS;
    int m_size;
    int m_ranLen;

    
};
