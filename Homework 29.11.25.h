#ifndef IT_HOMEWORK_29_11_25_H
#define IT_HOMEWORK_29_11_25_H

#include <cstdint>
#include <string>

int64_t gcd(int64_t a, int64_t b);

class Rational_number {
    int64_t simple;
    int64_t num;
    int64_t den;
public:
    void normalize();
    void showinfo() const;

    Rational_number();
    explicit Rational_number(int64_t s);
    Rational_number(int64_t n, int64_t d);

    [[nodiscard]] int64_t get_numerator() const;
    [[nodiscard]] int64_t get_denominator() const;
    [[nodiscard]] double convert_to_double() const;
    [[nodiscard]] std::string str() const;
    Rational_number operator+(const Rational_number& other) const;
    Rational_number operator-(const Rational_number &other) const;
    void operator+=(const Rational_number& other);
    void operator-=(const Rational_number &other);
    Rational_number operator*(const Rational_number& other) const;
    void operator*=(const Rational_number& other);
    Rational_number operator/(const Rational_number& other) const;
    void operator/=(const Rational_number& other);
    Rational_number operator-() const;
    bool operator==(const Rational_number& other) const;
    bool operator!=(const Rational_number &other) const;
    bool operator<(const Rational_number& other) const;
    bool operator<=(const Rational_number& other) const;
    bool operator>(const Rational_number& other) const;
    bool operator>=(const Rational_number& other) const;
};

#endif