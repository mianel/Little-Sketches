#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    vector <int> randoms;
    vector <int> randomInit;
    bool to_pdf;
    
    ofxPanel gui;
    ofxFloatSlider guiRotX;
    ofxFloatSlider guiRotY;
    ofxFloatSlider guiTransX;
    ofxFloatSlider guiTransY;
    ofxFloatSlider guiTransZ1;
    
    ofxFloatSlider guiTotal;
    ofxFloatSlider guiTotalSmall;
    ofxFloatSlider guiCurves;
    ofxFloatSlider guiRadiusMin;
    ofxFloatSlider guiRadiusMax;
    ofxFloatSlider guiDistance;
    ofxFloatSlider guiSpeed;
    ofxFloatSlider guiPosX;
    ofxFloatSlider guiPosY;
    
    ofxFloatSlider guiPosExtra;
    
};
