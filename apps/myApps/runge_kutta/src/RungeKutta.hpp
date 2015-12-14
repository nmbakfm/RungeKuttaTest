//
//  RungeKutta.hpp
//  runge_kutta
//
//  Created by NAMBU AKIFUMI on 2015/12/14.
//
//

#ifndef RungeKutta_hpp
#define RungeKutta_hpp

#include <stdio.h>

class RungeKutta {
    float * result;
    int num;
    void calculateNextStep(float (*f[])(float t, float *x), float t0, float *x, float tn, int num);
    
public:
    RungeKutta(){};
    RungeKutta(float (*f[])(float t, float *x), float t0, float tn, float *x, int div, int num);
    float getValue(int step, int index);
};

#endif /* RungeKutta_hpp */
