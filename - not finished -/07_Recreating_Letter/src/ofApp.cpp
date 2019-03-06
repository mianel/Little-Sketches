#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    font.load("fonts/HelveticaNeueLTStd-Bd.otf", 200, true, true, 1);
    myString = "S";
    loadCharacters(myString);
}

//--------------------------------------------------------------
void ofApp::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
}

//--------------------------------------------------------------
ofPoint ofApp::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);

    cam.begin();
    ofSeedRandom(0);
    //  float depthY = 100;
    float sizeCir = 2;
    float jumpDots = 1;
    float coutDot = 10;
    
    float time = ofGetElapsedTimef() * 1.5;
    float stageW = ofGetWidth();
    float stageH = ofGetHeight();
    
    ofPushMatrix();
    ofTranslate(centerCharacter(myString).x, centerCharacter(myString).y - 200);
    
    ofRotateX(180);
    ofSetLineWidth(0);
    
    for(int i = 0; i < characters.size(); i++){
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(10);
            
            for (int i = 0; i < line.size(); i += jumpDots) {
                
                ofPoint point = line[i];
                ofPushMatrix();
                ofTranslate(point.x, point.y);
                //ofDrawCircle(0, 0, 1);
                ofDrawLine(0, 0, 0, 0, 0, 100);
               // ofDrawLine(0, 0, 10, 10);
                ofPopMatrix();
            }
        }
    }
    ofPopMatrix();
    cam.end();
    
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
