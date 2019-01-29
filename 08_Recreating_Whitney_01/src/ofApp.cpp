#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    ofSetCircleResolution(80);
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofNoFill();
    ofSetLineWidth(1);
    
    float countCirclesX = 22;
    float countCirclesY = 40;
    float size = 35;
    float porc = 100 - ((mouseY) * 100) / 800;
    int countTotalY = int((countCirclesY * porc) / 100);
    
    float porc2 = ((mouseY) * 100) / 800;
    int countTotalY2 = int((countCirclesY * porc2) / 100);
    
   for (int i = 0; i < countCirclesX; i++) {
        float y = 0;
        for (int j = 2; j < countTotalY; j++) {
            float dy = ofMap(j + 1, 0, countTotalY, 5, size, true);
            if (i % 2 == j % 2) {
                ofSetColor(255);
                ofDrawEllipse(size+i*size, mouseY+y+10, size, dy);
            }
            y += dy;
        }
    }
    
    
    for (int a = 0; a < countCirclesX; a++) {
        float y2 = 0;
        for (int b = 1; b < countTotalY2; b++) {
            float db = ofMap(b + 1, 0, countTotalY2, 5, size, true);
            if (a % 2 == b % 2) {
                ofSetColor(255);
                ofDrawEllipse(size+a*size, mouseY+y2, size, db);
            }
            y2 -= db;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}
