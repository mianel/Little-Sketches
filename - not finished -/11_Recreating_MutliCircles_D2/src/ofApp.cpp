#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);

    guiMain.setup("Main", "settingsMain.xml");
    guiMain.setPosition(10, 10);
    //guiMain.loadFromFile( "settingsMain.xml" );
    guiMain.add( guiTotal.setup( "Total", 1, 1 , 500 ));
    guiMain.add( guiCurves.setup( "Curves", 0.1, 0.000 , 0.1));
    guiMain.add( guiRadiusMin.setup( "Radius Min", 100, 10, 500 ));
    guiMain.add( guiRadiusMax.setup( "Radius Max", 200, 10, 500 ));
    guiMain.add( guiDistance.setup( "Distance", 20, 2, 30 ));
    guiMain.add( guiSpeed.setup( "Speed", 10, 1, 100 ));
    guiMain.add( guiRotX.setup( "Rotation X", 5.2, -25, 25 ));
    guiMain.add( guiRotY.setup( "Rotation Y", 12.2, -25, 25 ));

    mainGroup.setup("Main Setup");
    mainGroup.add( guiPosX.setup( "Pos X", 0, -500, 500 ));
    mainGroup.add( guiPosY.setup( "Pos Y", 0, -500, 500 ));
    mainGroup.add( guiMainJump.setup( "Jump Main", 0, 0, 200 ));
    mainGroup.add( guiMainSpeed.setup( "Speed Mov Y", 10, 0.00, 20 ));
    mainGroup.add( guiMainMov.setup( "Mov Y", 0.13, 0.000, 0.5 ));
    guiMain.add( &mainGroup );
    
    
    colorGroup.setup("Color Setup");
    colorGroup.add( guiColorBackground.setup( "Color Background", 0, 0 , 255 ));
    colorGroup.add( guiSpeedColor.setup( "Speed Color", 10, 1, 100 ));
    colorGroup.add( guiCurvesColor.setup( "Curves Color", 0.1, 0.00 , 0.1 ));
    colorGroup.add( guiCurvesRedMin.setup( "Red Min", 1, 0 , 255 ));
    colorGroup.add( guiCurvesRedMax.setup( "Red Max", 1, 0 , 255 ));
    colorGroup.add( guiCurvesGreenMin.setup( "Green Min", 1, 0 , 255 ));
    colorGroup.add( guiCurvesGreenMax.setup( "Green Max", 1, 0 , 255 ));
    colorGroup.add( guiCurvesBlueMin.setup( "Blue Min", 1, 0 , 255 ));
    colorGroup.add( guiCurvesBlueMax.setup( "Blue Max", 1, 0 , 255 ));
    guiMain.add( &colorGroup );
    
    gui.setup("setup", "settingsChildren.xml");
    gui.setPosition(210, 10);
    
    gui.add( guiTotalSmall.setup( "Count Childen", 3, 0 , 20 ));
    gui.add( guiPosExtra.setup( "Distribution Children", 0.2, 0.00, 3 ));
    gui.add( guiColorDiference.setup( "Color Diference", 10, 0, 30 ));
    gui.add( guiRadiusChildrenMin.setup( "Radius Child Min", 10, 1, 50 ));
    gui.add( guiRadiusChildrenMax.setup( "Radius Child Max", 10, 1, 50 ));
    gui.add( guiCurvesRandomMin.setup( "Pos Y Min", 0, 0, 50 ));
    gui.add( guiCurvesRandomMax.setup( "Pos Y Max", 5, 0, 50 ));

    circleGroup.setup("Circle Setup");
    circleGroup.add( guiTotalAngleCircle.setup( "Dots Circle", 50, 5 , 100 ));
    circleGroup.add( guiColorAlphaChild.setup( "Dots Alpha", 0, 0 , 255 ));
    
    colorChildGroup.setup("Color Children");
    colorChildGroup.add( guiCurvesChildRedMin.setup( "Child Red Min", 1, 0 , 255 ));
    colorChildGroup.add( guiCurvesChildRedMax.setup( "Child Red Max", 1, 0 , 255 ));
    colorChildGroup.add( guiCurvesChildGreenMin.setup( "Child Green Min", 1, 0 , 255 ));
    colorChildGroup.add( guiCurvesChildGreenMax.setup( "Child Green Max", 1, 0 , 255 ));
    colorChildGroup.add( guiCurvesChildBlueMin.setup( "Child Blue Min", 1, 0 , 255 ));
    colorChildGroup.add( guiCurvesChildBlueMax.setup( "Child Blue Max", 1, 0 , 255 ));
    gui.add( &colorChildGroup );

    
    gui.add( &circleGroup );
    
    
    
    
    randoms.resize(int(guiTotalSmall));
    randomInit.resize(int(guiTotalSmall));
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(guiColorBackground);
    float time = ofGetElapsedTimef();
    float angle = 360/guiTotalAngleCircle;
    
    ofSeedRandom(0);
    ofEnableDepthTest();
    cam.enableOrtho();
    cam.begin();
    
    //////////////////////////////////////////// SETUP CHILDREN: Jump
    for(float f = 0; f < guiTotalSmall; f++){
        randoms[f] = int(ofRandom(guiRadiusChildrenMin, guiRadiusChildrenMax));
        randomInit[f] = int(ofRandom(guiCurvesRandomMin, guiCurvesRandomMax));
    }
    
    
    float sinOfTimeMovY = sin((time*guiMainSpeed)*guiMainMov);
    float movYMain = ofMap(sinOfTimeMovY, -1, 1, 0, 200);
    
    //////////////////////////////////////////// MAIN CIRCLE: Draw the main circle with many circles
    ofPushMatrix();
    ofTranslate(guiPosX, guiPosY + movYMain, 0);
    for(int i = 0; i < guiTotal; i++){
        ofPushMatrix();
            float sinOfTime = sin(((time*guiSpeed)+i)*guiCurves);
            float size = ofMap(sinOfTime, -1, 1, guiRadiusMin, guiRadiusMax);
        
            float sinOfTimeColor = sin(((time*guiSpeedColor)+i)*guiCurvesColor);
            float mapR = ofMap(sinOfTimeColor, -1, 1, guiCurvesRedMin, guiCurvesRedMax);
            float mapG = ofMap(sinOfTimeColor, -1, 1, guiCurvesGreenMin, guiCurvesGreenMax);
            float mapB = ofMap(sinOfTimeColor, -1, 1, guiCurvesBlueMin, guiCurvesBlueMax);
        
            float mapRChild = ofMap(sinOfTimeColor, -1, 1, guiCurvesChildRedMin, guiCurvesChildRedMax);
            float mapGChild = ofMap(sinOfTimeColor, -1, 1, guiCurvesChildGreenMin, guiCurvesChildGreenMax);
            float mapBChild = ofMap(sinOfTimeColor, -1, 1, guiCurvesChildBlueMin, guiCurvesChildBlueMax);
        
            ofTranslate(0, 0, -i * guiDistance);
            if(i > guiMainJump){
                ofFill();
                ofSetColor(mapR, mapG, mapB);
                ofDrawCircle(0, 0, size);
            }
            

            //////////////////////////// CENTER MAIN CIRCLE: Draw the first circle
            if(i == guiMainJump){
                ofSetColor(255, 255, 255, guiColorAlphaChild);
                ofSetPolyMode(OF_POLY_WINDING_NONZERO);
                ofNoFill();
                ofPolyline line;
                //ofBeginShape();
                for(int e = 0; e < guiTotalAngleCircle; e++){
                    float cirX = cos(angle * e) * size;
                    float cirY = sin(angle * e) * size;
                    //ofVertex(cirX, cirY);
                    line.addVertex(cirX, cirY);
                }
               // ofEndShape();
                line.close();
                
                ofFill();
                ofxTriangleMesh mesh;
                mesh.triangulate(line, -1, 200);
                
                for (int h = 0; h < mesh.triangulatedMesh.getVertices().size(); h++) {
                    float mY = mesh.triangulatedMesh.getVertices()[h].y;
                    float mapRedY = ofMap(mY, -size, size, guiCurvesChildRedMin, mapRChild);
                    float mapGreenY = ofMap(mY, -size, size, guiCurvesChildGreenMin, mapGChild);
                    float mapBlueY = ofMap(mY, -size, size, guiCurvesChildBlueMin, mapBChild);
                    mesh.triangulatedMesh.addColor(ofColor(mapRedY, mapGreenY, mapBlueY));
                }
                mesh.triangulatedMesh.draw();
            }
        ofPopMatrix();
        
        
        //////////////////////////// CHILDREN: Draw the children of main circle
        
        for(float b = 0; b < guiTotalSmall; b++){
            ofPushMatrix();
                float sinOfTime2 = sin(((time*guiSpeed)+i)*guiCurves);
                float size2 = ofMap(sinOfTime, -1, 1, randoms[b] , randoms[b] + 50);
            
                float x = (size + size2) * cos(guiPosExtra * b);
                float y = (size + size2) * sin(guiPosExtra * b);
            
                float sinOfTimeColor2 = sin(((time*guiSpeedColor)+i+(b*guiColorDiference))*guiCurvesColor);
                float mapR2 = ofMap(sinOfTimeColor2, -1, 1, guiCurvesRedMin, guiCurvesRedMax);
                float mapG2 = ofMap(sinOfTimeColor2, -1, 1, guiCurvesGreenMin, guiCurvesGreenMax);
                float mapB2 = ofMap(sinOfTimeColor2, -1, 1, guiCurvesBlueMin, guiCurvesBlueMax);
            
                float mapRChild2 = ofMap(sinOfTimeColor2, -1, 1, guiCurvesChildRedMin, guiCurvesChildRedMax);
                float mapGChild2 = ofMap(sinOfTimeColor2, -1, 1, guiCurvesChildGreenMin, guiCurvesChildGreenMax);
                float mapBChild2 = ofMap(sinOfTimeColor2, -1, 1, guiCurvesChildBlueMin, guiCurvesChildBlueMax);
            
                ofTranslate(x, y, -i * guiDistance);
            
                if(i > randomInit[b]){
                    ofFill();
                    ofSetColor(mapR2, mapG2, mapB2);
                    ofDrawCircle(0, 0, size2);
                }
            
                //////////////////////////// CENTER MAIN CIRCLE: Draw the first circle
                if(i == randomInit[b]){
                    ofSetColor(255, 255, 255, guiColorAlphaChild);
                    ofNoFill();
                    ofPolyline lineChild;
                   // ofBeginShape();
                    for(int r = 0; r < guiTotalAngleCircle; r++){
                        float cirX2 = cos(angle * r) * size2;
                        float cirY2 = sin(angle * r) * size2;
                        //ofVertex(cirX2, cirY2);
                        lineChild.addVertex(cirX2, cirY2);
                    }
                    //ofEndShape();
                    lineChild.close();
                    
                    ofFill();
                    ofxTriangleMesh meshChildren;
                    meshChildren.triangulate(lineChild, -1, 200);
                    
                    for (int j = 0; j < meshChildren.triangulatedMesh.getVertices().size(); j++) {
                        float mY2 = meshChildren.triangulatedMesh.getVertices()[j].y;
                        float mapRedY2 = ofMap(mY2+10, -size2+10, size2+10, guiCurvesChildRedMin, mapRChild2);
                        float mapGreenY2 = ofMap(mY2+10, -size2+10, size2+10, guiCurvesChildGreenMin, mapGChild2);
                        float mapBlueY2 = ofMap(mY2+10, -size2+10, size2+10, guiCurvesChildBlueMin, mapBChild2);
                        
                        meshChildren.triangulatedMesh.addColor(ofColor(mapRedY2, mapGreenY2, mapBlueY2));
                    }
                    meshChildren.triangulatedMesh.draw();
                }
                
            ofPopMatrix();
            
        }
    }
    ofPopMatrix();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    guiMain.draw();
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
