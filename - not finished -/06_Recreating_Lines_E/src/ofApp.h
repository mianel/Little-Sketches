#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void loadCharacters(string s);
    
    void keyPressed(int key);
    
    ofEasyCam cam;
    
    ofxPanel gui;
    ofxFloatSlider guiSpeed;
    
    ofTrueTypeFont font;
    string myString;
    
    vector<ofTTFCharacter> characters;
    ofPoint centerCharacter(string s);
    
    vector <ofPolyline> lineDraw;
    
};
