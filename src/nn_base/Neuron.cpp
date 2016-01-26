#include "Neuron.hpp"

// nothing much to free here.
Neuron::~Neuron(){

	this->pf = NULL; 
	this->af = NULL; 
}

Neuron::Neuron(float* line)
{

	this->idx = (unsigned int) line[0];  
	this->ntype = (unsigned int) line[1];
	this->pftype = (unsigned int) line[2]; 
	this->aftype = (unsigned int)line[3];
	this->oftype = (unsigned int)line[4];

	// and two floats
	this->astate=  line[5];
	this->thold= line[6];

	this->pf = propagationFunctions[this->pftype]; 
	this->af = activationFunctions[this->aftype];
	this->net = 0.; 
}


float*  Neuron::toFloatArray(){
	float* res = new float[NPROPS];
	res[0] = (float)idx; res[1] = (float)ntype; res[2] = (float)pftype;
	res[3] = (float)aftype; res[4] = (float)oftype; res[5] = astate;  res[6] = thold;
	return res;  

} 

void Neuron::setThreshold(float thld){this->thold = thld;}

void Neuron::print(){
	std::cout<<"this is me, dad!:\n ";
	float* me = this->toFloatArray(); 
	for(int i=0;i<NPROPS;i++)
		std::cout << me[i] << " "; 

	std::cout<< "\n";
	delete[] me;
}

// calculates the input to the neuron
void Neuron::propagate(float* weights,float* inputs, int N){ this->net = this->pf(weights,inputs,N); }

// sets the activations state
void Neuron::activate(){ this->astate = af(this->net,this->astate,this->thold);}

// retrieves the activation state of the neuron, possibly after applying an output function 
float Neuron::output(){ return this->astate; }

