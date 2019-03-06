#pragma once

#include "ofMain.h"

class ofParticle : public ofBaseApp{
    
public:
    void setup(float x, float y);
    void update();
    void draw();
    
    float zoff;
    float tubeZoff;
    bool hide;
    
    float guiTotal;
    float guiMulti;
    float guiRadiusMin;
    float guiRadiusMax;
    float guiNoiseMax;
    float guiSpeedTime;
    float guiDistance;
    float guiStroke;
    float guiSpeedTimeMin;
    float guiSpeedTimeMax;
    float guiDepth;
    float guiCurveY;
    float guiCurveYMin;
    float guiCurveYMax;
    float guiCurveNoise;
    float guiCurveSpeedTime;
    
    float time;
    float posX;
    float posY;
    float ra;
};
