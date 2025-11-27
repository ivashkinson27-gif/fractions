#include "rational.h"
#include <numeric>   // std::gcd
#include <stdexcept>
#include <sstream>

void Rational::normalize() {
    if (den == 0) {
        den = 1;
    }

    if ((int64_t) den < 0) {
        den = -(int64_t)den;
        num = -num;
    }

    int64_t g = std::gcd(num, (int64_t)den);
    if(g < 0) g = -g;
    if(g > 1) {
        num /= g;
        den /= g; 
    }
}


Rational::Rational() : num(0), den(1) {}

Rational::Rational(int64_t value) : num(value), den(1) {}

Rational::Rational(int64_t numerator, uint64_t denominator) : num(numerator), den(denominator < 0 ? -denominator : denominator)
{
    if(denominator < 0) num = -numerator;
    normalize();
}


int64_t Rational::numerator() const {
    return num;
}

uint64_t Rational::denominator() const {
    return den;
}

Rational::operator double() const {
    return double(num) / double(den);
}

std::string Rational::str() const {
    std::ostringstream os;
    os << num << "/" << den;
    return os.str();
}



Rational Rational::operator+(const Rational& other) const {
    // a/b + c/d = (ad + bc) / bd
    int64_t a = num, b = den;
    int64_t c = other.num, d = other.den;
    
    int64_t g = std::gcd(b, d);
    int64_t lcm = (b / g) * d;

    // ad/g + bc/g
    int64_t left = a * (d / g);
    int64_t right = c * (b / g);

    Rational res(left + right, lcm);
    res.normalize();
    return res;
} 

Rational Rational::operator-(const Rational& other) const {
    return (*this) + (-other);
}

Rational Rational::operator*(const Rational& other) const {
    // (a/g1 * c/g2)/(b/g2 * d/g1)
    int64_t a = num, b = den;
    int64_t c = other.num, d = other.den;

    int64_t g1 = std::gcd(a, (int64_t)d);
    int64_t g2 = std::gcd(c, (int64_t)b);

    Rational res((a / g1) * (c / g2), (b / g2) * (d / g1));
    res.normalize();
    return res;
}

Rational Rational::operator/(const Rational& other) const {
    // a/b / (c/d)=ad/bc
    int64_t a = num, b = den;
    int64_t c = other.num, d = other.den;

    int64_t g1 = std::gcd(a, c);
    int64_t g2 = std::gcd((int64_t)b, (int64_t)d);

    Rational res((a/g1) * (d/g2), (b/g2) * (c/g1));
    res.normalize();
    return res;
}

Rational& Rational::operator+=(const Rational& other) {
    *this = (*this + other);
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = (*this - other);
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = (*this * other);
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = (*this / other);
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-num, den);
}

bool Rational::operator==(const Rational& other) const {
    return num == other.num && den == other.den;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
    return (__int128)num * other.den < (__int128)other.num * den;
}

bool Rational::operator<=(const Rational& other) const {
    return !((*this) > other);
}

bool Rational::operator>(const Rational& other) const {
    return other < (*this);
}

bool Rational::operator>=(const Rational& other) const {
    return !((*this) < other);
}

