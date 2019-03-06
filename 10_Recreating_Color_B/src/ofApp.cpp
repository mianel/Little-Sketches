#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   /* w = 800;
    h = 800;
    
    img.allocate(w, h, OF_IMAGE_COLOR);*/
    
    gui.setup("setup");
    gui.add( guiTotal.setup( "Curves", 2.0, 0.00 , 10 ));
    gui.add( guiRedMin.setup( "Red min", 0.2, 0.00 , 1 ));
    gui.add( guiRedMax.setup( "Red max", 0.4, 0.00 , 5 ));
    gui.add( guiGreenMin.setup( "Green min", 0.4, 0.00 , 1 ));
    gui.add( guiGreenMax.setup( "Green max", 0.5, 0.00 , 5 ));
    gui.add( guiBlueMin.setup( "Blue min", 0.5, 0.00 , 1 ));
    gui.add( guiBlueMax.setup( "Blue max", 0.6, 0.00 , 5 ));

    
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofShader shader;
    shader.load("","color.frag");
    
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1f("m_curves", guiTotal);
    shader.setUniform1f("m_redInit", guiRedMin);
    shader.setUniform1f("m_redEnd", guiRedMax);
    shader.setUniform1f("m_greenInit", guiGreenMin);
    shader.setUniform1f("m_greenEnd", guiGreenMax);
    shader.setUniform1f("m_blueInit", guiBlueMin);
    shader.setUniform1f("m_blueEnd", guiBlueMax);
    
    
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shader.end();
    
    
   // img.draw(0,0);
    /*
    ofSeedRandom(0);
    float time = ofGetElapsedTimef();
    
    unsigned char * pixels = img.getPixels().getData();
    
    for(int i = 0; i < int(guiTotal); i++){
        float sinOfTime = sin(((time*10)+i)*0.13);
        float posX = ofMap(sinOfTime, -1, 1, 10, 200);
        
        int x = int(ofRandom(100, w));
        int y = int(ofRandom(200, h));
        int radius = int(ofRandom(100,200));
        
        //cout << "i: " << i << " / x: " << x << " / y: " << y << endl;
        for (int xpos = 0; xpos < w; xpos++){
            for (int ypos = 0; ypos < h; ypos++){
                float dist = ofDist(xpos, ypos, x, y);
                
                int index = ypos * w * 3 + xpos * 3;
                int red = pixels[index];
                int green = pixels[index+1];
                int blue = pixels[index+2];
                
                
                 if (dist <= radius){
                 switch(i){
                     case 0:
                             img.setColor(xpos, ypos, ofColor(ofMap(dist, 0, radius, 255, 0), green, blue));
                     break;
                     case 1:
                             img.setColor(xpos, ypos, ofColor(red, ofMap(dist, 0, radius, 255, 0), blue));
                     break;
                     case 2:
                             img.setColor(xpos, ypos, ofColor(red, green, ofMap(dist, 0, radius, 255, 0)));
                     break;
                     case 3:
                             img.setColor(xpos, ypos, ofColor(ofMap(dist, 0, radius, 255, 0), green, blue));
                     break;
                     case 4:
                     img.setColor(xpos, ypos, ofColor(red, green, ofMap(dist, 0, radius, 255, 0)));
                     break;
                     }
                 }
                 
            
                if (dist <= radius){
                    switch(i){
                        case 0:
                            ofSetColor(ofMap(dist, 0, radius, 255, 0), green, blue);
                            break;
                        case 1:
                            ofSetColor(red, ofMap(dist, 0, radius, 255, 0), blue);
                            break;
                        case 2:
                            ofSetColor(red, green, ofMap(dist, 0, radius, 255, 0));
                            break;
                        case 3:
                            ofSetColor(ofMap(dist, 0, radius, 255, 0), green, blue);
                            break;
                    }
                }
                ofDrawRectangle(xpos, ypos, 10, 10);
                
            }
        }
    }
    img.update();
    */
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
