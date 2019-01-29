#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(guiSpeed.setup("timer", 10, 0, 50));
    
    
    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 400, true, true, true);
    myString = "HI";
    loadCharacters(myString);
    
    lineDraw.resize(1000);
}

void ofApp::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
}

//--------------------------------------------------------------
ofPoint ofApp::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}


//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(0);
    
    float time = ofGetElapsedTimef() * 1.5;
    float ancho = 10;
    float sizeCir = 1;
    float jumpDots = 2;
    float spacing = 5;


    cam.begin();
    ofPushMatrix();
    ofTranslate(-30, -370);
    ofTranslate(centerCharacter(myString));
    ofSetLineWidth(2);
    
    
    for(int i = 0; i < characters.size(); i++){
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(spacing);
            
            for (int k = 0; k < line.size(); k += jumpDots) {
                
                ofPoint point = line[k];
                
                float x = point.x;
                float y = point.y;
                
                float sinOfTime = sin((time+(x*3)) * 3);
                float newRot = ofMap(sinOfTime, -1, 1, 5 , 10);
                float newRot2 = ofMap(sinOfTime, -1, 1, 0 , 30);
               // float newPos = ofMap(sinOfTime, -1, 1, -100 , 100);
                
                float newPos = ofMap(k, 0, line.size(), 0 , 50);
                
                ofPoint pt;
                pt.x = newRot;
                pt.y = newRot2;
                
                
               /* ofSetColor(255);
                ofPushMatrix();
                    ofTranslate(x, -y);
                    ofRotateZ(newRot2);
                    ofDrawLine(0,0, 0, 0, newRot, 10);
                ofPopMatrix();*/
                
                ofSetColor(255);
                ofPushMatrix();
                    ofTranslate(x, -y);
                    ofDrawCircle(0, 0, sizeCir);
                
                    //((k + 1)/3)
                   /* if (lineDraw[k].size() > 100) {
                        lineDraw[k].getVertices().erase(lineDraw[k].getVertices().begin());
                    }
                
                    lineDraw[k].addVertex(pt);
                    lineDraw[k].draw();*/
                
                ofPopMatrix();
                
               
            }
        }
    }
    ofPopMatrix();
    cam.end();
    
    // --------- Gui --------- //
   // gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    myString = key;
    loadCharacters(myString);
}


/*
 float x = point.x;
 float y = point.y;
 
 float sinOfTime = sin((time+(x*3)) * 3);
 float newRot = ofMap(sinOfTime, -1, 1, 0 , 360);
 float newPosY = ofMap(j, 0, lines.size(), 0 , 100);
 
 float newPos = ofMap(sinOfTime, -1, 1, -50 , 100);
 
 ofSetColor(255);
 ofPushMatrix();
 ofTranslate(x, -y);
 ofDrawCircle(0, 0, sizeCir);
 ofPopMatrix();
 
 ofPushMatrix();
 ofTranslate(x, -y);
 ofRotateZ(newRot);
 ofDrawLine(0,0, 0, 0, newPosY, 100);
 ofPopMatrix();
 */
