#include "Vector.h"
#include <iostream>
#include <math.h>

Vector::Vector() : components{ 0, 0, 0 } {}

Vector::Vector(double a, double b, double c) : components{ a, b, c } {}

const Vector operator+ (const Vector& vOne, const Vector& vTwo) {
	double x, y, z;
	x = vOne.components[0] + vTwo.components[0];
	y = vOne.components[1] + vTwo.components[1];
	z = vOne.components[2] + vTwo.components[2];
	return Vector(x, y, z);
}


const Vector operator- (const Vector& vOne, const Vector& vTwo) {
	double x, y, z;
	x = vOne.components[0] - vTwo.components[0];
	y = vOne.components[1] - vTwo.components[1];
	z = vOne.components[2] - vTwo.components[2];
	return Vector(x, y, z);
}

const Vector operator- (const Vector& vOne) {
	double x, y, z;
	x = -1.0 * vOne.components[0];
	y = -1.0 * vOne.components[1];
	z = -1.0 * vOne.components[2];
	return Vector(x, y, z);
}

const Vector operator* (const Vector& vOne, const Vector& vTwo) {
	double x, y, z;
	x = (vOne.components[1] * vTwo.components[2]) - (vOne.components[2] * vTwo.components[1]);
	y = -((vOne.components[0] * vTwo.components[2]) - (vOne.components[2] * vTwo.components[0]));
	z = (vOne.components[0] * vTwo.components[1]) - (vOne.components[1] * vTwo.components[0]);
	return Vector(x, y, z);
}

Vector& Vector::operator= (const Vector& vOne) {
	this->components[0] = vOne.components[0];
	this->components[1] = vOne.components[1];
	this->components[2] = vOne.components[2];
	return *this;
}

ostream& operator <<(ostream& output, const Vector& vOne) {
	output << "["
		<< vOne.components[0] << ", "
		<< vOne.components[1] << ", "
		<< vOne.components[2] << "]";
	return output;
}

istream& operator >>(istream& input, Vector& vOne) {
	std::cout << "Please enter a number for component 0: " << std::endl;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		input >> vOne.components[0];
		if (!cin.good()) {
			std::cout << "ERROR! Invalid number." << std::endl;
			std::cout << "Please enter a valid number for component 0:" << std::endl;
		}
	} while (cin.fail());

	std::cout << "Please enter a number for component 1: " << std::endl;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		input >> vOne.components[1];
		if (!cin.good()) {
			std::cout << "ERROR! Invalid number." << std::endl;
			std::cout << "Please enter a valid number for component 1:" << std::endl;
		}
	} while (cin.fail());

	std::cout << "Please enter a number for component 2: " << std::endl;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		input >> vOne.components[2];
		if (!cin.good()) {
			std::cout << "ERROR! Invalid number." << std::endl;
			std::cout << "Please enter a valid number for component 2:" << std::endl;
		}
	} while (!cin.good());

	return input;
}

bool operator>(const Vector& vOne, const Vector& vTwo) {
	return getMagnitude(vOne) > getMagnitude(vTwo);
}

bool operator<(const Vector& vOne, const Vector& vTwo) {
	return getMagnitude(vOne) < getMagnitude(vTwo);
}

bool operator==(const Vector& vOne, const Vector& vTwo) {
	return (vOne.components[0] == vTwo.components[0] &&
		vOne.components[1] == vTwo.components[1] &&
		vOne.components[2] == vTwo.components[2]);
}

bool operator>=(const Vector& vOne, const Vector& vTwo) {
	return (vOne == vTwo || vOne > vTwo);
}

bool operator<=(const Vector& vOne, const Vector& vTwo) {
	return (vOne == vTwo || vOne < vTwo);
}

double& Vector::operator[](int index) {
	return this->components[index];
}

double getMagnitude(const Vector& vOne) {
	double x = pow(vOne.components[0], 2.0);
	double y = pow(vOne.components[1], 2.0);
	double z = pow(vOne.components[2], 2.0);
	return sqrt(x + y + z);
}
