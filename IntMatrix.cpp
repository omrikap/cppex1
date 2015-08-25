#include "IntMatrix.h"
#include <iostream>

using namespace std;

IntMatrix::IntMatrix()
{
	_rows = 0;
	_cols = 0;
	_matrix = nullptr;
	cout << "++ a new matrix" << endl;
}

IntMatrix::IntMatrix(const int _rows, const int _cols)
{
	this->_rows = _rows;
	this->_cols = _cols;
	this->_matrix = new int[_rows * _cols];
	cout << "++ a new matrix of " << this->_rows << " on " << this->_cols << endl; // todo remove
}

IntMatrix::~IntMatrix()
{
	if (_matrix != nullptr)
	{
		delete[] _matrix;
		cout << "-- array destroied" << endl; // todo remove
	}
	cout << "-- matrix destroied" << endl; // todo remove
}

IntMatrix::IntMatrix(IntMatrix &other)
{
	_rows = other._rows;
	_cols = other._cols;

}


//IntMatrix &IntMatrix::operator=(const IntMatrix &other)
//{
//	if ((other._rows * other._cols) == (this->_rows * this->_cols))
//	{
//		this->_rows = other._rows;
//		this->_cols = other._cols;
//	}
//
//	return IntMatrix(other._rows, );
//}

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