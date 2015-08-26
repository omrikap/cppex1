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

IntMatrix::IntMatrix(const int rows, const int cols)
{
	_rows = rows;
	_cols = cols;
	_matrix = new int[_rows * _cols];
	int arraySize = _rows * _cols;
	for (int i = 0; i < arraySize; ++i)
	{
		_matrix[i] = 0;
	}
}

IntMatrix::IntMatrix(const IntMatrix &other)
{
	_rows = other._rows;
	_cols = other._cols;
	_matrix = new int[_rows * _cols];
	for (int i = 0; i < (_rows * _cols); ++i)
	{
		_matrix[i] = other._matrix[i];
	}
}

IntMatrix::IntMatrix(const int rows, const int cols, int* matrixArray)
{
	_rows = rows;
	_cols = cols;
	_matrix = matrixArray;
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

IntMatrix& IntMatrix::operator=(const IntMatrix &other)
{
	if (this != &other) // in case of self assignment, just return the same object.
	{
		if (_matrix != nullptr)
		{
			if ((other._rows * other._cols) != (this->_rows * this->_cols))
			{
				delete[] _matrix;
				_matrix = new int[other._rows * other._rows];
			}
		}
		else
		{
			_matrix = new int[other._rows * other._rows];
		}
		this->_rows = other._rows;
		this->_cols = other._cols;
		int matrixArrayLength = other._rows * other._rows;
		for (int i = 0; i < matrixArrayLength; ++i)
		{
			_matrix[i] = other._matrix[i];
		}
	}
	return *this;
}

IntMatrix &IntMatrix::operator+=(const IntMatrix &other)
{
	int matrixArrayLength = _rows * _cols;
	for (int i = 0; i < matrixArrayLength; ++i)
	{
		_matrix[i] += other._matrix[i];
	}

	return *this;
}

IntMatrix &IntMatrix::operator-=(const IntMatrix &other)
{
	int matrixArrayLength = _rows * _cols;
	for (int i = 0; i < matrixArrayLength; ++i)
	{
		_matrix[i] -= other._matrix[i];
	}

	return *this;
}

IntMatrix &IntMatrix::operator*=(const IntMatrix &other)
{
	int *newMatrix = new int[_rows * other._cols];
	for (int row = 0; row < _rows; ++row)
	{
		for (int otherCol = 0; otherCol < other._cols; ++otherCol)
		{
			int dotProduct = 0;
			for (int col = 0; col < _cols; ++col)
			{
				dotProduct += _matrix[(row * _cols) + col] * other._matrix[(col * other._cols) +
						otherCol];
			}
			newMatrix[row * _rows + otherCol] = dotProduct;
		}
	}
	delete[] _matrix;
	_matrix = newMatrix;
	_cols = other._cols;
	return *this;
}

const IntMatrix IntMatrix::operator+(const IntMatrix &other)
{
	IntMatrix result = *this;
	result += other;
	return result;
}

const IntMatrix IntMatrix::operator-(const IntMatrix &other)
{
	IntMatrix result = *this;
	result -= other;
	return result;
}

const IntMatrix IntMatrix::operator*(const IntMatrix &other)
{
	IntMatrix result = *this;
	result -= other;
	return result;
}

IntMatrix IntMatrix::trans()
{
	int *transposed = new int[_rows * _cols];
	for (int row = 0; row < _rows; ++row)
	{
		for (int col = 0; col < _cols; ++col)
		{
			transposed[(col * _cols) + row] = _matrix[(row * _cols) + col];
		}
	}
	IntMatrix *result = new IntMatrix(_rows, _cols, transposed);
	return *result;
}

int IntMatrix::trace()
{
	int theTrace = 0;
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _rows; ++i)
		{
			theTrace += _matrix[i*_rows + i];
		}
	}
	return theTrace;
}

// ---------------------------------- unit-testing --------------------------------------

#ifndef NDEBUG

void printMatrix(IntMatrix &matrix)
{
	for (int i = 0; i < matrix.get_rows(); ++i)
	{
		for (int j = 0; j < matrix.get_cols(); ++j)
		{
			cout << matrix.get_matrix()[i*matrix.get_cols() + j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int *firstArray = new int[4];
	firstArray[0] = 2;
	firstArray[1] = 4;
	firstArray[2] = 1;
	firstArray[3] = 3;

	int *secArray = new int[4];
	secArray[0] = 8;
	secArray[1] = 3;
	secArray[2] = 9;
	secArray[3] = 7;

	IntMatrix *S1 = new IntMatrix(2, 2, firstArray);

	IntMatrix *S2 = new IntMatrix(2, 2, secArray);

	IntMatrix& Sr = *S1;
	cout << "----------------------------" << endl;
	printMatrix(*S1);
	cout << "----------------------------" << endl;
	printMatrix(*S2);
	cout << "----------------------------" << endl;
	printMatrix(Sr);
	*S1 *= *S2;
	cout << "----------------------------" << endl;
	printMatrix(*S1);
	cout << "the trace of S1: " << S1->trace() << endl;
	cout << "----------------------------" << endl;
//	IntMatrix *transposed = new IntMatrix();
//	cout << "----------------------------" << endl;
	IntMatrix transposed = Sr.trans();
	cout << "----------------------------" << endl;
	printMatrix(transposed);
	cout << "----------------------------" << endl;
	delete S1;
	delete S2;
	delete &transposed;

	return 0;
}

#endif // NDEBUG