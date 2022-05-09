/*

#include "cmpt225sort.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
using std::string;
using std::cout;
using std::endl;

// PARAM: infile = name of the file to be opened
//        n = the size of the result array
// PRE: the file contains values separated by white space
// POST: returns an array containing the contents of infile
template <class T>
T* readFile(string infile, int& n)
{
	T* result;
	T next;
	n = 0;

	std::ifstream ist(infile.c_str()); 
	// open file
	// Check if file opened correctly
	if (ist.fail()) {
		throw std::runtime_error(infile + " not found");
	}

	// Find file size
	while (ist >> next) {
		n++;
	}

	// Read file into array
	ist.close();
	ist.open(infile.c_str());
	result = new T[n];
	for (int i = 0; i < n; ++i) {
		ist >> result[i];
	}

	ist.close();
	return result;
}




void basicTest()
{
	int n = 0;
	int* arr1 = readFile<int>("a3test1.txt", n);
	int* arr12 = readFile<int>("a3test1.txt", n);
	int* arr13 = readFile<int>("a3test1.txt", n);
	cout << "insertion sort comparisons = " << insertionsort<int>(arr1, n) << endl;
	cout << "quicksort comparisons = " << quicksort<int>(arr12, n) << endl;
	cout << "mergesort comparisons = " << mergesort<int>(arr13, n) << endl;
	float* arr2 = readFile<float>("a3test2.txt", n);
	float* arr22 = readFile<float>("a3test2.txt", n);
	float* arr23 = readFile<float>("a3test2.txt", n);
	cout << "quicksort comparisons = " << quicksort<float>(arr2, n) << endl;
	cout << "insertion sort comparisons = " << insertionsort<float>(arr22, n) << endl;
	cout << "mergesort comparisons = " << mergesort<float>(arr23, n) << endl;
	string* arr3 = readFile<string>("a3test3.txt", n);
	string* arr32 = readFile<string>("a3test3.txt", n);
	string* arr33 = readFile<string>("a3test3.txt", n);
	string* arr34 = readFile<string>("a3test3.txt", n);
	cout << "mergesort comparisons = " << mergesort<string>(arr3, n) << endl;
	cout << "shell sort comparisons = " << shellsort<string>(arr32, n) << endl;
	cout << "insertion sort comparisons = " << insertionsort<string>(arr33, n) << endl;
	cout << "quicksort comparisons = " << quicksort<string>(arr34, n) << endl;
}

int main() {

	basicTest();
	return 0;
}

//*/