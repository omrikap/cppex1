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
	IntMatrix(); // todo

	/**
	 * @brief A copy constructor.
	 * @param other The matrix to copy.
	 */
	IntMatrix(IntMatrix other);

	/**
	 * @brief A destructor.
	 */
	~IntMatrix();

//	todo copy constructor
//	todo custom constructors
//	todo operator

private:
	/**
	 *
	 */
	int _rows;

	/**
	 *
	 */
	int _cols;

	/**
	 *
	 */
	int *_matrix;
};

#endif //EX1_INTMATRIX_H
