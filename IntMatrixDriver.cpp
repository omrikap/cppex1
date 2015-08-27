#include <iostream>
#include <stdlib.h>
#include "IntMatrix.h"

using namespace std;

/**
 *
 */
enum userChoice
{
	ADD = 1,
	SUB,
	MUL,
	TRANS,
	TRACE
};

/**
 *
 */
void printResult(const IntMatrix &result)
{
	cout << "==========\nResulted matrix:\n" << result << endl;
}

/**
 *
 */
void gotMatrix(IntMatrix &matrix)
{
	cout << "--------\ngot matrix:\n" << matrix << endl;
}

/**
 *
 */
void printDimensionsError(string op)
{
	cout << "ERROR: " << op << " faild - different dimensions." << endl;
}

/**
 *
 */
void binaryOperatorPrintMatrices(const IntMatrix &first, const IntMatrix &second)
{
	cout << "--------\nGot first matrix:\n" << first << endl;
	cout << "--------\nGot second matrix:\n" << second << endl;
}

/**
 * @brief Get a matrix data from the user.
 * @return A new IntMatrix object.
 */
IntMatrix getMatrix()
{
	int rows, cols;
	cout << "number of rows:";
	cin >> rows;
	cout << "number of columns:";
	cin >> cols;
	cout << "Now insert the values of the matrix, row by row.\n"
					"After each cell add the char ',' (including after the last cell of a row).\n"
					"Each row should be in a separate line." << endl;
	int index = 0;
	int *matrixArray = new int[rows * cols];
	string rowInput;
	const string DELIMITER = ",";
	size_t delimiterPos = 0;
	for (int j = 0; j < rows; ++j)
	{
		cin >> rowInput;
		string currentInt;
		while ((delimiterPos = rowInput.find(DELIMITER)) != string::npos)
		{
			currentInt = rowInput.substr(0, delimiterPos);
			matrixArray[index] = atoi(&currentInt[0]); // atoi 'cause Cygwin doesn't support stoi
			rowInput.erase(0, delimiterPos + DELIMITER.length());
			index++;
		}
	}
	return IntMatrix(rows, cols, matrixArray);
}

/**
 * @brief Print the main menu of the driver.
 */
int mainMenu()
{
	cout << "Choose operation:\n1. add\n2. sub\n3. mul\n4. trans\n5. trace" << endl;
	int choice = 0;
	cin >> choice;
	while ((choice > 5) || (choice < 1))
	{
		cin >> choice;
	}
	return choice;
}

/**
 * @brief called when the user choose a binary operation from the main menu.
 */
void binaryFunction(string op, int uc)
{
	cout << "Operation " << op << " requires 2 operand matrices." << endl;
	cout << "Insert first matrix:" << endl;
	IntMatrix left = getMatrix();
	cout << "Insert second matrix:" << endl;
	IntMatrix right = getMatrix();
	IntMatrix result = IntMatrix();
	binaryOperatorPrintMatrices(left, right);
	switch (uc)
	{
		case ADD:
			if (left.getRows() != right.getRows() || left.getCols() != right.getCols())
			{
				printDimensionsError(op);
				return;
			}
			else
			{
				result = left + right;
			}
			break;
		case SUB:
			if (left.getRows() != right.getRows() || left.getCols() != right.getCols())
			{
				printDimensionsError(op);
				return;
			}
			else
			{
				result = left - right;
			}
			break;
		case MUL:
			if (left.getCols() != right.getRows())
			{
				printDimensionsError(op);
				return;
			}
			else
			{
				result = left * right;
			}
			break;
		default:
			break;
	}
	printResult(result);
}

/**
 *
 */
void unaryFunction(string op, int uc)
{
	cout << "Operation " << op << " requires 1 operand matrix." << endl;
	IntMatrix matrix = getMatrix();
	gotMatrix(matrix);
	IntMatrix result = IntMatrix();
	switch (uc)
	{
		case TRANS:
			result = matrix.trans();
			printResult(result);
			break;

		case TRACE:
			if (matrix.getCols() != matrix.getRows())
			{
				cout << "ERROR: trace faild - The matrix isn't square." << endl;
				return;
			}
			else
			{
				cout << "The matrix is square and its trace is " << matrix.trace() << endl;
			}
			break;
	}
}

/**
 * @brief the main function of the IntMatrix class driver.
 * @return int 0 if all went well.
 */
int main()
{
	int choice = mainMenu();
	switch (choice)
	{
		case ADD:
			binaryFunction("add", ADD);
			break;
		case SUB:
			binaryFunction("sub", SUB);
			break;
		case MUL:
			binaryFunction("mul", MUL);
			break;
		case TRANS:
			unaryFunction("trans", TRANS);
			break;
		case TRACE:
			unaryFunction("trace", TRACE);
			break;
	}
	return 0;
}
