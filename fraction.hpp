#pragma once
#include <cstdint>
#include <string>

class fraction {
private:
    int64_t num;
    uint64_t den;
    
    void reduce_fractions();
public:
    // конструкторы
    fraction();
    fraction(int64_t n);
    fraction(int64_t numerator, int64_t denominator);

    // методы доступа
    int64_t numerator() const;
    uint64_t denominator() const;

    explicit operator double() const;
    std::string str() const;

    // арифметические опрации
    fraction operator+(const fraction& other) const;
    fraction operator-(const fraction& other) const;  
    fraction operator*(const fraction& other) const;
    fraction operator/(const fraction& other) const;
    fraction operator-() const;

    fraction& operator+=(const fraction& other);
    fraction& operator-=(const fraction& other);
    fraction& operator*=(const fraction& other);
    fraction& operator/=(const fraction& other);

    // операции сравнения
    bool operator==(const fraction& other) const;
    bool operator!=(const fraction& other) const;
    bool operator<(const fraction& other) const;
    bool operator<=(const fraction& other) const;
    bool operator>(const fraction& other) const;
    bool operator>=(const fraction& other) const;
};
