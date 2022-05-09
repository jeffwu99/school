#include "StringList.h"
#include <stdexcept>
#include <iostream>
#include <fstream> 


//fstream included in header file instead of here from assignment instructions
//although fstream is used here

//default constructor
//creates empty array of size 4
StringList::StringList() : maxSize(4), currentSize(0), arr(nullptr) 
{
	arr = new string[maxSize];
}
//copy constructor
//PARAM: sl is a StringList object
StringList::StringList(const StringList& sl) : maxSize(sl.maxSize), currentSize(sl.currentSize), arr(nullptr)
{
	arr = new string[maxSize];
	for (int i = 0; i < currentSize; i++) {
		arr[i] = sl.arr[i];
	}
}
//destructor
//deallocates dynamic memory
StringList::~StringList()
{
	delete[] arr;
}
//assignment operator
//overloaded to assign stringlist objects. "Deep" copies array items
//PARAM: sl is a StringList object
//POST: returns StringList reference; alters the calling object
StringList& StringList::operator=(const StringList& sl)
{
	//check for self assignment
	if (this == &sl) {
		return *this;
	}

	delete[] arr; // deallocate original array memory
	arr = new string[sl.maxSize];
	maxSize = sl.maxSize;
	currentSize = sl.currentSize;

	for (int i = 0; i < currentSize; i++) {
		arr[i] = sl.arr[i];
	}
	return *this;
	
}
//inserts a string into stringlist at given index.
//PARAM: data is string; string to be stored, 
//index is integer; is the index where item is stored in StringList's array  
void StringList::insert(string data, int index) 
{
	//double array size if already full
	if (currentSize == maxSize) {
		string* temp = new string[currentSize]; //store contents in temporary array
		for (int i = 0; i < currentSize; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		maxSize = maxSize * 2; 
		arr = new string[maxSize];
		for (int i = 0; i < currentSize; i++) {
			arr[i] = temp[i];
		}
		delete[] temp;  //deallocate temporary array
	}
	//check to see if index is within range
	if (index < 0 || index > currentSize) {
		throw std::out_of_range("Index is outside of array range");
	}
	//shift elements at and above index up 1
	for (int i = currentSize; i > index; i--) {
		arr[i] = arr[i - 1]; 
	}
	arr[index] = data; 
	currentSize++; //new item added so current size increases
}
//removes and returns string at noted index
//PARAM: index is integer; the index of the array
//POST: returns string; data that was at the noted index
string StringList::remove(int index)
{
	if (currentSize == 0) {   //if statement below can also captures this exception
		throw std::out_of_range("List is already empty"); // different error message than below
	}

	if (index < 0 || index >= currentSize) {   //this error will throw if empty stringlist
		throw std::out_of_range("Index is outside of array range");
	}

	string str = arr[index];
	//shift all items down 1
	for (int i = index; i < currentSize; i++) {
		arr[i] = arr[i + 1];
	}
	currentSize--;

	return str;
}
//puts string at index a to index b and puts string at index b to index a
//PARAM: a,b are integers; indices of array
void StringList::swap(int a, int b)
{
	if (a < 0 || b < 0 || a >= currentSize || b >= currentSize) { //this error will throw if empty stringlist
		throw std::out_of_range("One or more arguments are outside of array range");
	}

	string placeholder = arr[a];
	arr[a] = arr[b];
	arr[b] = placeholder;
}
//without removing item from array, returns the string at index
//PARAM: index is integer; index of array
//POST: returns string
string StringList::retrieve(int index) const
{
	if (index < 0 || index >=  currentSize) {
		throw std::out_of_range("Index is outside of array range");
	}
	string str = arr[index];

	return str;
}
//returns the number of items currently in StringList
//POST: returns integer
int StringList::size() const
{
	return currentSize;
}
//combines calling object and argument object into another stringlist
//with calling object's items first
//PARAM: sl is StringList; the items in sl will appear after the calling object's items
//POST: returns StringList
StringList StringList::concatenate(const StringList& sl) const
{
	StringList result(*this); //create a StringList of calling object first
	int offset = this->currentSize;

	for (int i = 0; i < sl.currentSize; i++) {
		result.insert(sl.arr[i], i + offset);
	}
	result.maxSize = result.currentSize + 4;


	return result; //cannot return by reference since this object will be destroyed after function
}

//prints every string in sl's array starting from index 0
//PARAM: sl is StringList
void print(const StringList& sl)
{
	int size = sl.size();
	for (int i = 0; i < size; i++) { //will not print anything if sl is empty
		std::cout << sl.retrieve(i) << std::endl;
	}
}
//reverses strings in array;
//PARAM: sl is StringList
void reverse(StringList& sl)
{
	int size = sl.size();
	//nothing to reverse if stringlist is empty
	if (size == 0) {
		return;
	}
	//when even number of items in list
	else if (size % 2 == 0) {
		for (int i = 0; i < (size /2); i++) {
			sl.swap(i, size - 1 - i);
		}
	}
	//odd cases
	else {
		for (int i = 0; i < ((size - 1) / 2); i++) {
			sl.swap(i, size - 1 - i);
		}
	}
}
//creates a stringlist object with each string being the string read from the text file
//PARAM: name is string; name of the text file including file type extension
//PRE: perfectly formed text files of one string per line (as per instructions)
//POST: returns a StringList
StringList readFile(string name)
{
	StringList sl;
	std::ifstream data(name);
	string str;
	if (!data) {
		return sl;
	}
	
	int i = 0;
	while (getline(data, str, '\n')) {
		sl.insert(str, i);
		i++;
	}

	data.close();
	return sl;
}
//combines two stringlist objects into another stringlist; combined list will start with first item in slA
//then alternate between the two argument StringLists until both are fully exhausted
//PARAM: slA, slB are StringList; slA first item will be first item in returned stringList unless slA is empty
//POST: returns StringListj
StringList merge(const StringList& slA, const StringList& slB)
{
	StringList sl;
	int sizeA = slA.size();
	int countA = 0;
	int sizeB = slB.size();
	int countB = 0;
	int countReturn = 0;
	//for loop will end when both stringlists are exhausted
	for (int i = 0; countA < sizeA || countB < sizeB; i++) {
		if (i % 2 == 0 && countA < sizeA) {
			sl.insert(slA.retrieve(countA), countReturn);
			countA++;
			countReturn++;
		}
		else if (countB < sizeB) {
			sl.insert(slB.retrieve(countB), countReturn);
			countB++;
			countReturn++;
		}
	}

	return sl;
}

