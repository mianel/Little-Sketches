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
    gui.add(guiSize.setup("amplitude", 1, 1, 20));
    gui.add(guiSpace.setup("space", 10, 0, 30));
    gui.add(guiMany.setup("radius", 10, 5, 200));
    gui.add(guiFor.setup("total dots", 50, 1, 100));
    gui.add(guiAround.setup("around", 20, 1, 50));
    gui.add(guiWhat.setup("pi", 0.3, 0.01, 10));
    gui.add(guiDot.setup("scale", 1, 3, 10));
    gui.add(guiOther.setup("spaceScale", 70, 10, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   // ofSetLineWidth(0);
    
    ofSetColor(255);
    ofSetLineWidth(0);
    ofSetColor(255);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = guiTimer;
    float totalDots = guiFor;
    float totalDupli = guiAround;
    float totalScale = guiDot;
    float size = 1;
    float space = guiSpace;
    float amplitude = guiSize;
    float frequency = 10;
    float phase = 13.0;
    float radius = guiMany;
    float spaceScale = guiOther;
    
    
    ofPushMatrix();
    ofTranslate(centerX, centerY);
    
    for(int i = 0; i < totalDots; i++){
        for(int f = 0; f < totalDupli; f++){
            for(int g = 0; g < totalScale; g++){
                float angle = ofMap(i, 0, totalDots, 0, guiWhat);
                float sinOfTime = sin((time) * 2);
                float newY = ofMap(sinOfTime, -1, 1, 1 , 25);
                float input = (newY * angle) + phase;
                float radiusB = ((radius - (f * space)) + (g * spaceScale)) + 2 * amplitude * ofNoise(newY * cos(angle*100), newY * sin(angle));
                
                float x = (radiusB * cos(angle));
                float y = (radiusB * sin(angle));
                
                float colorR = 100 + x;
                float colorG = 50 + y;
                float colorB = 255;
                
                
                float color = 255 - (f * (255/totalDupli));
                float colorAlpha = 255 - (g * (255/totalScale)) + 50;
                
                ofSetColor(colorR, colorG, colorB);
                ofDrawCircle(x, y, size);
            }
        }
    }
    ofPopMatrix();
    
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
