//
//  FandamentalShapeRect.h
//  asobu
//
//  Created by NAMBU AKIFUMI on 2015/10/24.
//
//

#ifndef __asobu__FandamentalShapeRect__
#define __asobu__FandamentalShapeRect__

#include "ofMain.h" 

class FandamentalShapeRect {
    int hue;
    float alpha;
public:
    FandamentalShapeRect(){
        hue = ofRandom(-50, 50) + 100;
        alpha = 10.;
    }
    
    void update(){
        hue += 5;
        alpha -=1;
        while(hue > 255) hue -= 255;
    };
    
    void draw(){
        ofColor color;
        color.setHsb(hue, 255, 255);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(color, alpha);
        ofRect(0, 0, 5, 5);
        ofSetRectMode(OF_RECTMODE_CORNER);
    };
    
    bool isDead(){
        return alpha <= 0;
    }
};

#endif /* defined(__asobu__FandamentalShapeRect__) */
