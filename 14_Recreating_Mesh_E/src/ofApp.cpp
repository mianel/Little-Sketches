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
    gui.add( guiNoiseMax.setup( "Noise Max", 1, 0.01, 2 ));
    gui.add( guiSpeedTime.setup("Speed time", 0.01, 0.000, 0.1 ));
    gui.add( guiDistance.setup("Distance Z", 1, 1, 100 ));
    gui.add( guiDistanceRadius.setup("Distance Radius", 1, -50, 50 ));
    
    gui.add( guiStroke.setup( "Stroke", 1, 0.01 , 1 ));
    gui.add( guiSpeedTimeMin.setup("Speed time Min", 0.01, 0.000, 0.9 ));
    gui.add( guiSpeedTimeMax.setup("Speed time Max", 0.01, 0.000, 0.9 ));
    
    gui.add( guiFreq.setup( "Frequency", 200, 1, 1000 ));
    gui.add( guiAmp.setup( "Amplitude", 1, 1, 200 ));
    
    gui.add( guiCor.setup( "algo", 200, 0 , 500 ));
    gui.add( guiCurvesChildRedMin.setup( "Child Red Min", 1, 0 , 255 ));
    gui.add( guiCurvesChildRedMax.setup( "Child Red Max", 1, 0 , 255 ));
    gui.add( guiCurvesChildGreenMin.setup( "Child Green Min", 1, 0 , 255 ));
    gui.add( guiCurvesChildGreenMax.setup( "Child Green Max", 1, 0 , 255 ));
    gui.add( guiCurvesChildBlueMin.setup( "Child Blue Min", 1, 0 , 255 ));
    gui.add( guiCurvesChildBlueMax.setup( "Child Blue Max", 1, 0 , 255 ));
    
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
    
    
    for(int m = 0; m < guiMulti; m++){
        ofFill();
        ofSetColor(0);
        ofBeginShape();
        for(int f = 0; f<guiTotal; f++){
            float a = ofMap(f, 0, guiTotal, 0, TWO_PI);
            float n = ofMap(sin(time), -1, 1, 0.5, guiNoiseMax);
            float rMin = ofMap(sin(time * guiSpeedTimeMin), -1, 1, guiRadiusMin-50, guiRadiusMin);
            float rMax = ofMap(sin(time * guiSpeedTimeMax), -1, 1, guiRadiusMax-50, guiRadiusMax);
            
            float xoff = ofMap(cos(a), -1, 1, 0, guiNoiseMax);
            float yoff = ofMap(sin(a), -1, 1, 0, n);
            float r = ofMap(ofNoise(xoff, yoff, zoff), 0, 1, rMin, rMax);
            float x = (r + (m*guiDistanceRadius)) * cos(a);
            float y = (r + (m*guiDistanceRadius))  * sin(a);
            ofVertex(x, y, -m*guiDistance);
        }
        ofEndShape(OF_CLOSE);
        
        ofNoFill();
        ofSetColor(255);
        ofBeginShape();
        for(int f = 0; f<guiTotal; f++){
            float a = ofMap(f, 0, guiTotal, 0, TWO_PI);
            float n = ofMap(sin(time), -1, 1, 0.5, guiNoiseMax);
            float rMin = ofMap(sin(time * guiSpeedTimeMin), -1, 1, guiRadiusMin-50, guiRadiusMin);
            float rMax = ofMap(sin(time * guiSpeedTimeMax), -1, 1, guiRadiusMax-50, guiRadiusMax);
            
            float xoff = ofMap(cos(a), -1, 1, 0, guiNoiseMax);
            float yoff = ofMap(sin(a), -1, 1, 0, n);
            float r = ofMap(ofNoise(xoff, yoff, zoff), 0, 1, rMin, rMax);
            float x = (r + (m*guiDistanceRadius)) * cos(a);
            float y = (r + (m*guiDistanceRadius))  * sin(a);
            ofSetLineWidth(2);
            ofVertex(x, y, -m*guiDistance);
            
        }
        ofEndShape(OF_CLOSE);
        
        
    }
    
    /*
    ofDisableDepthTest();
    ofPolyline line;
    float ra;
    
    for(int g = 0; g<guiTotal; g++){
        float a = ofMap(g, 0, guiTotal, 0, TWO_PI);
        float n = ofMap(sin(time), -1, 1, 0.5, guiNoiseMax);
        float rMin = ofMap(sin(time * guiSpeedTimeMin), -1, 1, guiRadiusMin-50, guiRadiusMin);
        float rMax = ofMap(sin(time * guiSpeedTimeMax), -1, 1, guiRadiusMax-50, guiRadiusMax);
        
        float xoff = ofMap(cos(a), -1, 1, 0, guiNoiseMax);
        float yoff = ofMap(sin(a), -1, 1, 0, n);
        float r = ofMap(ofNoise(xoff, yoff, zoff), 0, 1, rMin, rMax);
        float x = r * cos(a);
        float y = r * sin(a);
        ra = r;
        line.addVertex(x, y, 0);
    }
    line.close();
    
    ofFill();
    ofxTriangleMesh mesh;
    mesh.triangulate(line, -1, 200);
    
    for (int h = 0; h < mesh.triangulatedMesh.getVertices().size(); h++) {
        float mY = mesh.triangulatedMesh.getVertices()[h].y;
        float coR = ofMap( mY, -( guiAmp + guiFreq ), guiAmp + guiFreq, guiCurvesChildRedMin, guiCurvesChildRedMax);
        float coG = ofMap( mY, -( guiAmp + guiFreq ), guiAmp + guiFreq, guiCurvesChildGreenMin, guiCurvesChildGreenMax);
        float coB = ofMap( mY, -( guiAmp + guiFreq ), guiAmp + guiFreq, guiCurvesChildBlueMin, guiCurvesChildBlueMax);
        mesh.triangulatedMesh.addColor(ofColor(coR, coG, coB));
    }
    mesh.triangulatedMesh.draw();
    
    */
    zoff += guiSpeedTime;
    
    
    
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
