#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
   // ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup();
    gui.add(guiTotal.setup("Total dots", 342, 0, 500));
    gui.add(guiRadius.setup("Radius", 185, 0, 1000));
    gui.add(guiMultiply.setup("Curves multiply", 1.945, 1, 10));
    gui.add(guiMin.setup("Minimo", 18, -200, 200));
    gui.add(guiMax.setup("Max", 149, 0, 200));
    gui.add(guiSpeedTime.setup("Speed time", 0.39, 0.000, 2));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef() * guiSpeedTime;
    float sinOfTime = sin(time * 0.371);
    float t = .8;
    //float sinOfTime = t;

    float angle = 360/guiTotal;
    
    cam.begin();
   // cam.enableOrtho();
    
    /*for(int i = 0; i < guiTotal; i++){
        // for(int z = 0; z < guiHigh; z++){
            float mult = ofMap(sinOfTime, -1, 1, 1, guiMultiply);
            float angle = ofMap(i, 0, guiTotal, 0, TWO_PI);
            float newY = ofMap(sinOfTime, -1, 1, 1 , 5);
        
            float radius = (guiRadius/2)  *  ofNoise(cos(angle), sin(angle));
        
            int x = radius * cos(angle);
            int y = radius * sin(angle);
        
            ofSetColor(255);
            ofDrawCircle(x, y, guiSize);
        // }
    }*/
    ofPushStyle();
    ofNoFill();
        ofBeginShape();
        ofSetLineWidth(1);
    
            for(int e = 0; e < guiTotal; e++){
                float x = cos(angle * e) * guiRadius;
                float y = sin(angle * e) * guiRadius;
                float z = sin(angle * e) * guiRadius;
                ofVec3f p = ofVec3f(x, y, z).normalize();
                float n = ofMap(ofNoise(p.x + time, p.y + time), 0, 1, guiMin, guiMax);
                p = p*(n*guiMultiply);
                ofVertex(p.x, p.y, e);
            }
        ofEndShape(false);
    ofPopStyle();
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
