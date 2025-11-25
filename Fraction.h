#ifndef FRACTION_H
#define FRACTION_H

#include <cstdint>
#include <string>

using namespace std;

class Fraction
{
private:
	int64_t num;
	uint64_t den;
	static int64_t gcd(int64_t a, int64_t b);
	void normalize();

public:
	Fraction();
	Fraction(int64_t value);
	Fraction(int64_t numerator, int64_t denominator);
	Fraction(const Fraction&) = default;
	Fraction& operator=(const Fraction&) = default;

	int64_t numerator() const
	{
		return num;
	}

	uint64_t denominator() const
	{
		return den;
	}

	explicit operator double() const;
	string str() const;

	Fraction operator+() const;
	Fraction operator-() const;

	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
};

#endif