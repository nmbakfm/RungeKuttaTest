#pragma once

#include "ofMain.h"
#include "RungeKutta.hpp"

#define LOOP 10000.f

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
    
    
    
    static float _f1(float t, float * x);
    static float _f2(float t, float * x);
    
    static float _g1(float t, float * x);
    static float _g2(float t, float * x);
    
    float (*f[2])(float, float*);
    float (*g[2])(float, float*);
    
    RungeKutta rk;
    RungeKutta rk2;
		
};
