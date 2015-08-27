#include <iostream>
#include <string>
#include <stdlib.h>
#include "IntMatrix.h"
#ifdef NDEBUG

using namespace std;

void printResult(const IntMatrix &result)
{
	cout << "==========\nResulted matrix:" << result << endl;
}

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
	cout << "number of rows:" << endl;
	cin >> rows;
	cout << "number of columns:" << endl;
	cin >> cols;
	cout << "Now insert the values of the matrix, row by row.\n"
					"After each cell add the char ',' (including after the last cell of a row).\n"
					"Each row should be in a separate line." << endl;
	int index = 0;
	int *matrixArray = new int[rows * cols];
	string rowInput;
	for (int j = 0; j < rows; ++j)
	{
		cin >> rowInput;
		for (int i = 0; i < (cols * 2); ++i)
		{
			if (rowInput[i] != ',')
			{
				matrixArray[index] = atoi(&rowInput[i]); // atoi 'cause Cygwin doesn't support stoi

				index++;
			}
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
void binaryFunction()
{
	cout << "Operation add requires 2 operand matrices.\nInsert first matrix:" << endl;
	IntMatrix left = getMatrix();
	IntMatrix right = getMatrix();
	IntMatrix result = left + right;
	cout << left << endl;
	binaryOperatorPrintMatrices(left, right);
	printResult(result);
}

/**
 *
 */
void unaryFunction()
{
	cout << "Operation add requires 2 operand matrices.\nInsert first matrix:" << endl;
	IntMatrix left = getMatrix();
	IntMatrix right = getMatrix();
	IntMatrix result = left + right;
	cout << left << endl;
	binaryOperatorPrintMatrices(left, right);
	printResult(result);
}

int main()
{
	mainMenu();

	binaryFunction();
	return 0;
}

#endif // NDEBUG