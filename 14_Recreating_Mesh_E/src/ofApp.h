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
    
    ofxPanel gui;
    ofxFloatSlider guiTotal;
    ofxFloatSlider guiMulti;
    ofxFloatSlider guiRadiusMin;
    ofxFloatSlider guiRadiusMax;
    ofxFloatSlider guiNoiseMax;
    ofxFloatSlider guiSpeedTime;
    ofxFloatSlider guiDistance;
    ofxFloatSlider guiDistanceRadius;
    ofxFloatSlider guiStroke;
    ofxFloatSlider guiSpeedTimeMin;
    ofxFloatSlider guiSpeedTimeMax;
    ofxFloatSlider guiCor;
    
    ofxFloatSlider guiFreq;
    ofxFloatSlider guiAmp;
    
    ofxFloatSlider guiCurvesChildRedMin;
    ofxFloatSlider guiCurvesChildRedMax;
    ofxFloatSlider guiCurvesChildGreenMin;
    ofxFloatSlider guiCurvesChildGreenMax;
    ofxFloatSlider guiCurvesChildBlueMin;
    ofxFloatSlider guiCurvesChildBlueMax;
    
    float zoff;
    bool hide;
};
