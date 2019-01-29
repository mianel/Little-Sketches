#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSeedRandom(0);
    
    float w = ofGetWidth();
    float h = ofGetHeight();
    float time = ofGetElapsedTimef();
    float space = 50;
    float size = 4;
    
    for(int x = space; x < w; x+=space){
        for(int y = space; y < h; y+=space){
            float sinOfTime = sin(time * (ofRandom(2, 5)));
            float randomPosX = ofRandom(10, 30);
            float noisePos = randomPosX + ofNoise(0, sinOfTime);
            float moveDot = ofMap(sinOfTime, -1, 1, 0, -noisePos);
            float noiseScale = sinOfTime + ofNoise(0, sinOfTime);
            float scaleDot = ofMap(noiseScale, -1, 1, 1, 0.2);
            
            
            ofPushMatrix();
            ofTranslate(moveDot+x, y);
            ofScale(scaleDot, scaleDot);
            ofDrawRectangle(-(size/2), -(size/2), 0, size, size);
            ofPopMatrix();
        }
    }

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
