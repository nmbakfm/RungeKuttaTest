#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    for(int i=0; i<5; ++i){
        particleSystem[i].setPosition(ofGetWidth()/2+100*cos(i*TWO_PI/5), ofGetHeight()/2+100*sin(i*TWO_PI/5));
        particleSystem[i].setAttractPoint(ofGetWidth()/2, ofGetHeight()/2);
        particleSystem[i].setAttractPower(2);
        particleSystem[i].setVelocity(ofVec2f(sin(i*TWO_PI/5),cos(i*TWO_PI/5)).normalize()*20);
    }
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    midiController = MidiController::sharedManager();
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int j=0; j<5; ++j){
        for(int i=0; i<100; ++i){
            KineticShape<FandamentalShapeRect> rect = KineticShape<FandamentalShapeRect>();
            rect.setRotAxis(73, 83, 47);
            rect.setRotSpeed(4);
            rect.setRotDegree(ofRandom(360));
            
            rect.setAttractPoint(ofGetWidth()/2, ofGetHeight()/2);
            rect.setAttractPower(-1);
            rect.setVelocity(ofVec2f(ofRandomf(), ofRandomf()).normalize() * ofRandomf()*5);
            particleSystem[j].addParticle(rect);
        }
        particleSystem[j].update();
    }
    cout << "control: " << midiController->getMidiMessage().control << endl;
    cout << "value: " << midiController->getMidiMessage().value << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 20);
    for (int i=0; i<5; ++i) {
        particleSystem[i].draw();
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
