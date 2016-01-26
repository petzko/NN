#ifndef _NN_IO_HPP
#define _NN_IO_HPP

#include "Neuron.hpp"

	typedef Neuron** arrayofNeurons; 
	void readNetwork_b(const char*, arrayofNeurons&, float*&, int&, int&);
	void readNetwork_t(const char*,arrayofNeurons&, float*&, int&,int&);

	void writeNetwork_t(const char*, arrayofNeurons, float*, int , int); 
	void writeNetwork_b(const char*,arrayofNeurons,float*,int,int); 

#endif




