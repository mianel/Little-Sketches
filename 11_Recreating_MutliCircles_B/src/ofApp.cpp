#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofBackground(0);
    
    
    gui.setup("setup");
    gui.add( guiRotX.setup( "Rotation X", 5.2, 0.000, 25 ));
    gui.add( guiRotY.setup( "Rotation Y", 12.2, 0.000, 25 ));
    gui.add( guiTransX.setup( "Translate X", 255, 0.000, 25 ));
    gui.add( guiTransY.setup( "Translate Y", 255, 0.000 , 25 ));
    
    
    
    
    gui.add( guiTotal.setup( "Count Circles", 100, 1 , 150 ));
    gui.add( guiTotalSmall.setup( "Count Childen", 3, 0 , 20 ));
    gui.add( guiCurves.setup( "Curves", 0.3, 0.00 , 0.5 ));
    gui.add( guiRadiusMin.setup( "Radius Min", 100, 10, 500 ));
    gui.add( guiRadiusMax.setup( "Radius Max", 200, 10, 500 ));
    gui.add( guiDistance.setup( "Distance", 20, 0.01, 30 ));
    gui.add( guiSpeed.setup( "Speed", 10, 1, 100 ));
    gui.add( guiPosX.setup( "Pos X", 0, -500, 500 ));
    gui.add( guiPosY.setup( "Pos Y", 0, -500, 500 ));
    gui.add( guiPosExtra.setup( "Pos Extra", 0.2, 0.00, 3 ));
    
    randoms.resize(int(guiTotalSmall));
    randomInit.resize(int(guiTotalSmall));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();

    ofSeedRandom(0);
    ofEnableDepthTest();
    cam.enableOrtho();
    cam.begin();
    
    for(float f = 0; f < guiTotalSmall; f++){
        randoms[f] = int(ofRandom(10, guiRadiusMax - 50));
        randomInit[f] = int(ofRandom(0, 3));
    }

    ofPushMatrix();
    ofTranslate(guiPosX, guiPosY, 0);
    for(int i = 0; i < guiTotal; i++){
        ofPushMatrix();
            float sinOfTime = sin(((time*guiSpeed)+i)*guiCurves);
            float size = ofMap(sinOfTime, -1, 1, guiRadiusMin, guiRadiusMax);

            ofTranslate(0, 0, -i * guiDistance);
            ofRotateX(guiRotX * i * sin(time));
            ofTranslate(0, 0, guiTransZ1 * sinOfTime);
            ofRotateY(guiRotY * i * sin(time));
        
        
            ofFill();
            ofSetColor(0);
            ofDrawCircle(0, 0, size);
            ofNoFill();
            ofSetColor(255);
            ofDrawCircle(0, 0, size);
            ofPopMatrix();
        
        
        for(float b = 0; b < guiTotalSmall; b++){
            if(i > randomInit[b]){
                ofPushMatrix();
                    float sinOfTime2 = sin(((time*guiSpeed)+i)*guiCurves);
                    float size2 = ofMap(sinOfTime, -1, 1, randoms[b] , randoms[b] + 50);
                
                    float x = (size + size2) * cos(guiPosExtra * b);
                    float y = (size + size2) * sin(guiPosExtra * b);
                
                
                    ofTranslate(x, y, -i * guiDistance);
                    ofRotateX(guiRotX * i * sin(time));
                    ofTranslate(0, 0, guiTransZ1 * sinOfTime2);
                    ofRotateY(guiRotY * i * sin(time));
                
                    ofFill();
                    ofSetColor(0);
                    ofDrawCircle(0, 0, size2);
                    ofNoFill();
                    ofSetColor(255);
                    ofDrawCircle(0, 0, size2);
                ofPopMatrix();
            }
        }
        
        
        /*
        ofPushMatrix();
            float sinOfTime2 = sin(((time*guiSpeed)+i)*guiCurves);
            float size2 = ofMap(sinOfTime, -1, 1, guiRadiusMin - 30, guiRadiusMax - 50);
            float posX = size + size2;

            float x = (size + size2) * cos(TWO_PI * guiPosExtra);
            float y = (size + size2) * sin(TWO_PI * guiPosExtra);

        
            ofTranslate(x, y, -i * guiDistance);
                ofFill();
                ofSetColor(0);
                ofDrawCircle(0, 0, size2);
                ofNoFill();
                ofSetColor(255);
                ofDrawCircle(0, 0, size2);
        ofPopMatrix();
         */
    }
    ofPopMatrix();
    cam.end();
    
    ofDisableDepthTest();
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
