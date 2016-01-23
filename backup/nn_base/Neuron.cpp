#include "Neuron.hpp"

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

}

float* Neuron::toFloatArray(){
	float* res = new float[7];
	res[0] = (float)idx; res[1] = (float)ntype; res[2] = (float)pftype;
	res[3] = (float)aftype; res[4] = (float)oftype; res[5] = astate;  res[6] = thold;
	return res;  

} 

void Neuron::print(){
	std::cout<<"this is me, dad!:\n ";
	float* me = this->toFloatArray(); 

	for(int i=0;i<NPROPS;i++)
		std::cout << me[i] << " "; 

	std::cout<< "\n";
	delete[] me;

}
