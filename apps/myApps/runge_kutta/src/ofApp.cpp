#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    f[0] = _f1;
    f[1] = _f2;
    
    g[0] = _g1;
    g[1] = _g2;
    
    float initialValues[] = {30.0, 0.0};
    rk = RungeKutta(f, 0, 30, initialValues, LOOP, 2);
    float initialValues2[] = {30.0, 0.0};
    rk2 = RungeKutta(g, 0, 30, initialValues2, LOOP, 2);
    
}

float ofApp::_f1(float t, float * x){
    return x[1];
}

float ofApp::_f2(float t, float * x){
    return - x[0] - 0.2 * x[1];
}

float ofApp::_g1(float t, float * x){
    return x[1];
}

float ofApp::_g2(float t, float * x){
    return -4*x[0] - 0.2 * x[1];
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
//    ofSetColor(255);
//    ofBeginShape();
//    for(int i=0; i<LOOP; ++i){
//        ofVertex(ofGetWidth()*i/LOOP, rk.getValue(i, 0) + ofGetHeight()/2);
//    }
//    ofEndShape();
    
    
    ofSetColor(255, 255, 0);
    ofBeginShape();
    for(int i=0; i<LOOP; ++i){
        ofVertex(ofGetWidth()*i/LOOP, rk2.getValue(i, 0) + ofGetHeight()/2);
    }
    ofEndShape();
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
