#include "PrimeList.h"

PrimeList::PrimeList() : num(0), last(0), list(nullptr) {
	cout << "> Default constructor called." << endl;
}

PrimeList::PrimeList(unsigned int n) : num(n), list(new long int[n]) {
	cout << "> One-arg constructor called." << endl;
	if (n == 0) {
		delete[] list;
		list = nullptr;
		last = 0;
	}
	else {
		unsigned int count = 0;
		for (long int i = 0; count < n; i++) {
			if (isPrime(i)) {
				list[count] = i;
				count++;
			}
		}
		last = list[num - 1];
	}
}

PrimeList::PrimeList(const PrimeList& pl) : num(pl.num), list(new long int[pl.num]), last(pl.last) {
	cout << "> Copy constructor called" << endl;
	if (pl.num == 0) {
		delete[] list;
		list = nullptr;
	}
	else {
		for (unsigned int i = 0; i < pl.num; i++) {
			list[i] = pl.list[i];
		}
	}
}

PrimeList::PrimeList(PrimeList&& tempVal) : num(tempVal.num), list(new long int[tempVal.num])
{
	cout << "> Move constructor called." << endl;
	if (tempVal.num == 0) {
		delete[] list;
		list = nullptr;
		last = 0;
	}
	else { 
		swap(list, tempVal.list);
		last = list[num - 1];
	}
}

PrimeList::PrimeList(long int* passedList, int passedNum) : num(passedNum), list(new long int[passedNum]) {
	bool flag = false;
	cout << "> One-arg-array constructor called." << endl;
	if (passedNum == 0) {
		delete[] list;
		list = nullptr;
		last = 0;
	}
	else {
		for (int i = 0; i < passedNum; i++) {
			if (!isPrime(passedList[i])) {
				flag = true;
			}
			list[i] = passedList[i];
		}
		last = passedList[passedNum - 1];
		if (flag) {
			cout << "> Error: input list must consist of prime numbers only." << endl;
			num = 0;
			delete[] list;
			list = nullptr;
			last = 0;
		}
	}
}

PrimeList::~PrimeList() {
	cout << "> Destructor called for list with " << this->num << " Prime numbers." << endl;
	delete[] list;
}

bool PrimeList::isPrime(long int n) {
	if (n <= 1)
		return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

const PrimeList& PrimeList::operator++() {

	//for low memory, high cpu usage
	delete[] list;
	++num;
	list = new long int[num];
	unsigned int count = 0;
	for (long int i = 0; count < num; i++) {
		if (isPrime(i)) {
			list[count] = i;
			count++;
		}
	}
	last = list[num - 1];
	//for larger memory, very high primelist 
	/*
	for (long int i = last + 1; last > -1; i++) {
		if (isPrime(i)) {
			last = i;
			break;
		}
	}
	long int* arr = new long int[num];
	for (long int j = 0; j < num; j++) {
		arr[j] = list[j];
	}
	delete[] list;
	++num;
	list = new long int[num];
	for (long int k = 0; k < num - 1; k++) {
		list[k] = arr[k];
	}
	list[num - 1] = last;
	delete[] arr;
	*/

	return *this;
}

const PrimeList& PrimeList::operator--() {
	if (num == 0) {
		cout << "> Error: list is empty." << endl;
		return *this;
	}

	//for low memory, high cpu usage
	delete[] list;
	--num;
	list = new long int[num];
	unsigned int count = 0;
	for (long int i = 0; count < num; i++) {
		if (isPrime(i)) {
			list[count] = i;
			count++;
		}
	}
	last = list[num - 1];

	//for larger memory, very high primelist 
	/*
	long int* arr = new long int[num];
	for (long int i = 0; i < num - 1; i++) {
		arr[i] = list[i];
	}
	delete[] list;
	--num;
	list = new long int[num];
	for (long int k = 0; k < num; k++) {
		list[k] = arr[k];
	}
	last = list[num - 1];
	delete[] arr;

	*/
	
	return *this;
}

const PrimeList& PrimeList::operator=(const PrimeList& pl) {
	cout << "> Assignment operator called" << endl;
	if (pl.num == 0) {
		num = 0;
		delete[] list;
		list = nullptr;
		last = 0;
	}
	else if (this != &pl) {
		delete[] list;
		num = pl.num;
		list = new long int[pl.num];
		for (unsigned int i = 0; i < pl.num; i++) {
			list[i] = pl.list[i];
		}
		last = this->getLast();
	}
	return *this;
}

const PrimeList& PrimeList::operator=(PrimeList&& temp) {
	cout << "> Move assignment called." << endl;
	if (temp.num == 0) {
		num = 0;
		delete[] list;
		list = nullptr;
		last = 0;
	}
	else {
		delete[] list;
		num = temp.num;
		list = new long int[temp.num];
		swap(list, temp.list);

		last = list[num - 1];
	}
	
	return *this;
}

ostream& operator<<(ostream& outs, const PrimeList& pl) {
	if (pl.num == 0) {
		outs << "{}";
		return outs;
	}

	outs << "{";
	for (unsigned int i = 0; i < pl.num - 1; i++) {
		outs << pl.list[i] << ", ";
	}
	outs << pl.list[pl.num - 1] << "}";
	return outs;
}

long int PrimeList::getLast() {
	if (this->num == 0) {
		cout << "Error: list is empty, 0 is returned." << endl;
	}
	return this->last;
}

int PrimeList::getLength() {
	return this->num;
}

PrimeList makePrimeList(long int* arr, unsigned int size) {
	PrimeList temp(PrimeList(arr, size));
	return temp;
}