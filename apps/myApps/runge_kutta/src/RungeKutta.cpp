//
//  RungeKutta.cpp
//  runge_kutta
//
//  Created by NAMBU AKIFUMI on 2015/12/15.
//
//

#include "RungeKutta.hpp"

float RungeKutta::getValue(int step, int index){
    return result[step*num + index];
}

RungeKutta::RungeKutta(float (*f[])(float t, float *x), float t0, float tn, float *x, int div, int _num){
    num = _num;
    result = new float[div*num];
    float h = (tn - t0)/div;
    for(int i=0; i<div; ++i){
        calculateNextStep(f, t0, x, t0+h, num);
        for(int j=0; j<num; ++j){
            result[i*num+j] = x[j];
            t0 += h;
        }
    }
}


void RungeKutta::calculateNextStep(float (*f[])(float t, float *x), float t0, float *x, float tn, int num){
    float k1[num], k2[num], k3[num], k4[num], tmp[num];
    
    float h = (tn - t0);
    
    float t = t0;
    
    for(int j=0; j<num; j++){
        k1[j] = (*f[j])(t, x);
        
        tmp[j] = x[j] + h*k1[j]/2;
        k2[j] = (*f[j])(t+h/2, tmp);
        
        tmp[j] = x[j] + h*k2[j]/2;
        k3[j] = (*f[j])(t+h/2, tmp);
        
        tmp[j] = x[j] + h*k3[j];
        k4[j] = (*f[j])(t+h, tmp);
        
        x[j] += (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])*h/6;
    }
}

