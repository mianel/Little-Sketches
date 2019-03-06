#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxTriangleMesh.h"

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
    
    ofxPanel gui;
    ofxPanel guiMain;
    
    ofxGuiGroup colorGroup;
    ofxGuiGroup childenGroup;
    ofxGuiGroup mainGroup;
    ofxGuiGroup circleGroup;
    ofxGuiGroup colorChildGroup;

    ofxFloatSlider guiTotal;
    ofxFloatSlider guiTotalSmall;
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
    ofxFloatSlider guiTransX;
    ofxFloatSlider guiTransY;
    ofxFloatSlider guiSpeedColor;
    ofxFloatSlider guiCurvesColor;
    ofxFloatSlider guiCurvesRedMin;
    ofxFloatSlider guiCurvesRedMax;
    ofxFloatSlider guiCurvesGreenMin;
    ofxFloatSlider guiCurvesGreenMax;
    ofxFloatSlider guiCurvesBlueMin;
    ofxFloatSlider guiCurvesBlueMax;
    ofxFloatSlider guiColorBackground;
    ofxFloatSlider guiColorDiference;
    ofxFloatSlider guiPosExtra;
    ofxFloatSlider guiTotalAngleCircle;
    ofxFloatSlider guiColorAlphaChild;

    ofxFloatSlider guiCurvesChildRedMin;
    ofxFloatSlider guiCurvesChildRedMax;
    ofxFloatSlider guiCurvesChildGreenMin;
    ofxFloatSlider guiCurvesChildGreenMax;
    ofxFloatSlider guiCurvesChildBlueMin;
    ofxFloatSlider guiCurvesChildBlueMax;
    
    ofxFloatSlider guiCurvesRandomMin;
    ofxFloatSlider guiCurvesRandomMax;
    ofxFloatSlider guiRadiusChildrenMin;
    ofxFloatSlider guiRadiusChildrenMax;
    ofxFloatSlider guiMainJump;
    ofxFloatSlider guiMainSpeed;
    ofxFloatSlider guiMainMov;
};
