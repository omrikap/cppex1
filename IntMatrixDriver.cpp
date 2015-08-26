#include <iostream>
#include "IntMatrix.h"
#ifdef NDEBUG

using namespace std;

IntMatrix getMatrix()
{
	int rows, cols;
	cout << "number of rows:" << endl;
	cin >> rows;
	cout << "number of columns:" << endl;
	cin >> cols;
	cout << rows << " rows, and " << cols << " cols." << endl;
	string theInts;
	cout << "enter a row:" << endl;
	cin >> theInts;
	cout << theInts << endl;
	int num;
	for (int i = 0; i < cols; ++i)
	{
		int x;
		if (cin.ignore() >> x)
		{
			cout << x << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}

//	while (cin.ignore() >> num)
//	{
//		cout << num << endl;
//	}
//	cout << theInts;
	return IntMatrix(rows, cols);
}

/**
 * @brief Print the main menu of the driver.
 */
void printMenu()
{
	cout << "Choose operation:\n1. add\n2. sub\n3. mul\n4. trans\n5. trace" << endl;
}

/**
 * @brief called when the user choose "add" in the main menu.
 */
void add()
{
	cout << "Operation add requires 2 operand matrices.\nInsert first matrix:" << endl;

}

int main()
{
	printMenu();
	getMatrix();
	return 0;
}

#endif // NDEBUG