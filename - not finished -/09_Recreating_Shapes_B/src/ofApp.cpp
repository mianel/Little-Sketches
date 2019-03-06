#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup("setup");
    gui.add(guiTotal.setup("Total dots", 250, 1, 1000));
    gui.add(guiRadiusX.setup("Radius X", 1, 0.000, 5));
    gui.add(guiRadiusY.setup("Radius Y", 1, 0.000, 5));
    gui.add(guiMin.setup("Minimo", 88, -200, 200));
    gui.add(guiMax.setup("Max", 101, 0, 200));
    gui.add(guiFreq.setup("Frequency", 45, 1, 100));
    gui.add(guiAmp.setup("Amplitude", 166, 1, 200));
    gui.add(guiSpeedTime.setup("Speed time", 0.53, 0.000, 2));
    gui.add(guiSpeedTimeSmooth.setup("Speed smooth", 0.53, 0.000, 2));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef() * guiSpeedTime;
    float timeSmooth = ofGetElapsedTimef() * guiSpeedTimeSmooth;
    float radius = 260;
    //float sinOfTime = sin(time * 0.371);

    cam.begin();
    
   ofPolyline line;
    for(int i = 0; i < guiTotal; i++){
        float angle = ofMap(i, 0, guiTotal, 0, TWO_PI);
        float r = radius + guiAmp * sin(angle * guiFreq);
        float x = r * cos(angle);
        float y = r * sin(angle);
        
        cout << x << endl;
        
        ofVec2f p = ofVec2f(x, y).normalize();
        float n = ofMap(ofNoise(p.x + time * ofMap(cos(timeSmooth), -1, 1, 1, guiRadiusX), p.y + time), 0, 1, guiMin, guiMax);
        p = p * (n*2);
        
        line.addVertex(p.x * guiRadiusX, p.y * guiRadiusY);
    }
    
    line.close();
   // line.draw();

    
    ofxTriangleMesh mesh;
    mesh.triangulate(line, -1, 200);
    
    for (int i = 0; i < mesh.triangulatedMesh.getVertices().size(); i++) {
        float y = mesh.triangulatedMesh.getVertices()[i].y;
        mesh.triangulatedMesh.addColor(ofColor(ofMap(y, -(guiAmp + guiFreq), guiAmp + guiFreq,
                                        ofMap(mouseX, 0, 800, 100, 255), 255), 100, 100));
    }
    
    mesh.triangulatedMesh.draw();
    
    
    // ofEndShape();
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
