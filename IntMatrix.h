#ifndef EX1_INTMATRIX_H
	#define EX1_INTMATRIX_H

/**
 * A class that represent a matrix of integers.
 */
class IntMatrix
{
public:
	/**
	 * @brief The default constructor.
	 */
	IntMatrix();

	/**
	 * @brief A copy constructor.
	 * @param other The matrix to copy.
	 */
	IntMatrix(IntMatrix& other);

	/**
	 * @brief A destructor.
	 */
	~IntMatrix();

	/**
	 * @brief IntMatrix constructor.
	 * @param rows The number of rows in the matrix.
	 * @param cols The number of columns in the matrix.
	 */
	IntMatrix(const int rows, const int cols);

	/**
	 * @brief The '=' operator.
	 * @param other The matrix to use on the right side of the '='.
	 */
	IntMatrix& operator=(IntMatrix& other);

private:
	int _rows; /* the number of rows of the matrix. */
	int _cols; /* the number of columns of the matrix. */
	int *_matrix; /* A pointer to the int array of the matrix. */
};

#endif //EX1_INTMATRIX_H
