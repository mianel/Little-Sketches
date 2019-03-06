#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(80);
    ofEnableSmoothing();
    
    // ------ Gui ------- //
    gui.setup("setup");
    gui.add( guiBg.setup( "Background", 255, 0, 255 ));
    gui.add( guiTotal.setup( "Total dots", 250, 10, 500 ));
    gui.add( guiMin.setup( "Min", 88, -200, 500 ));
    gui.add( guiMax.setup( "Max", 101, 0, 500 ));
    gui.add( guiFreq.setup( "Frequency", 200, 1, 1000 ));
    gui.add( guiAmp.setup( "Amplitude", 1, 1, 200 ));
    
    
    radiusGroup.setup( "Radius" );
    radiusGroup.add( guiRadius.setup( "Radius", 10, 1, 1000 ));
    radiusGroup.add( guiRadiusX.setup( "Radius X", 1, 0.000, 5 ));
    radiusGroup.add( guiRadiusY.setup( "Radius Y", 1, 0.000, 5 ));
    gui.add( &radiusGroup );
    
    speedGroup.setup( "Speed" );
    speedGroup.add( guiSpeedTime.setup( "Speed time", 0.53, 0.000, 200 ));
    speedGroup.add( guiSpeedTimeSmooth.setup( "Speed smooth", 0.53, 0.000, 200 ));
    gui.add( &speedGroup );
    
    colorGroup.setup( "Colors" );
    colorGroup.add( guiColorRedMin.setup( "Red min", 100, 0, 255 ));
    colorGroup.add( guiColorRedMax.setup( "Red max", 100, 0, 255 ));
    colorGroup.add( guiColorGreen.setup( "Green", 100, 0, 255 ));
    colorGroup.add( guiColorBlue.setup( "Blue", 100, 0, 255 ));
    gui.add( &colorGroup );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(guiBg);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef() * guiSpeedTime;
    float timeSmooth = ofGetElapsedTimef() * guiSpeedTimeSmooth;
    
    ofEnableDepthTest();
    cam.enableOrtho();
    cam.begin();
    
    
    for(int e = 0; e < 5; e++){
        ofPolyline line;
        ofPushMatrix();
        ofTranslate(0, 0, e * 10);
            for(int i = 0; i < guiTotal; i++){
                float angle = ofMap(i, 0, guiTotal, 0, TWO_PI);
                float r = guiRadius + guiAmp * sin(angle * guiFreq);
                float x = r * cos(angle);
                float y = r * sin(angle);
                
               // ofDrawCircle(x, y, 2);
                //line.addVertex(x, y);
                
                ofVec2f p = ofVec2f(x, y).normalize();
                float n = ofMap(ofNoise(p.x + time * 0.03, p.y + time * 0.03), 0, 1, guiMin, guiMax);
                p = p * (n);
                
                line.addVertex(p.x + guiRadiusX, p.y + guiRadiusY);
            }
        
            line.close();
            //line.draw();
        
            ///////////////////// mesh
            ofxTriangleMesh mesh;
            mesh.triangulate(line, -1, 200);
        
            for (int i = 0; i < mesh.triangulatedMesh.getVertices().size(); i++) {
                float y = mesh.triangulatedMesh.getVertices()[i].y;
                mesh.triangulatedMesh.addColor(ofColor (
                                                        ofMap( y, -( guiAmp + guiFreq ), guiAmp + guiFreq, guiColorRedMin, guiColorRedMax-e),
                                                        guiColorGreen-e,
                                                        guiColorBlue-e));
            }
        
            mesh.triangulatedMesh.draw();
        ofPopMatrix();
    }
    
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
