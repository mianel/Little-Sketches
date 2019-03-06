#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofBackground(0);
    
    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 300, true, true, true);
    letter = 'B';
    testChar = font.getCharacterAsPoints(letter);
    
    
    gui.setup("setup");
    gui.add( guiTotal.setup( "Total", 1, 1 , 500 ));
    gui.add( guiQuilityString.setup( "Quality String", 1, 1 , 10 ));
    gui.add( guiSpaceString.setup( "Space String", 5, 0.0 , 20 ));
    gui.add( guiPosX.setup( "Pos X", 0, -1000 , 1000 ));
    gui.add( guiPosY.setup( "Pos Y", 0, -1000 , 1000 ));
    gui.add( guiDistance.setup( "Distance", 1, 0.01 , 2 ));
    
    gui.add( guiCurves.setup( "Curves", 0.3, 0.00 , 0.5 ));
    gui.add( guiRadiusMin.setup( "Radius Min", 1, 0.1, 5 ));
    gui.add( guiRadiusMax.setup( "Radius Max", 1, 0.1, 5 ));
    gui.add( guiSpeed.setup( "Speed", 10, 1, 100 ));
    
    gui.add( guiRotX.setup( "Rotation X", 5.2, -25, 25 ));
    gui.add( guiRotY.setup( "Rotation Y", 12.2, -25, 25 ));
    gui.add( guiTransZ.setup( "guiTransZ X", 255, 0.000, 25 ));
    
    gui.add( guiCenterX.setup( "Center X", 0, -1000, 1000 ));
    gui.add( guiCenterY.setup( "Center Y", 0, -1000, 1000 ));
}

void ofApp::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    ofSeedRandom(0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    cam.enableOrtho();
    cam.begin();
    //////////////////////////////////////////////
    ofPushMatrix();
        ofTranslate(guiPosX, guiPosY, 0);
        //////////////////////////////////////////////
        /*ofPushMatrix();
            ofFill();
            ofSetColor(0);
            for(int f = 0; f < guiTotal; f++){
                float sinOfTime = sin(((time*guiSpeed)+f)*guiCurves);
                float size = ofMap(sinOfTime, -1, 1, guiRadiusMin, guiRadiusMax);
                //ofScale(size, size);
                
                ofTranslate(0, 0, f * guiDistance);
                ofRotateX(guiRotX * f * sin(time));
                //ofTranslate(0, 0, guiTransZ * sinOfTime);
                ofRotateY(guiRotY * f * sin(time));
               
                ofPushMatrix();
                ofTranslate(guiCenterX, guiCenterY);
                ofBeginShape();
                for(int k = 0; k <(int)testChar.getOutline().size(); k++){
                    if( k!= 0)ofNextContour(true) ;
                    for(int i = 0; i < (int)testChar.getOutline()[k].size(); i++){
                        ofVertex(testChar.getOutline()[k].getVertices()[i].x, testChar.getOutline()[k].getVertices()[i].y);
                    }
                }
                ofEndShape( true );
                 ofPopMatrix();
            }
        ofPopMatrix();*/
        //////////////////////////////////////////////
        ofPushMatrix();
    
            ofNoFill();
    
            for(int g = 0; g < guiTotal; g++){
                float color = 255 - (g * (255/guiTotal));
                ofSetColor(color + 5);
                
                float sinOfTime2 = sin(((time*guiSpeed)+g)*guiCurves);
                float size2 = ofMap(sinOfTime2, -1, 1, guiRadiusMin, guiRadiusMax);
                
                
                ofTranslate(0, 0, g * guiDistance);
                ofRotateX(guiRotX * g * sin(time));
                ofRotateY(guiRotY * g * sin(time));
               
                ofPushMatrix();
                ofTranslate(guiCenterX, guiCenterY);
                ofScale(size2, size2);
                ofBeginShape();
                for(int j = 0; j <(int)testChar.getOutline().size(); j++){
                    if( j!= 0)ofNextContour(true) ;
                    for(int p = 0; p < (int)testChar.getOutline()[j].size(); p++){
                        ofVertex(testChar.getOutline()[j].getVertices()[p].x, testChar.getOutline()[j].getVertices()[p].y);
                    }
                }
                ofEndShape( true );
                ofPopMatrix();
               
            }
        ofPopMatrix();
        //////////////////////////////////////////////
    ofPopMatrix();
    //////////////////////////////////////////////
    
    cam.end();
    ofDisableDepthTest();
    gui.draw();
}

ofPoint ofApp::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    letter = char(key);
    testChar = font.getCharacterAsPoints(letter);
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
