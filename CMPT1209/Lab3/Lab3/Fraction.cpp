#include "Fraction.h"
#include <iostream>


int Fraction::gcd() const {
	int t;
	int a = numerator;
	int b = denominator;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return std::max(a, (a * (-1)));
}

Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
	setDenominator(d);
}

Fraction::Fraction() : numerator(1), denominator(1) {}

double Fraction::getDecimal() const {
	return static_cast<double>(numerator) / denominator;
}

void Fraction::simplify() {
	int commonDenom = gcd();
	numerator /= commonDenom;
	denominator /= commonDenom;
}

void Fraction::setNumerator(int n) {
	numerator = n;
}

void Fraction::setDenominator(int d) {
	if (d == 0) {
		std::cout << "ERROR! Denominator must not be zero!" << std::endl;
		std::cout << "Denominator has been set equal to 1." << std::endl;
		denominator = 1;
	} 
	else {
		denominator = d;
	}
}

Fraction::Fraction(const Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
}

Fraction Fraction::operator+(const Fraction& f) const {
	Fraction tempFrac;
	if (f.denominator < 0) {

	}
	tempFrac.numerator = (this->numerator * f.denominator) + (f.numerator * this->denominator);
	tempFrac.denominator = f.denominator * this->denominator;
	tempFrac.simplify();
	return tempFrac;

	//would this be quicker to execute? (but also much harder to read)
	/*	
	Fraction tempfrac((this->numerator * f.denominator) + (f.numerator * this->denominator),
		(f.denominator * this->denominator));
	tempfrac.simplify();
	return tempfrac;
	*/
	//applies to all return by value fraction operator overloads
}

double Fraction::operator+(double d) {
	return this->getDecimal() + d;
}

Fraction Fraction::operator-(const Fraction& f) const {
	Fraction tempFrac;
	tempFrac.numerator = (this->numerator * f.denominator) - (f.numerator * this->denominator);
	tempFrac.denominator = f.denominator * this->denominator;
	tempFrac.simplify();
	return tempFrac;
}

double Fraction::operator-(double d) {
	return this->getDecimal() - d;
}

Fraction Fraction::operator*(const Fraction& f) const {
	Fraction tempFrac;
	tempFrac.numerator = this->numerator * f.numerator;
	tempFrac.denominator = this->denominator * f.denominator;
	tempFrac.simplify();
	return tempFrac;
}

double Fraction::operator*(double d) {
	return this->getDecimal() * d;
}

Fraction Fraction::operator/(const Fraction& f) const {
	Fraction tempFrac;
	tempFrac.numerator = this->numerator * f.denominator;
	tempFrac.denominator = this->denominator * f.numerator;
	tempFrac.simplify();
	return tempFrac;
}

double Fraction::operator/(double d) {
	return this->getDecimal() / d;
}

Fraction& Fraction::operator=(const Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
	return *this;
}

Fraction& Fraction::operator++() {
	numerator = numerator + denominator;
	this->simplify();
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction tempFrac(numerator, denominator);
	numerator = numerator + denominator;
	denominator = denominator;
	this->simplify();
	tempFrac.simplify();
	return tempFrac;
}

Fraction& Fraction::operator--() {
	numerator = numerator - denominator;
	this->simplify();
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction tempFrac(numerator, denominator);
	numerator = numerator - denominator;
	denominator = denominator;
	this->simplify();
	tempFrac.simplify();
	return tempFrac;
}

//denominator signs matter now
bool Fraction::operator>(const Fraction& f) {
	if (denominator < 0 && f.denominator < 0) {
		return (numerator * f.denominator > f.numerator * denominator);
	}
	else if (denominator < 0 && f.denominator > 0) {
		return (numerator * f.denominator < f.numerator * std::abs(denominator));
	}
	else if (denominator > 0 && f.denominator < 0) {
		return (numerator * std::abs(f.denominator) > f.numerator* denominator);
	}
	else {
		return (numerator * f.denominator > f.numerator * denominator);
	}
}

bool Fraction::operator<(const Fraction& f) {
	return !(*this > f);
}

bool Fraction::operator==(const Fraction& f) {
	return (numerator * f.denominator == f.numerator * denominator);
}

bool Fraction::operator>=(const Fraction& f) {
	return (*this > f || *this == f);
}

bool Fraction::operator<=(const Fraction& f) {
	return (*this < f || *this == f);
}


void Fraction::display() {
	std::cout << numerator << " / " << denominator;
}