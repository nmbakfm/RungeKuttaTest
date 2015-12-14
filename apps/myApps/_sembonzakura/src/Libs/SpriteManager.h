//
//  SpriteManager.h
//  asobu
//
//  Created by NAMBU AKIFUMI on 2015/11/01.
//
//

#ifndef asobu_SpriteManager_h
#define asobu_SpriteManager_h

#include "ofMain.h"

class SpriteManager {
    vector<ofImage> images;
    int fileNum;
//    bool isRealTime;
    int currentFrame;
public:
    SpriteManager(){
        currentFrame = 0;
        fileNum = 0;
    };
    static void init(string filenamePrefix, int fileNum){
        this -> fileNum = fileNum;
        for (int i=0; i<fileNum; ++i) {
            ofImage image;
            stringstream filename;
            filename << filenamePrefix << fileNum;
            image.load(filename.str());
            images.push_back(image);
        }
    };
    
//    void enableRealTime(){
//        isRealTime = true;
//    }
//    
//    void disableRealTime(){
//        isRealTime = false;
//    }
    
    void update(){
        currentFrame = (currentFrame < fileNum - 1)?currentFrame+1:0;
    }
    
    void draw(){
        image[currentFrame].draw(0,0);
    }
};


#endif
