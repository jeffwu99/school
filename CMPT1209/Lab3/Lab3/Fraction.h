#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;
	int gcd() const;
public:
	Fraction(int n, int d);
	Fraction();
	double getDecimal() const;
	void simplify();
	void setNumerator(int n);
	void setDenominator(int d);
	Fraction(const Fraction& f);
	Fraction operator+(const Fraction& f) const;
	double operator+(double d);
	Fraction operator-(const Fraction& f) const;
	double operator-(double d);
	Fraction operator*(const Fraction& f) const;
	double operator*(double d);
	Fraction operator/(const Fraction& f) const;
	Fraction& operator=(const Fraction& f);
	double operator/(double d);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	bool operator>(const Fraction& f);
	bool operator<(const Fraction& f);
	bool operator==(const Fraction& f);
	bool operator>=(const Fraction& f);
	bool operator<=(const Fraction& f);
	void display();
};
