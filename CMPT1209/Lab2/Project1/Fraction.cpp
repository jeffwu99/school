#include "Fraction.h"
#include <iostream>

Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
	setDenominator(d);
}

Fraction::Fraction() : numerator(1), denominator(1) {}

Fraction::Fraction(const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
}

int Fraction::gcd()
{
	int gcd;
	(abs(numerator) > abs(denominator)) ? gcd = abs(denominator) : gcd = abs(numerator);
	if (gcd <= 1)
		return 1;
	while (abs(numerator) % gcd != 0 || abs(denominator) % gcd != 0) {
		gcd--;
	}
	return gcd;
}

inline double Fraction::getDecimal()
{
	return static_cast<double>(numerator) / static_cast<double>(denominator);
}

void Fraction::simplify()
{
	int gcd = Fraction::gcd();
	numerator /= gcd;
	denominator /= gcd;
}

void Fraction::setNumerator(int n)
{
	numerator = n;
}

void Fraction::setDenominator(int d)
{
	if (d == 0) {
		std::cout << "ERROR! Denominator must not be zero!" << std::endl;
		std::cout << "Denominator has been set equal to 1." << std::endl;
		denominator = 1;
	}
	else {
		denominator = d;
	}
}

void Fraction::addTo(const Fraction& f)
{
	numerator = (numerator * f.denominator) + (f.numerator * denominator);
	denominator = denominator * f.denominator;
	this->simplify();
}

void Fraction::addTo(int n, int d)
{
	numerator = (numerator * d) + (n * denominator);
	denominator = denominator * d;
	this->simplify();
}

void Fraction::subtractFrom(const Fraction& f)
{
	numerator = (numerator * f.denominator) - (f.numerator * denominator);
	denominator = denominator * f.denominator;
	this->simplify();
}

void Fraction::subtractFrom(int n, int d)
{
	numerator = (numerator * d) - (n * denominator);
	denominator = denominator * d;
	this->simplify();
}

void Fraction::multiplyTo(const Fraction& f)
{
	numerator *= f.numerator;
	denominator *= f.denominator;
	this->simplify();
}

void Fraction::multiplyTo(int n, int d)
{
	numerator *= n;
	denominator *= d;
	this->simplify();
}

void Fraction::divideBy(const Fraction& f)
{
	numerator *= f.denominator;
	denominator *= f.numerator;
	this->simplify();
}

void Fraction::divideBy(int n, int d)
{
	numerator *= d;
	denominator *= n;
	this->simplify();
}

void Fraction::display() const
{
	std::cout << numerator << " / " << denominator << std::endl;
}


int main(int argc, char* argv)
{
	Fraction f1(2, 0);
	f1.setDenominator(3);
	std::cout << f1.getDecimal() << std::endl;
	Fraction f2(f1);
	f2.display();
	f2.setNumerator(1);
	f2.setDenominator(6);
	f2.display();
	f1.setDenominator(3);
	f1.addTo(f2);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(3);
	f1.addTo(6, 8);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(3);
	f1.subtractFrom(f2);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(3);
	f1.subtractFrom(6, 8);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(0);
	f1.multiplyTo(f2);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(3);
	f1.multiplyTo(6, 8);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(3);
	f1.divideBy(f2);
	f1.display();
	f1.setNumerator(2);
	f1.setDenominator(3);
	f1.divideBy(-6, 8);
	f1.display();

	return 0;
}
