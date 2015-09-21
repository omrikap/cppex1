CPPC = g++ -std=c++11
FLAGS = -Wall -Wextra

.PHONY: tar all clean IntMatrix valgrind

# create the program to test the IntMatrix class.
IntMatrixMainDriver: IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp
	$(CPPC) $(FLAGS) IntMatrix.cpp IntMatrixDriver.cpp -o IntMatrixMainDriver

#create an object file out of IntMatrix.cpp
IntMatrix: IntMatrix.cpp IntMatrix.h
	$(CPPC) $(FLAGS) -c IntMatrix.cpp -o IntMatrix.o

# create the tar file for he submission.
tar: IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp Makefile
	tar cvf ex1.tar IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp Makefile

# create all the options this Makefile support, except from "clean"
all: IntMatrix IntMatrixMainDriver tar

# clean all files created by make.
clean:
	rm -f *.o ex1.tar IntMatrixMainDriver

# debug with valgrind
valgrind: IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp
	$(CPPC) $(FLAGS) -g IntMatrix.cpp IntMatrixDriver.cpp -o dbgIntMatrixMainDriver