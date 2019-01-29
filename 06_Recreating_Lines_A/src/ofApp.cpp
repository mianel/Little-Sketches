#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(guiSpeed.setup("timer", 10, 0, 50));
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
    float space = 50;
    float betw = 30;
    float ancho = 10;
    
    for(int x = 0; x < centerX - space*2 - 100; x += betw){
        for(int y = 0; y < centerY - space*2 - 100; y += betw){
            
            float sinOfTime = sin((time+(x*3)) * 3);
            float newRot = ofMap(sinOfTime, -1, 1, 0 , 360);
            
            ofPushMatrix();
            ofTranslate(250 + space + x, 200 + space + y);
            ofRotateZ(newRot);
            //ofDrawRectangle(-5, -5, 10, 10);
            ofDrawLine(-5, -5, x, y+ancho);
            ofPopMatrix();
        }
    }
    
    // --------- Gui --------- //
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
