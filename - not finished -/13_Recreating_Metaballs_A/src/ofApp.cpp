#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = 800;
    h = 800;
    img.allocate(w, h, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0, w, h);
    
    
    unsigned char * pixels = img.getPixels().getData();
    unsigned char * data = new unsigned char[w * h * 4];
    // unsigned char * pixels = img.getPixels();
    int components = img.bpp / 8;
    
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            int index =  ofGetMouseY() * w * 3 + ofGetMouseX() * 3;
            float d = ofDist(x, y, w/2, h/2);
            // img.getPixels().setColor(index, ofColor(x, 0, y));
            // img.setColor(index, ofColor(x, 0, y));
            int r = pixels[index];
            int g = pixels[index+1];
            int b = pixels[index+2];
            
           // ofSetColor(r, g, b);
            img.setColor(index, ofColor(r, x, y));
        }
    }
    
    img.update();
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
