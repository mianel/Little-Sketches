#pragma once

#include "ofMain.h"
#include "ofBoids.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    vector <ofBoids> m_boids;
    vector <ofPolyline> line;
    
    ofEasyCam cam;
    ofFbo fbo;
    
    // ------ Gui ------- //
    ofxPanel gui;
    ofxFloatSlider guiAlign;
    ofxFloatSlider guiCohesion;
    ofxFloatSlider guiSeparation;
    ofxFloatSlider guiMaxForce;
    ofxFloatSlider guiMaxSpeed;
    ofxFloatSlider guiRadiusA;
    ofxFloatSlider guiRadiusC;
    ofxFloatSlider guiRadiusS;
    ofxFloatSlider guiSize;
    
    
};
