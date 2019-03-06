#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofBackground(0);
    
    zoff = 0;
    
    gui.setup("setup");
    
    gui.add( guiTotal.setup( "Count Circles", 10, 1 , 200 ));
    gui.add( guiMulti.setup( "Multi", 10, 1 , 200 ));
    
    gui.add( guiRadiusMin.setup( "Radius Min", 100, -500, 500 ));
    gui.add( guiRadiusMax.setup( "Radius Max", 200, -500, 500 ));
    gui.add( guiNoiseMax.setup( "Noise Max", 1, 0.01, 10 ));
    gui.add( guiSpeedTime.setup("Speed time", 0.01, 0.000, 0.1 ));
    gui.add( guiDistance.setup("Distance", 1, 1, 30 ));
    gui.add( guiStroke.setup( "Stroke", 1, 0.01 , 1 ));
    gui.add( guiSpeedTimeMin.setup("Speed time Min", 0.01, 0.000, 0.9 ));
    gui.add( guiSpeedTimeMax.setup("Speed time Max", 0.01, 0.000, 0.9 ));
        
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    ofSeedRandom(0);
    
    
    cam.begin();
    ofNoFill();
    
    for(int m = 0; m < guiMulti; m++){
        ofBeginShape();
        for(int f = 0; f<guiTotal; f++){
            float a = ofMap(f, 0, guiTotal, 0, TWO_PI);
            float n = ofMap(sin(time), -1, 1, 0.5, guiNoiseMax);
            float rMin = ofMap(sin(time * guiSpeedTimeMin), -1, 1, guiRadiusMin-50, guiRadiusMin);
            float rMax = ofMap(sin(time * guiSpeedTimeMax), -1, 1, guiRadiusMax-50, guiRadiusMax);
            
            float xoff = ofMap(cos(a), -1, 1, 0, guiNoiseMax);
            float yoff = ofMap(sin(a), -1, 1, 0, n);
            float r = ofMap(ofNoise(xoff, yoff, zoff), 0, 1, rMin, rMax);
            float x = (r + (m*guiDistance)) * cos(a);
            float y = (r + (m*guiDistance))  * sin(a);
            ofSetLineWidth(2);
            
            
            float color = ofMap(m, 0, guiMulti, 100, 255);
            ofSetColor(color);
            ofVertex(x, y);

        }
        ofEndShape(OF_CLOSE);
    }
    zoff += guiSpeedTime;
   
    
    
    cam.end();
    
    if(hide) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        hide = !hide;
    }
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
