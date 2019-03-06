#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    // ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup();
    gui.add(guiTotal.setup("Total dots", 10, 2, 25));
    gui.add(guiTotalInt.setup("detail", 1, 1, 1000));
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
    
    
    gui.add( guiTotalCurves.setup( "Curves", 2.0, 0.00 , 10 ));
    gui.add( guiRedMin.setup( "Red min", 0.2, 0.00 , 1 ));
    gui.add( guiRedMax.setup( "Red max", 0.4, 0.00 , 5 ));
    gui.add( guiGreenMin.setup( "Green min", 0.4, 0.00 , 1 ));
    gui.add( guiGreenMax.setup( "Green max", 0.5, 0.00 , 5 ));
    gui.add( guiBlueMin.setup( "Blue min", 0.5, 0.00 , 1 ));
    gui.add( guiBlueMax.setup( "Blue max", 0.6, 0.00 , 5 ));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofShader shader;
    shader.load("","color.frag");
    
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1f("m_curves", guiTotalCurves);
    
    
    
    
    
    
    ////////////////////////////////////
    
    ofSeedRandom(0);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef() * guiSpeedTime;
    
    ofSetLineWidth(guiStroke);
    
    ofMesh m;
    m.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    cam.begin();

    //ofBeginShape();
     for (float f = 0; f <= int(guiTotalInt); f++) {
    for (float i = -1; i <= int(guiTotal) + 1; i++) {
        float angle = ofMap(i, 0, int(guiTotal), 0, TWO_PI);
        float sinOfTime = sin(time * guiSpeedTimeMulti);
        float multi = ofMap(sinOfTime, -1, 1, 0, guiMultiply);
        float cal = ofMap(f, 0, int(guiTotalInt), 0, guiMin);
        float r = ofMap(ofNoise(multi * cos(angle),  sin(angle + time)), 0, 1, guiMin, guiMax);
        float x = (guiRadius + r) * cos(angle * (i-2));
        float y = (guiRadius + r) * sin(angle * (i-2));
        
       
        ofSetColor(255, 0, 0);
        
        ofVec3f top(x, y, -f);
        m.addVertex(top);
        m.addColor(ofColor(sin(angle*2) * guiRed + guiRed2, sin(angle*3.1) * guiGreen + guiGreen2, sin(angle*4.1) * guiBlue + guiBlue2));
        
        float myR = ofMap(sin(angle*2) * guiRed + guiRed2, 0, 255, 0.0, 1.0);
        float myG = ofMap(sin(angle*2) * guiRed + guiRed2, 0, 255, 0.0, 1.0);
        float myB = ofMap(sin(angle*2) * guiRed + guiRed2, 0, 255, 0.0, 1.0);
        
        cout << myR << endl;
        
        
        shader.setUniform1f("m_redInit", myR);
        shader.setUniform1f("m_redEnd", guiRedMax);
        shader.setUniform1f("m_greenInit", myG);
        shader.setUniform1f("m_greenEnd", guiGreenMax);
        shader.setUniform1f("m_blueInit", myB);
        shader.setUniform1f("m_blueEnd", guiBlueMax);
        
    }
     }
    //ofEndShape();
    ofDrawRectangle(-400,-400,ofGetWidth(), ofGetHeight());
    shader.end();
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
