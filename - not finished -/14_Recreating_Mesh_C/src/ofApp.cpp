#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofBackground(0);
    ofSeedRandom(0);
    
    gui.setup("setup");
    
    gui.add( guiTotal.setup( "Count Circles", 10, 1 , 200 ));
    gui.add( guiMulti.setup( "Multi", 10, 1 , 200 ));
    
    gui.add( guiRadiusMin.setup( "Radius Min", 100, -500, 500 ));
    gui.add( guiRadiusMax.setup( "Radius Max", 200, -500, 500 ));
    gui.add( guiNoiseMax.setup( "Noise Max", 1, 0.01, 10 ));
    gui.add( guiSpeedTime.setup("Speed time", 0.01, 0.000, 0.1 ));
    gui.add( guiDistance.setup("Distance", 1, -30, 30 ));
    gui.add( guiDepth.setup("Depth", 1, 1, 100 ));
    gui.add( guiStroke.setup( "Stroke", 1, 0.01 , 1 ));
    gui.add( guiSpeedTimeMin.setup("Speed time Min", 0.01, 0.000, 3 ));
    gui.add( guiSpeedTimeMax.setup("Speed time Max", 0.01, 0.000, 3 ));
    gui.add( guiCurveY.setup( "Curve Y", 0.1, 0.001, 0.3 ));
    gui.add( guiCurveNoise.setup( "Curve Noise", 1, 0.01, 2 ));
    gui.add( guiCurveYMin.setup( "Curve Min", 1, -500, 100 ));
    gui.add( guiCurveYMax.setup( "Curve Max", 1, -500, 100 ));
    gui.add( guiCurveSpeedTime.setup("Curve Speed", 0.01, 0.000, 0.01 ));
    
    
    myParticles.resize(5);
    
    for(int i = 0; i < myParticles.size(); i++){
        myParticles[i].setup(ofRandom(-100, 100), ofRandom(-100, 100));
       
        
        for(int n = 0; n < myParticles.size(); n++){
            if(i != n){
                float d = ofDist(myParticles[i].posX, myParticles[i].posY, myParticles[n].posX, myParticles[n].posY);
                
                if(d < 100){
                    myParticles[n].posX = myParticles[i].posX + 100;
                }
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < myParticles.size(); i++){
      
    
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    
    ofEnableDepthTest();
    cam.enableOrtho();
    cam.begin();
   
    ofNoFill();
    for(int i = 0; i < myParticles.size(); i++){
        myParticles[i].draw();
    }
    
    cam.end();
    
     ofDisableDepthTest();
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
