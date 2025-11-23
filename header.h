#pragma once
#include <string>
#include <cstdint>

class Fraction{

private:

    int64_t num_;
    uint64_t den_;

    void reduce();

public:
    
    Fraction();
    explicit Fraction(int64_t number);
    Fraction(int64_t num_, int64_t den_);

    static uint64_t gcd(uint64_t a, uint64_t b);

    int64_t numerator() const { return num_; }
    int64_t denominator() const { return den_; }

    explicit operator double() const;
    std::string str() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    Fraction operator-() const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    
};