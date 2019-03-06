#include "ofApp.h"

//--------------------------------------------------------------
void ofParticle::setup(float x, float y){
    zoff = 0;
    tubeZoff = 0;
    posX = x;
    posY = y;
}

//--------------------------------------------------------------
void ofParticle::update(){
    
}

//--------------------------------------------------------------
void ofParticle::draw(){
    
    ofPushMatrix();
    ofTranslate(posX, posY);
    ofDrawCircle(posX, posY, 100);
    ofPopMatrix();
    
}
