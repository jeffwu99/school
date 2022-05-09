#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;
	int gcd();
public:
	Fraction(int n, int d);
	Fraction();
	Fraction(const Fraction& f);
	double getDecimal();
	void simplify();
	void setNumerator(int n);
	void setDenominator(int d);
	void addTo(const Fraction& f);
	void addTo(int n, int d);
	void subtractFrom(const Fraction& f);  //assumes "this" - f
	void subtractFrom(int n, int d);       //assumes "this" - n, d
	void multiplyTo(const Fraction& f);
	void multiplyTo(int n, int d);
	void divideBy(const Fraction& f);      //assumes "this" / f
	void divideBy(int n, int d);           //assumes "this" / n, d
	void display() const;
};