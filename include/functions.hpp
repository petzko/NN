#ifndef _FUNCTIONS_HPP
#define _FUNCTIONS_HPP

#define NUM_PFTS 1
#define NUM_AFTS 3 

#include <math.h>

float nn_wsum(float* inputs , float* weights, int N);

float nn_tanh(float net,float astate, float thold);
float nn_fermi(float net, float astate, float thold);
float nn_heaviside(float net, float astate, float thold);

typedef float (*pfunction)(float*, float*,int);
typedef float (*afunction)(float, float,float);


extern pfunction propagationFunctions[NUM_PFTS]; 
extern afunction  activationFunctions[NUM_AFTS]; 
#endif



