#pragma once
#include <cstdint>
#include <string>

class Fraction {
private:
    int64_t num_ = 0;
    uint64_t den_ = 1;

    void reduce();

public:
    Fraction();
    explicit Fraction(int64_t numerator);
    Fraction(int64_t numerator, int64_t denominator);

    int64_t numerator() const;
    uint64_t denominator() const;

    explicit operator double() const;
    std::string str() const;

    // арифметика
    Fraction& operator+=(const Fraction& other);
    Fraction  operator+(const Fraction& other) const;

    Fraction& operator-=(const Fraction& other);
    Fraction  operator-(const Fraction& other) const;

    Fraction  operator-() const;

    Fraction& operator*=(const Fraction& other);
    Fraction  operator*(const Fraction& other) const;

    Fraction& operator/=(const Fraction& other);
    Fraction  operator/(const Fraction& other) const;

    // сравнения
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
};