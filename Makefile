#some build variables
BDIR = build
SRC = src
INC = include

# redefine the nn_base and nn_io header files
BASE_SRC = $(SRC)/nn_base
BASE_HPP =Neuron.hpp function.hpp
BASE_HPP_ = $(pathsubst %,$(INC)/%,$(BASE_HPP))
BASE_CPP_ = $(wildcard $(BASE_SRC)/*.cpp)

IO = $(SRC)/nn_io
IO_HPP = NN_io.hpp 
IO_HPP_ = $(pathsubst %,$(INC)/%,$(IO_HPP))
IO_CPP_ = $(wildcard $(IO)/*.cpp)
 
CC = g++

#compilation and linker  flags (add debug flag)
CFLAGS = -c -Wall -g -I$(INC)
LFLAGS = 
EXEC = nn_run

all: $(EXEC)

$(EXEC): base io main.o
	$(CC) $(BDIR)/*.o $(LFLAGS) -o $@

#compile nn_base files
base: $(BASE_CPP_) $(BASE_HPP_)
	$(CC) -c $(BASE_CPP_) $(CFLAGS)
	mv *.o $(BDIR)

#compile nn_io files 
io: $(IO_CPP_) $(IO_HPP_)
	$(CC) -c $(IO_CPP_) $(CFLAGS)
	mv *.o $(BDIR)

#build the main file
main.o: $(BASE_HPP_) $(IO_HPP_) 
	$(CC) -c $(SRC)/main.cpp $(CFLAGS) 
	mv *.o $(BDIR)	 
clean:
	rm $(BDIR)/*.o
	rm $(EXEC) 
