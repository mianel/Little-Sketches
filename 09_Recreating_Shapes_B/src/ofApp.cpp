#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup(); // most of the time you don't need a name
    gui.add(guiTotal.setup("Total dots", 535, 0, 1000));
    gui.add(guiRadius.setup("Radius X", 185, 0, 1000));
    gui.add(guiMin.setup("Minimo", 86, -200, 200));
    gui.add(guiMax.setup("Max", 101, 0, 200));
    gui.add(guiSpeedTime.setup("Speed time", 0.53, 0.000, 2));
    gui.add(guiFreq.setup("Frequency", 17, 1, 25));
    gui.add(guiAmp.setup("Amplitude", 166, 1, 200));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef() * guiSpeedTime;
    //float sinOfTime = sin(time * 0.371);

    cam.begin();
    
    ofBeginShape();
    
    for(int i = 0; i < guiTotal; i++){
        float angle = ofMap(i, 0, guiTotal, 0, TWO_PI);
        float radius = guiRadius + guiAmp * sin(angle * guiFreq);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        
        ofVec2f p = ofVec2f(x, y).normalize();
        float n = ofMap(ofNoise(p.x + time, p.y + time), 0, 1, guiMin, guiMax);
        p = p * (n*2);
        
        ofVertex(p.x, p.y);
    }

    ofEndShape();
    cam.end();
    
    gui.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
