#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    
    line.resize(24);
    rot = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(0);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    float size = 600;
    float space = 5;
    
    cam.begin();
    cam.enableOrtho();
    
    ofPushMatrix();
    ofRotateZ(rot);
    
    for(float i = 0; i < TWO_PI; i += 0.015){
        for(float b = 0; b < 1; b++){
            float radius = (size * cos(i)) - (b * space);
            float sinOfTime = sin((time+(i*3)) * 3);
            float newY = ofMap(sinOfTime, -1, 1, 0 , radius);
            float color = 255 - (i * (200/TWO_PI));
            
            float x = (radius * cos(i)) - (size/2);
            float y = (newY * sin(i));
            float z = -(i*50 + sin(i));

            ofPoint pt;
            pt.x = x;
            pt.y = y;
            pt.z = z;
            
            ofSetColor(color);
            
            if( i > 1){
                if (line[i].size() > 1000) {
                    line[i].getVertices().erase(line[i].getVertices().begin());
                }
            
                line[i].addVertex(pt);
                line[i].draw();
            }
            
           
           // ofDrawCircle(x, y, z, 1);
        }
    }
    ofPopMatrix();
    cam.end();
    
    if(rot < 360){
        rot += 0.25;
    }else{
        rot = 0;
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
