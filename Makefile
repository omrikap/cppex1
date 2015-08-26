CPPC = g++
FLAGS = -std=c++11 -Wextra -Wall
.PHONY: tar all clean IntMatrix

#make IntMatrix
IntMatrix: IntMatrix.cpp IntMatrix.h
	$(CPPC) $(FLAGS) -c IntMatrix.cpp -o IntMatrix.o

#make IntMatrixDriver
IntMatrixDriver: IntMatrix.o IntMatrixDriver.cpp
	$(CPPC) $(FLAGS) -c IntMatrixDriver.cpp  -o IntMatrixDriver.o
	$(CPPC) $(FLAGS) IntMatrix.o IntMatrixDriver.o  -o IntMatrixDriver

#make tar
tar: IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp Makefile
	tar cvf ex1.tar IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp Makefile

#make all

#make clean
#no parameters == make IntMatrixDriver