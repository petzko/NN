#include "Neuron.hpp" 
#include "NN_io.hpp"
#include <iostream>

int main(){

	std::cout<<"hello world\n";
	arrayofNeurons neurons;
	char* filename = "tempfile.nn";
	float* weightsmtx;
	int N, M; 
	readNetwork_t(filename,neurons,weightsmtx,N,M);
	std::cout<<"read " << N <<" neurons with " << M << " synapses\n"; 	
	for(int n=0;n<N;n++)
		neurons[n]->print(); 
	
	for(int n = 0 ; n < N; n++)
	{	std::cout<<"\n";
		for(int nn =0 ; nn < N ; nn++)
			std::cout<<weightsmtx[nn+ N*n] << " " ;
	}
	writeNetwork_t("tempfile_copy.nn",neurons,weightsmtx,N,M);

}

