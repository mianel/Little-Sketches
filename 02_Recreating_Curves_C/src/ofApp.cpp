#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    
    line.resize(24);
    rot = 0;
    
    // ------ Gui ------- //
    gui.setup(); // most of the time you don't need a name
    gui.add(guiTimer.setup("timer", 10, 0, 15));
    gui.add(guiSize.setup("size", 200, 1, 2000));
    gui.add(guiSpace.setup("space", 10, 0, 30));
    gui.add(guiMany.setup("micro", 0.015, 0.005, 0.025));
    gui.add(guiFor.setup("for", 50, 3, 100));
    gui.add(guiAround.setup("around", 1, 0.1, 30));
    gui.add(guiWhat.setup("what", 0.3, 0.01, 10));
    gui.add(guiDot.setup("dot", 1, 1, 10));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   // ofSetLineWidth(0);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    float size = guiSize;
    float space = guiSpace;
    
    cam.begin();
    cam.enableOrtho();
    
    ofPushMatrix();
    
    for(float i = 0; i < guiAround; i += guiMany){
        for(float b = 0; b < guiFor; b++){
            float radius = (size * cos(i)) - (b * space);
            float sinOfTime = sin((time+(i*guiWhat)) * 3);
            float newY = ofMap(sinOfTime, -1, 1, 0 , radius);
            //float color = 255 - (i * (200/TWO_PI));
            
            float x = (radius * cos(i));
            float y = (newY * sin(i));
            float z = -(i*50 + sin(i));
            
            float colorR = 100 + z;
            float colorG = 50 + y;
            float colorB = 255;
            
            ofPoint pt;
            pt.x = x;
            pt.y = y;
            pt.z = z;
            
            ofSetColor(colorR, colorG, colorB);
            ofDrawCircle(x, y, guiDot);
        }
    }
    ofPopMatrix();
    cam.end();
    
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
