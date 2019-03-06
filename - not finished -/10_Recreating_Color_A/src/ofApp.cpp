#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(80);
    ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup(); // most of the time you don't need a name
    gui.add(guiTotal.setup("Total dots", 535, 1, 1000));
    gui.add(guiRadius.setup("Radius X", 185, 1, 1000));
    gui.add(guiMin.setup("Minimo", 86, -200, 200));
    gui.add(guiMax.setup("Max", 101, 0, 200));
    gui.add(guiSpeedTime.setup("Speed time", 0.53, 0.000, 2));
    gui.add(guiFreq.setup("Frequency", 17, 1, 100));
    gui.add(guiAmp.setup("Amplitude", 166, 1, 200));
    //gui.add(guiColorTop.setup("Color top", 17, 1, 255));
    //gui.add(guiColorDown.setup("Color down", 17, 1, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
   /* for(size_t i = 0; i < mesh.getNumColors(); i++){
        mesh.getColors()[i];// Use this to get the current color
        mesh.setColor(i, ofFloatColor(0));// pass which ever ofFloatColor you want to.
    }*/
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float time = ofGetElapsedTimef() * guiSpeedTime;
   
    
    float height = 800;
    float width = 800;
    
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
             float timeSin = sin(time * guiSpeedTime) ;
            mesh.addVertex(ofPoint(x,y,0)); // make a new vertex
            mesh.addColor(ofColor(ofMap(y, 0, height, 0, 255), ofMap(timeSin, -1, 1, 100, 255), 100));  // add a color at that vertex
        }
    }
    
    for (int y = 0; y < height-1; y++){
        for (int x = 0; x < width-1; x++){
            mesh.addIndex(x + y * width);               // 0
            mesh.addIndex((x + 1) + y * width);           // 1
            mesh.addIndex(x + (y + 1) * width);           // 10
            
            mesh.addIndex((x + 1) + y * width);           // 1
            mesh.addIndex((x + 1) + (y + 1) * width);       // 11
            mesh.addIndex(x + (y + 1) * width);           // 10
        }
    }
    
    mesh.draw();

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
