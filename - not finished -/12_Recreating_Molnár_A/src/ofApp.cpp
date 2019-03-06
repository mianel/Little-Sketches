#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    
    wLine = 120.0f;

    gui.setup("setup");
    gui.add( guiTotal.setup( "Total", 15, 1 , 100 ));
    gui.add( guiTotalMulti.setup( "Total Multi", 15, 1 , 15 ));
    gui.add( guiCurves.setup( "Curves", 0.3, 0.00 , 0.5 ));
    gui.add( guiRadiusMin.setup( "Radius Min", 50, -100, 100 ));
    gui.add( guiRadiusMax.setup( "Radius Max", 200, 10, 500 ));
    gui.add( guiSpeed.setup( "Speed", 10, 1, 100 ));
    gui.add( guiSize.setup( "Size", 50, 1, 100 ));
    gui.add( guiSpace.setup( "Space",35, 1, 200 ));
    gui.add( guiDistance.setup( "Distance",1, 0.1, 50 ));
    gui.add( guiToggleLines.setup("Lines", true));
    gui.add( guiToggleFill.setup("Fill", true));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofNoFill();
    ofSeedRandom(0);
    ofSetLineWidth(1);
    ofEnableDepthTest();
    
    cam.enableOrtho();
    cam.begin();

        float time = ofGetElapsedTimef();
    
    
        ofPushMatrix();
    
            for (int x = 0; x < guiTotalMulti; x++){
                for (int y = 0; y < guiTotalMulti; y++){
                    ofPolyline line;
                    float sinOfTime = sin(((time*guiSpeed)+x)*guiCurves);
                    float size = ofMap(sinOfTime, -1, 1, guiRadiusMin, guiRadiusMax);
                    
                    
                    for (int j = 0; j < guiTotal; j++){
                        ofPoint a(ofRandom(-5,max),0);
                        ofPoint b(ofRandom(guiSize*0.5,size),0);
                        ofPoint c(ofRandom(min,guiSize),guiSize*0.5);
                        ofPoint d(ofRandom(-5, guiSize*0.7),guiSize*0.5);
                    
                        ofPushMatrix();
                        ofTranslate(-270, -270, -j * guiDistance);
                        
                        
                        if(guiToggleFill){
                            ofFill();
                            ofSetColor(0);
                            ofBeginShape();
                                ofPushMatrix();
                                ofVertex(a.x + x * guiSpace, a.y + y * guiSpace);
                                ofVertex(b.x + x * guiSpace, b.y + y * guiSpace);
                                ofVertex(c.x + x * guiSpace, c.y + y * guiSpace);
                                ofVertex(d.x + x * guiSpace, d.y + y * guiSpace);
                                ofPopMatrix();
                            ofEndShape();
                        }
                        
                        if(guiToggleLines){
                            ofNoFill();
                            ofSetColor(255);
                            ofPushMatrix();
                                ofTranslate(x * guiSpace, y * guiSpace);
                                ofDrawLine(a,b);
                                ofDrawLine(b,c);
                                ofDrawLine(c,d);
                                ofDrawLine(d,a);
                            ofPopMatrix();
                        }
                        
                        ofPopMatrix();
                    }
                    
                }
            }
    
            min = 0;
            max = 0;
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
void ofApp::dragEvent(ofDragInfo info){
   
}







