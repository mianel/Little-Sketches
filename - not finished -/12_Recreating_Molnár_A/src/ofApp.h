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
    
    float max, min, space;
    float wLine;
    
     ofEasyCam cam;
    
    ofxPanel gui;
    ofxFloatSlider guiTotal;
    ofxFloatSlider guiTotalMulti;
    ofxFloatSlider guiCurves;
    ofxFloatSlider guiSpeed;
    ofxFloatSlider guiRadiusMin;
    ofxFloatSlider guiRadiusMax;
    ofxFloatSlider guiSize;
    ofxFloatSlider guiSpace;
    ofxFloatSlider guiDistance;
    ofxToggle guiToggleLines;
    ofxToggle guiToggleFill;
};
    

    
    
