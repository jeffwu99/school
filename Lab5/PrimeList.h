#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class PrimeList
{
private:
	unsigned int num;
	long int last;
	long int* list;
	bool isPrime(long int);
public:
	PrimeList();
	PrimeList(unsigned int);
	PrimeList(const PrimeList&);
	PrimeList(PrimeList&&);
	PrimeList(long int*, int);
	~PrimeList();
	const PrimeList& operator++();
	const PrimeList& operator--();
	const PrimeList& operator=(const PrimeList&);
	const PrimeList& operator=(PrimeList&&);
	friend ostream& operator<<(ostream&, const PrimeList&);
	long int getLast(); //returns last
	int getLength(); //returns num
};

PrimeList makePrimeList(long int*, unsigned int);