#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    x[0] = 30.0;
    x[1] = 0.0;
    
    f[0] = ofApp::_f1;
    f[1] = ofApp::_f2;
    
    h=(tn - t)/LOOP;
}

double ofApp::_f1(double t, double * x){
    return x[1];
}

double ofApp::_f2(double t, double * x){
    return -x[0];
}

//--------------------------------------------------------------
void ofApp::update(){
    x[0] = 30.0;
    x[1] = 0.0;

}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBeginShape();
    for(int i=0; i<LOOP; ++i){
        ofxRungeKutta::getValues(f, t, x, t+h, 1, 2);
        ofDrawCircle(ofGetWidth()*i/LOOP, ofGetHeight()/2 + x[0], 1);
        t+=h;
    }
//    ofEndShape();
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
