#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    
    fbo.allocate(800, 800);
    fbo.begin();
    ofClear(0, 0, 0);
    fbo.end();
    
    int total = 500;
    m_boids.resize(total);
    line.resize(total);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(guiAlign.setup("Align", 1, 0, 5));
    gui.add(guiCohesion.setup("Cohesion", 1, 0, 5));
    gui.add(guiSeparation.setup("Separation", 1, 0, 5));
    gui.add(guiMaxForce.setup("Force", 1, 0, 5));
    gui.add(guiMaxSpeed.setup("Speed", 4, 0, 10));
    gui.add(guiRadiusA.setup("Radius Align", 50, 0, 200));
    gui.add(guiRadiusC.setup("Radius Cohesion", 50, 0, 200));
    gui.add(guiRadiusS.setup("Radius Separation", 50, 0, 200));
    gui.add(guiSize.setup("Size", 1.25, 1, 5));
    
    
    for(int i = 0; i < m_boids.size(); i++){
        m_boids[i].setup(i, guiMaxForce, guiMaxSpeed);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < m_boids.size(); i++){
        m_boids[i].update(guiMaxForce, guiMaxSpeed, guiRadiusA, guiRadiusC, guiRadiusS);
        m_boids[i].edges();
        m_boids[i].flock(m_boids, guiAlign, guiCohesion, guiSeparation);
       
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom();
    ofSetLineWidth(2);
    ofEnableSmoothing();
    
    
    
    fbo.begin();
        ofClear(0, 0, 0);
        cam.begin();
    
        for(int i = 0; i < m_boids.size(); i++){
            ofPushMatrix();
                ofTranslate(-400, -400, m_boids[i].m_z);
            
            
                float m_color = ofMap(m_boids[i].m_z, 0, 200, 10, 255);
                ofSetColor(m_color);
            
                line[i].addVertex(m_boids[i].m_position.x, m_boids[i].m_position.y);
            
                if(line[i].size() > m_boids[i].m_ranLen){
                    line[i].getVertices().erase(line[i].getVertices().begin());
                }
            
                line[i].draw();
                //m_boids[i].draw();
            
            ofPopMatrix();
        }
    
        cam.end();
        gui.draw();
    fbo.end();
    
    fbo.draw(0, 0);
}
