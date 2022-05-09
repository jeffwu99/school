#pragma once
#include <string>
#include <stdexcept> //to show other programmers that this class throws exceptions
//assignment instructions unclear on where fstream should be, but function requiring this library
//is not part of the StringList class


using std::string;

class StringList {
public:
	
	StringList(); // Default constructor
	StringList(const StringList& sl); // Copy constructor
	~StringList(); // destructor

	StringList& operator=(const StringList& sl); // assignment operator

	void insert(string data, int index);  // inserts string into stringlist at noted index
	string remove(int index); // removes string at noted index from stringlist
	void swap(int a, int b); // switches the strings from index "a" and "b"
	string retrieve(int index) const; // returns the string at noted index without removing item from stringlist
	int size() const; // returns stringlist currentsize
	StringList concatenate(const StringList& sl) const; // creates a stringlist object of combination of the calling and parameter objects 

private:
	int currentSize;
	int maxSize;
	string* arr;
};



//added after submission so it can compile:
StringList merge(const StringList& slA, const StringList& slB);
StringList readFile(string name);
void reverse(StringList& sl);
void print(const StringList& sl);