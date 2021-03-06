#ifndef _NEURON_HPP
#define _NEURON_HPP

#include <iostream> 
#include <stdlib.h>
#include "functions.hpp"
#include <stdio.h>

// number of properties characterizing the neuron
#define NPROPS 7

class Neuron {

	private:
		unsigned int idx; unsigned int ntype; unsigned int pftype,aftype,oftype;  
		pfunction pf; afunction af;   
		float astate , thold; 
		// todo: allow for different output function
		float net; 

	public:
		~Neuron();  
		Neuron(float* line);
		float* toFloatArray();
		void print();	
	
		// calculates the input to the neuron
		void propagate(float* weights,float* inputs, int N); 

		// sets the activations state
		void activate();

		// retrieves the activation state of the neuron, possibly after applying an output function 
		float output(); 
	
		void setThreshold(float thld);



	
};


#endif
