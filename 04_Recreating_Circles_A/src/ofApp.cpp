#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(80);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    
    float margin = 40;
    float size = 40;
    
    float mapMouseX = ofMap(mouseX, 0, ofGetWidth(), 0, 5, true);
    float mapMouseY = ofMap(mouseY, 0, ofGetHeight(), 0, 5, true);
    
    for(int x = -2; x < 5; x++){
        for(int y = -2; y < 5; y++){
            ofPushMatrix();
            ofTranslate(300, 300);
            if (x % 2 == y % 2) {
                ofDrawEllipse(x*size, y*size, size, size);
            }
            ofPopMatrix();
        }
    }
    
    /*
    float maxGrid = 30;
    float x = 0; // creo x y es 0
    float size = 50;
    float margin = 20;
    
    float mapMouseX = ofMap(mouseX, 0, ofGetWidth(), 0, size, true);
    float mapMouseY = ofMap(mouseY, 0, ofGetHeight(), 0, size, true);
    
    for (int i = 0; i < maxGrid; i++) {
        
        float y = 0; // creo y es 0
        float dx = ofMap(i + 1, 0, maxGrid, 0, size, true);
        

        for (int j = 0; j < maxGrid; j++) {
            float dy = ofMap(j + 1, 0, maxGrid, 0, size, true);
            
            cout << (int)mapMouseX << endl;
            
            // si i par es igual a j par, se dibuja
            if (i % 2 == j % 2) {
                
                ofSetColor(0);
                ofDrawEllipse(margin + x, margin + y, dx, dy);
                
                ofSetColor(255, 0, 0);
                string t = ofToString(i);
                ofDrawBitmapString(t, x, y);
            }
            y += dy;
        }
        
        x += dx;
    }
     */
}

