//
//  XmlSetting.h
//  asobu
//
//  Created by NAMBU AKIFUMI on 2015/10/31.
//
//

#ifndef asobu_XmlSetting_h
#define asobu_XmlSetting_h

#include "ofMain.h"
#include "ofxXmlSettings.h"

class XmlSetting {
    ofxXmlSettings xml;
    
public:
    void load(string file_name){
        xml.load(file_name);
        
        
    }
};

#endif
