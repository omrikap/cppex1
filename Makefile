CPPC = g++
FLAGS = -std=c++11 -Wextra -Wall
.PHONY: tar all clean IntMatrix

#make IntMatrix
IntMatrix: IntMatrix.cpp IntMatrix.h
	$(CPPC) $(FLAGS) -c IntMatrix.cpp -o IntMatrix.o

#make IntMatrixDriver
IntMatrixDriver: IntMatrix.o
	$(CPPC) $(FLAGS) IntMatrix.cpp -o IntMatrixDriver

#make tar

#make all
#make clean
#no parameters == make IntMatrixDriver