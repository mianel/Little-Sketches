#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	float time = ofGetElapsedTimef();
	float total = 30;

	for (int i = 0; i < total; i++) {
		float sinOfTimeX = sin((time * i)*0.3);
		float x = ofMap(sinOfTimeX, -1, 1, 0, ofGetWidth());
		float sinOfTimeY = sin((time* 40+i) *0.3);
		float y = ofGetHeight() / 2 + ofMap(sinOfTimeY, -1, 1, 0, 400) - 200;

		//cout << y << endl;
		ofSetColor(200, 0, 0);
		ofDrawCircle(x, y, 5);

		if (i == ofRandom(0, 15)) {
			ofPoint pt;
			pt.x = x;
			pt.y = y;

			if (line.size() > 300) {
				line.getVertices().erase(line.getVertices().begin());
			}

			line.addVertex(pt);
			line.draw();
		}
	}
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
