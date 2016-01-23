#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class A{

	int a; 
public:
	A(int in_a)
	{
		a = in_a; 
	}
	int getA(){return a;}
};


#include <stdlib.h>
typedef A** arrayofA; 

void initializeAs(arrayofA &storage){
	
	storage = (arrayofA) malloc(4*sizeof(A*));
	for(int i=0;i<4;i++)
		storage[i] = new A(i);
			

}

int main(){
	 
	std::cout<<"Hello petkzo \n";
	A* a = new A(3);

	arrayofA storage; 
	initializeAs(storage); 
	for(int i = 0;i<4;i++)
		std::cout<< storage[i]->getA() << " ";
}

