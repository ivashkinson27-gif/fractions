#include "Rational.h"

void Rational::reduce() {
    if (num == 0) {
        den = 1;
        return;
    }
    
    int64_t gcd_val = std::gcd(std::abs(num), static_cast<int64_t>(den));
    num /= gcd_val;
    den /= gcd_val;
}

Rational::Rational() : num(0), den(1) {}

Rational::Rational(int64_t value) : num(value), den(1) {}

Rational::Rational(int64_t numerator, int64_t denominator) {
    if (denominator == 0) {
        num = 0;
        den = 1;
    } else if (denominator < 0) {
        num = -numerator;
        den = -denominator;
    } else {
        num = numerator;
        den = denominator;
    }
    reduce();
}

int64_t Rational::numerator() const {
    return num;
}

uint64_t Rational::denominator() const {
    return den;
}

Rational::operator double() const {
    return static_cast<double>(num) / static_cast<double>(den);
}

std::string Rational::str() const {
    return std::to_string(num) + "/" + std::to_string(den);
}

Rational Rational::operator-() const {
    return Rational(-num, den);
}

