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
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofEasyCam cam;
    ofTrueTypeFont font;
    string myString;
    char letter;
    
    vector<ofTTFCharacter> characters;
    ofPoint centerCharacter(string s);
    ofTTFCharacter testChar;
    
    ofxPanel gui;

    ofxFloatSlider guiTotal;
    ofxFloatSlider guiQuilityString;
    ofxFloatSlider guiSpaceString;
    ofxFloatSlider guiPosX;
    ofxFloatSlider guiPosY;
    ofxFloatSlider guiDistance;
    
    ofxFloatSlider guiCurves;
    ofxFloatSlider guiRadiusMin;
    ofxFloatSlider guiRadiusMax;
    ofxFloatSlider guiSpeed;
    
    ofxFloatSlider guiRotX;
    ofxFloatSlider guiRotY;
    ofxFloatSlider guiTransZ;
    
    ofxFloatSlider guiCenterX;
    ofxFloatSlider guiCenterY;
};
