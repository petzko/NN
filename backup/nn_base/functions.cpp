#include "functions.hpp"


pfunction propagationFunctions[NUM_PFTS] = {&nn_wsum};
afunction activationFunctions[NUM_AFTS] = {&nn_heaviside,&nn_tanh,&nn_fermi};



float nn_wsum(float* inputs , float* weights, int N)
{       float sum = 0.0f;
	for (int i = 0; i<N; i++)
		sum+=inputs[i]*weights[i];
	return sum;
}

float nn_tanh(float net,float astate, float thold)
{
	return -1;
}

float nn_fermi(float net, float astate, float thold)
{
	return -1;
}

float nn_heaviside(float net, float astate, float thold)
{
	return -1;
}

