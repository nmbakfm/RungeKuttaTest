//
//  MidiController.h
//  asobu
//
//  Created by NAMBU AKIFUMI on 2015/10/31.
//
//

#ifndef asobu_MidiController_h
#define asobu_MidiController_h

#include "ofMain.h"
#include "ofApp.h"
#include "ofxMidi.h"

class MidiController: public ofxMidiListener {
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    
    MidiController(){};
    
public:
    
    static MidiController *sharedManager(){
        static MidiController *midiController = new MidiController();
        midiController->init();
        return midiController;
    }
    
    void init(){
        midiIn.listPorts();
        midiIn.openPort(0);
        midiIn.ignoreTypes(false, false, false);
        midiIn.addListener(this);
        midiIn.setVerbose(true);
    }
    
    ofxMidiMessage getMidiMessage(){
        return midiMessage;
    };
    
    void newMidiMessage(ofxMidiMessage& msg) {
        // make a copy of the latest message
        midiMessage = msg;
    }
};

#endif
