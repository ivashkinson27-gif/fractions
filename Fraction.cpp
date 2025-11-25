#include "Fraction.h"
#include <cmath>
#include <string>

using namespace std;

int64_t Fraction::gcd(int64_t a, int64_t b)
{
	a = abs(a);
	b = abs(b);

	while (b != 0)
	{
		int64_t temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void Fraction::normalize()
{
	if (static_cast<int64_t>(den) < 0)
	{
		num = -num;
		den = -static_cast<int64_t>(den);
	}

	int64_t common = gcd(num, den);
	if (common != 0)
	{
		num /= common;
		den /= common;
	}

	if (num == 0)
	{
		den = 1;
	}
}

Fraction::Fraction() : num(0), den(1)
{

}

Fraction::Fraction(int64_t value) : num(value), den(1)
{

}

Fraction::Fraction(int64_t numerator, int64_t denominator) : num(numerator), den(denominator)
{
	normalize();
}

Fraction::operator double() const
{
	return static_cast<double>(num) / static_cast<double>(den);
}

string Fraction::str() const
{
	if (den == 1)
	{
		return to_string(num);
	}
	else
	{
		return to_string(num) + "/" + to_string(den);
	}
}

Fraction Fraction::operator+() const
{
	return *this;
}

Fraction Fraction::operator-() const
{
	return Fraction(-num, den);
}

Fraction Fraction::operator+(const Fraction& other) const
{
	int64_t new_num = num * static_cast<int64_t>(other.den) + other.num * static_cast<int64_t>(den);
	uint64_t new_den = den * other.den;
	return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(const Fraction& other) const
{
	int64_t new_num = num * static_cast<int64_t>(other.den) - other.num * static_cast<int64_t>(den);
	uint64_t new_den = den * other.den;
	return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction a(num, other.den);
	Fraction b(other.num, den);

	int64_t new_sum = a.num * b.num;
	uint64_t new_den = a.den * b.den;
	return Fraction(new_sum, new_den);
}

Fraction Fraction::operator/(const Fraction& other) const
{
	int64_t new_num = num * static_cast<int64_t>(other.den);
	int64_t new_den = den * other.num;

	if (new_den < 0)
	{
		new_num = -new_num;
		new_den = -new_den;
	}

	return Fraction(new_num, new_den);
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	*this = *this + other;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	*this = *this - other;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	*this = *this * other;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	*this = *this / other;
	return *this;
}

bool Fraction::operator==(const Fraction& other) const
{
	return num == other.num && den == other.den;
}

bool Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const
{
	return num * static_cast<int64_t>(other.den) < other.num * static_cast<int64_t>(den);
}

bool Fraction::operator<=(const Fraction& other) const
{
	return *this < other || *this == other;
}

bool Fraction::operator>(const Fraction& other) const
{
	return !(*this <= other);
}

bool Fraction::operator>=(const Fraction& other) const
{
	return !(*this < other);
}

int main()
{

	return 0;
}