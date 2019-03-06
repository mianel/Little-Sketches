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
    
    // ------ Gui ------- //
    ofxPanel gui;
    
    ofxFloatSlider guiTotal;
    ofxFloatSlider guiSize;
    ofxFloatSlider guiRadius;
    ofxFloatSlider guiHigh;
    ofxFloatSlider guiCurveHigh;
    ofxFloatSlider guiMultiply;
    ofxFloatSlider guiMin;
    ofxFloatSlider guiMax;
    ofxFloatSlider guiSpeedTime;
    ofxFloatSlider guiTotalInt;
    ofxFloatSlider guiStroke;
    ofxFloatSlider guiRed;
    ofxFloatSlider guiGreen;
    ofxFloatSlider guiBlue;
    ofxFloatSlider guiRed2;
    ofxFloatSlider guiGreen2;
    ofxFloatSlider guiBlue2;
    ofxFloatSlider guiSpeedTimeMulti;
    
    ofxFloatSlider guiTotalCurves;
    ofxFloatSlider guiRedMin;
    ofxFloatSlider guiRedMax;
    ofxFloatSlider guiGreenMin;
    ofxFloatSlider guiGreenMax;
    ofxFloatSlider guiBlueMin;
    ofxFloatSlider guiBlueMax;
};
