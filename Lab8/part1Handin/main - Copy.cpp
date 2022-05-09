#include "SimpleVector.h"
using namespace std;
int main()
{
	const int SIZE = 10; // Number of elements
	int count; // Loop counter
	try {
		// Create a SimpleVector of ints.
		SimpleVector<int> intTable(SIZE);
		// Create a SimpleVector of doubles.
		SimpleVector<double> doubleTable(SIZE);

		// Store values in the two SimpleVectors.
		for (count = 0; count < SIZE; count++)
		{
			intTable[count] = SIZE - count;
			doubleTable[count] = SIZE - (count * 1.1);
		}
		// Display the values in the SimpleVectors.
		cout << "These values are in intTable:\n";
		for (count = 0; count < intTable.size(); count++)
			cout << intTable[count] << " ";
		cout << endl;
		cout << "These values are in doubleTable:\n";
		for (count = 0; count < doubleTable.size(); count++)
			cout << doubleTable[count] << " ";
		cout << endl;


	}
	catch (SimpleVector<int>::MemoryAllocationException e)
	{
		cout << e.getErrorMessage();
	}


	return 0;
}
