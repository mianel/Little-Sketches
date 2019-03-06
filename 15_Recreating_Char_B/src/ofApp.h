#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class myPointsVec{
public:
    vector <ofPoint> myPos;
    vector<ofTTFCharacter> characters;
};

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
		
    
    ofTrueTypeFont font;
    
    string m_wordA, m_wordB;
    bool m_hide;
    bool m_morphed;
    bool m_stop;
    float m_wait;
    float m_counter;
    
    float timerMap;
    float timer;
    float m_jumpA;
    float m_jumpB;
    float m_moveZ;
    int m_next;
    vector <vector <vector <ofPoint> > > getStringAsPoints3DMatrix(ofTrueTypeFont & font, string s, int numOfSamples);
    vector <ofPolyline> line;
    
    ofEasyCam cam;
    
    ofxPanel gui;
    ofxFloatSlider guiDots;
    ofxFloatSlider guiSpeed;
    ofxFloatSlider guiSize;
    ofxFloatSlider guiMorph;
    ofxFloatSlider guiJumpZ;
    ofxFloatSlider guiLongLine;
    ofxFloatSlider guiCanvasX;
    ofxFloatSlider guiCanvasY;
    ofxFloatSlider guiWait;
    ofxFloatSlider guiStroke;
    
};


