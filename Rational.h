#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <cstdint>
#include <numeric>

class Rational {
private:
    int64_t num;
    uint64_t den;

    void reduce();

public:
    // Конструкторы
    Rational();
    explicit Rational(int64_t value);
    Rational(int64_t numerator, int64_t denominator);

    // Доступ к компонентам
    int64_t numerator() const;
    uint64_t denominator() const;

    // Преобразования
    explicit operator double() const;
    std::string str() const;

    // Унарные операции
    Rational operator-() const;

    // Арифметические операции
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;

    // Операции сравнения
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;
    bool operator<=(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;
    bool operator>=(const Rational& rhs) const;
};

// Внешний оператор вывода
std::ostream& operator<<(std::ostream& os, const Rational& r);

#endif // RATIONAL_H
