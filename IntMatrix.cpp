#include "IntMatrix.h"
#include <iostream>

using namespace std;

IntMatrix::IntMatrix() // toTest
{
	_rows = 0;
	_cols = 0;
	_matrix = nullptr;
	cout << "++ a new matrix" << endl;
}

IntMatrix::IntMatrix(IntMatrix &other) // toTest
{
	if (other._matrix != nullptr)
	{
		if ((_rows * _cols) != (other._rows * other._cols))
		{
			delete[] _matrix;
			_matrix = nullptr;
		}
	}
	else
	{
		_matrix = new int[other._rows * other._cols];
	}
	_rows = other._rows;
	_cols = other._cols;
	for (int i = 0; i < (_rows * _cols); ++i)
	{
		_matrix[i] = other._matrix[i];
	}
}

IntMatrix::IntMatrix(const int _rows, const int _cols) // toTest
{
	this->_rows = _rows;
	this->_cols = _cols;
	this->_matrix = new int[_rows * _cols];
	cout << "++ a new matrix of " << this->_rows << " on " << this->_cols << endl; // todo remove
}

IntMatrix::~IntMatrix() //toTest
{
	if (_matrix != nullptr)
	{
		delete[] _matrix;
		cout << "-- array destroied" << endl; // todo remove
	}
	cout << "-- matrix destroied" << endl; // todo remove
}

IntMatrix& IntMatrix::operator=(const IntMatrix &other) // toTest
{
	if (this == &other)
	{
		return *this;
	}
	if (_matrix != nullptr)
	{
		if ((other._rows * other._cols) != (this->_rows * this->_cols))
		{
			delete[] _matrix;
			_matrix = new int[other._rows * other._rows];
		}
	}
	this->_rows = other._rows;
	this->_cols = other._cols;
	int matrixArrayLength = other._rows * other._rows;
	for (int i = 0; i < matrixArrayLength; ++i)
	{
		_matrix[i] = other._matrix[i];
	}
	return *this;
}



// ---------------------------------- unit-testing --------------------------------------

#ifndef NDEBUG

int main()
{
	IntMatrix *M = new IntMatrix();
	IntMatrix *S = new IntMatrix(2, 2);

	delete M;
	delete S;

	return 0;
}

#endif // NDEBUG