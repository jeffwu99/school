#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f1(2, 0), f2(1, 6), f3;
	double d;
	f1.setDenominator(3);
	f3 = f1 + f2;
	f3.display();
	cout << endl;
	f3 = f1 + f2 + f3;
	f3.display();
	cout << endl;
	d = f1 + 0.75;
	cout << d << endl;
	f3 = f1 - f2;
	f3.display();
	cout << endl;
	d = f1 - 0.5;
	cout << d << endl;
	f1.setDenominator(0);
	f3 = f1 * f2;
	f3.display();
	cout << endl;
	d = f1 * 2.0;
	cout << d << endl;
	f3 = f1 / f2;
	f3.display();
	cout << endl;
	d = f1 / (-2.0);
	cout << d << endl;
	f2++.display();
	cout << endl;
	(++f2).display();
	cout << endl;
	(f2++)++.display();
	cout << endl;
	(++(++f2)).display();
	cout << endl;
	f2--.display();
	cout << endl;
	(--f2).display();
	cout << endl;
	(f2--)--.display();
	cout << endl;
	(--(--f2)).display();
	cout << endl;
	if (f1 > f2)
	{
		f1.display();
		cout << " > ";
		f2.display();
		cout << endl;
	}
	f1.setNumerator(1);
	f1.setDenominator(6);
	if (f1 == f2)
	{
		f1.display();
		cout << " = ";
		f2.display();
		cout << endl;
	}
	
	return 0;
}
