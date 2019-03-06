#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    // ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup();
    gui.add(guiTotal.setup("Total dots", 342, 0, 700));
    gui.add(guiTotalInt.setup("Total int", 342, 1, 500));
    gui.add(guiRadius.setup("Radius", 185, 0, 200));
    gui.add(guiMultiply.setup("Curves multiply", 1.945, 0.00, 3));
    gui.add(guiMin.setup("Minimo", 18, -200, 200));
    gui.add(guiMax.setup("Max", 149, 0, 200));
    gui.add(guiSpeedTime.setup("Speed time", 0.39, 0.000, 2));
    gui.add(guiSpeedTimeMulti.setup("Speed time multi", 0.39, 0.000, 2));
    gui.add(guiStroke.setup("Stroke", 0.39, 0.0, 50));
    gui.add(guiRed.setup("Red", 127, 0, 127));
    gui.add(guiGreen.setup("Green", 127, 0, 127));
    gui.add(guiBlue.setup("Blue", 127, 0, 127));
    gui.add(guiRed2.setup("Red2", 127, 0, 255));
    gui.add(guiGreen2.setup("Green2", 127, 0, 255));
    gui.add(guiBlue2.setup("Blue2", 127, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef() * guiSpeedTime;
    
    
    cam.begin();
   
    ofMesh m;
    m.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    ofSetLineWidth(guiStroke);
    //(10);
    //ofBeginShape();
    
    for (float i = 0; i < guiTotal; i++) {
        for(int j = 0; j < guiTotalInt; j++){
            float angle = ofMap(i, 0, guiTotal, 0, TWO_PI);
            //float radius = (guiRadius/2) * sin(guiMultiply * angle);
            float sinOfTime = sin((time) * guiSpeedTime);
            float sinOfTimeMulti = sin((time) * guiSpeedTimeMulti);
            float multi = ofMap(sinOfTimeMulti, -1, 1, 0, guiMultiply);
            float r = ofMap(ofNoise(multi * cos(angle), multi * sin(angle + time)), 0, 1, guiMin, guiMax);
            float x = (guiRadius + r - (j*0.5)) * cos(angle);
            float y = (guiRadius + r - (j*0.5)) * sin(angle);
            
            ofVec3f top(x, y, 0);
            m.addVertex(top);
            m.addColor(ofColor(sin(angle*2) * guiRed + guiRed2, sin(angle*3.1) * guiGreen + guiGreen2, sin(angle*4.1) * guiBlue + guiBlue2));
           // ofCurveVertex(x, y);
            //ofDrawCircle(x, y, 2);
        }
    }
    //ofEndShape();
    m.draw();

    
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
