CPPC = g++ -std=c++11
FLAGS = -Wall -Wextra

.PHONY: tar all clean IntMatrix

# when calling make with no arguments
main: IntMakeMainDriver

all: tar IntMatrixDriver

IntMatrixMainDriver: IntMatrix IntMatrixDriver.cpp
	$(CPPC) $(FLAGS) IntMatrix.o IntMatrixDriver.cpp -o IntMatrixMainDriver

IntMatrix: IntMatrix.cpp IntMatrix.h
	$(CPPC) $(FLAGS) -c IntMatrix.cpp -o IntMatrix.o

tar: IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp Makefile
	tar cvf ex1.tar IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp Makefile

#make clean
clean:
	rm -f *.o ex1.tar IntMatrixDriver