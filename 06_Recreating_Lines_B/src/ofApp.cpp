#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(guiSpeed.setup("timer", 1.75, -5, 5));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    float space = 40;
    float betw = 50;
    float ancho = 10;
    float margin = 50;
    
    for(int x = 0; x < ofGetWidth() - space*2; x += betw){
        for(int y = 0; y < ofGetHeight() - space*2; y += betw){
            
            float sinOfTimeX = sin((time*5+(y*50)) * 0.5);
            float moveX = ofMap(sinOfTimeX, -1, 1, 0, 90);

            ofPushMatrix();
            ofTranslate(margin + x, margin + y);
            ofRotateZ(moveX);
            ofDrawLine(-ancho, -ancho, ancho, ancho);
            ofPopMatrix();
        }
    }
    
    // --------- Gui --------- //
   // gui.draw();
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
