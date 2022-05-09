#include "PrimeList.h"

int main() {

	PrimeList p1(20), p2(p1);
	cout << "p2 = " << p2 << endl;
	cout << "++p2 = " << ++p2 << endl;
	PrimeList p3;
	long int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 32, 37 };
	p3 = makePrimeList(arr, sizeof(arr) / sizeof(arr[0]));
	cout << "p3 = " << p3 << endl;
	cout << "--p3 = " << --p3 << endl;
	cout << p3.getLast() << endl;
	arr[10] = 31;
	p3 = makePrimeList(arr, sizeof(arr) / sizeof(arr[0]));
	cout << "p3 = " << p3 << endl;
	cout << "--p3 = " << --p3 << endl;
	cout << p3.getLast() << endl;
	PrimeList p4;
	p4 = ++p3;
	cout << p4.getLength() << endl;

	return 0;
}