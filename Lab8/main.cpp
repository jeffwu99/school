#include "SimpleVector.h"
#include "SortableVector.h"
using namespace std;

//Main for part 2

int main()
{
	const int SIZE = 10; // Number of elements
	int count; // Loop counter
	try {


		// Create a SimpleVector of ints.
		SortableVector<int> intTable(SIZE);
		// Create a SimpleVector of doubles.
		SortableVector<double> doubleTable(SIZE);

		// Store values in the two SimpleVectors.
		cout << "Initializing both vectors to hold some initial values here." << endl;
		for (count = 0; count < SIZE; count++)
		{
			intTable[count] = SIZE - count;
			doubleTable[count] = SIZE - (count * 1.1);
		}

		//modifying the vectors
		cout << "Calling push_back(0) here for the int vector." << endl;
		intTable.push_back(0);
		cout << "Calling pop_back() here for the double vector." << endl;
		doubleTable.pop_back();

		// Display the values in the SimpleVectors.
		cout << "These values are in intTable:\n";
		for (count = 0; count < intTable.size(); count++)
			cout << intTable[count] << " ";
		cout << endl;
		cout << "These values are in doubleTable:\n";
		for (count = 0; count < doubleTable.size(); count++)
			cout << doubleTable[count] << " ";
		cout << endl;

		//Sorting the Vectors
		cout << "Calling Sort() here for the int vector." << endl;
		intTable.sort();
		cout << "Calling Sort() here for the double vector." << endl;
		doubleTable.sort();

		// Display the values in the SimpleVectors.
		cout << "These are the sorted values in the int vector:\n";
		for (count = 0; count < intTable.size(); count++)
			cout << intTable[count] << " ";
		cout << endl;
		cout << "These are the sorted values in the double vector:\n";
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









//Main for part 1
/*
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
*/