#include "fraction.h"
#include <numeric>
#include <cstdlib>


// констркторы

Fraction::Fraction() = default;

Fraction::Fraction(int64_t numerator) {
        num_ = numerator;
}

Fraction::Fraction(int64_t numerator, int64_t denominator) {
    if (denominator == 0) {
        denominator = 1;
    } else if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    num_ = numerator;
    den_ = denominator;
    reduce();
}

int64_t Fraction::numerator() const { return num_; }
uint64_t Fraction::denominator() const { return den_; }

Fraction::operator double() const {
    return static_cast<double>(num_) / static_cast<double>(den_);
}

std::string Fraction::str() const {
    if (den_ == 1) {
        return std::to_string(num_);
    }
    return std::to_string(num_) + "/" + std::to_string(den_);
}

// сокращение дроби

void Fraction::reduce() {
    if (num_ == 0) {
        den_ = 1;
        return;
    }

    int64_t g = std::gcd(std::llabs(num_), (int64_t)den_);
    num_ /= g;
    den_ /= g;
}

// арифметика

Fraction& Fraction::operator+=(const Fraction& other) {
    num_ = num_ * other.den_ + other.num_ * den_;
    den_ = den_ * other.den_;
    reduce();
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction r = *this;
    r += other;
    return r;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    num_ = num_ * other.den_ - other.num_ * den_;
    den_ = den_ * other.den_;
    reduce();
    return *this;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction r = *this;
    r -= other;
    return r;
}

Fraction Fraction::operator-() const {
    return Fraction(-num_, den_);
}

Fraction& Fraction::operator*=(const Fraction& other) {
    num_ = num_ * other.num_;
    den_ = den_ * other.den_;
    reduce();
    return *this;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction r = *this;
    r *= other;
    return r;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    num_ = num_ * other.den_;
    den_ = den_ * other.num_;
    reduce();
    return *this;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction r = *this;
    r /= other;
    return r;
}

// сравнения

bool Fraction::operator==(const Fraction& other) const {
    return num_ == other.num_ && den_ == other.den_;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return num_ * static_cast<int64_t>(other.den_) < other.num_ * static_cast<int64_t>(den_);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}