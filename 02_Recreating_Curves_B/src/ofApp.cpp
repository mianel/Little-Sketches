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
    gui.add(guiSpeed.setup("speed", 10, 0, 15));
    gui.add(guiForce.setup("force", 1.0, 1.0, 10.0));
    gui.add(guiArea.setup("radius mouth", 30, 0, 100));
    gui.add(guiMicro.setup("micro", 0, 0.00, 1.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(0);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = guiSpeed;
    float size = guiForce;
    float space = 10;
    
    cam.begin();
    cam.enableOrtho();
    
    ofPushMatrix();
    //ofRotateZ(rot);
    
    for(float i = 0; i < TWO_PI; i += 0.015){
        for(float b = 0; b < 50; b++){
            float radius = (size * cos(i)) - (b * space);
            float sinOfTime = sin((time+(i*3)) * 3);
            float newY = ofMap(sinOfTime, -1, 1, 0 , radius);
            //float color = 255 - (i * (200/TWO_PI));
            
            
            float x = (radius * cos(i)) - (size/2);
            float y = (newY * sin(i));
            float z = -(i*50 + sin(i));
            
            float colorR = 100 + z;
            float colorG = 50 + y;
            float colorB = 255;
            
            ofPoint pt;
            pt.x = x;
            pt.y = y;
            pt.z = z;
            
            ofSetColor(colorR, colorG, colorB);
            
          /*  if( i > 1){
                if (line[i].size() > 10) {
                    line[i].getVertices().erase(line[i].getVertices().begin());
                }
            
                line[i].addVertex(pt);
                line[i].draw();
            }
            */
           
            ofDrawCircle(x, y, z, 1);
        }
    }
    ofPopMatrix();
    cam.end();
    
    if(rot < 360){
        rot += 0.25;
    }else{
        rot = 0;
    }

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
