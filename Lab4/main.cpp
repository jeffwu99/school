#include "Vector.h"

using namespace std;

int main(void) {

	Vector a, b(3.0, 4.0, 5.0), c(b), d;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cin >> a;
	d = a + b;
	cout << d << endl;
	a[0] = 11.0;
	a[1] = -15.0;
	a[2] = 3.0;
	d = a - b;
	cout << d << endl;
	d = a * b;
	cout << d << endl;
	d = -a;
	cout << d << endl;
	d = a = b;
	cout << d << endl;
	if (a == b)
		cout << "a and b are equal!" << endl;
	else
		cout << "a and b are NOT equal!" << endl;
	a[0] = 11.0;
	a[1] = -15.0;
	a[2] = 3.0;
	b[0] = 11.0;
	b[1] = 15.0;
	b[2] = 3.0;
	if (a == b)
		cout << "a and b are equal!" << endl;
	else
		cout << "a and b are NOT equal!" << endl;
	cout << setprecision(4) << "Magnitude of a is equal to " << getMagnitude(a) <<
		endl;
	cout << "Magnitude of b is equal to " << getMagnitude(b) << endl;
	c[0] = 2;
	c[1] = -100;
	c[2] = 1;
	if (a < c)
		cout << "a < c" << endl;




	return 0;
}