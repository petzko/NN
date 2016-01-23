#ifndef _NN_IO_HPP
#define _NN_IO_HPP

#include "Neuron.hpp"

	typedef Neuron** arrayofNeurons; 
	void readNetwork_b(char*, arrayofNeurons&, float*&, int&, int&);
	void readNetwork_t(char*,arrayofNeurons&, float*&, int&,int&);

	void writeNetwork_t(char*, arrayofNeurons, float*, int , int); 
	void writeNetwork_b(char*,arrayofNeurons,float*,int,int); 


#endif




