//
//  ofxRungeKutta.hpp
//  runge_kutta
//
//  Created by NAMBU AKIFUMI on 2015/12/14.
//
//

#ifndef ofxRungeKutta_hpp
#define ofxRungeKutta_hpp

#include <stdio.h>

class ofxRungeKutta {
    
public:
    static float * getValues(double (*f[])(double t, double *x), double t0, double *x, double tn, int div, int num)
    {
        double h, t;
        double k1[num], k2[num], k3[num], k4[num], temp[num];
        
        h = (tn - t0);
        if(div) h /= div;
        
        t = t0;
        
        for(int i=0; i<div; i++){
            for(int j=0; j<num; j++){
                k1[j] = (*f[j])(t, x);
                temp[j] = x[j] + h*k1[j]/2;
            }
            for(int j=0; j<num; j++){
                k2[j] = (*f[j])(t+h/2, temp);
            }
            for(int j=0; j<num; j++){
                temp[j] = x[j] + h*k2[j]/2;
            }
            for(int j=0; j<num; j++){
                k3[j] = (*f[j])(t+h/2, temp);
            }
            for(int j=0; j<num; j++){
                temp[j] = x[j] + h*k3[j];
            }
            for(int j=0; j<num; j++){
                k4[j] = (*f[j])(t+h, temp);
                x[j] += (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])*h/6;
            }
            t += h;
        }
    }
};

#endif /* ofxRungeKutta_hpp */
