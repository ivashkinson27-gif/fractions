#include <stdexcept>
#include <string>
#include <cstdlib>

// Класс рационального числа (дроби)
class Fraction {
private:
    long long num; // числитель
    long long den; // знаменатель (> 0)

    static long long gcd(long long a, long long b) {
        a = std::llabs(a);
        b = std::llabs(b);
        while (b != 0) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a == 0 ? 1 : a;
    }

    void normalize() {
        if (den == 0) {
            throw std::invalid_argument("denominator must not be zero");
        }
        if (num == 0) {
            den = 1;
            return;
        }
        long long g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }

public:
    // Конструктор без аргументов
    Fraction() : num(0), den(1) {}

    // Конструктор от целого
    explicit Fraction(long long n) : num(n), den(1) {
        normalize();
    }

    // Конструктор от числителя и знаменателя
    Fraction(long long n, long long d) : num(n), den(d) {
        normalize();
    }

    // Числитель и знаменатель
    long long numerator() const { return num; }
    unsigned long long denominator() const {
        return static_cast<unsigned long long>(den);
    }

    // Явное приведение к double
    explicit operator double() const {
        return static_cast<double>(num) / static_cast<double>(den);
    }

    // Строковое представление
    std::string str() const {
        if (den == 1) return std::to_string(num);
        return std::to_string(num) + "/" + std::to_string(den);
    }

    // Унарный минус
    Fraction operator-() const {
        return Fraction(-num, den);
    }

    // Арифметические операции
    Fraction operator+(const Fraction& other) const {
        long long n = num * other.den + other.num * den;
        long long d = den * other.den;
        return Fraction(n, d);
    }

    Fraction operator-(const Fraction& other) const {
        long long n = num * other.den - other.num * den;
        long long d = den * other.den;
        return Fraction(n, d);
    }

    Fraction operator*(const Fraction& other) const {
        long long n = num * other.num;
        long long d = den * other.den;
        return Fraction(n, d);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) {
            throw std::invalid_argument("division by zero fraction");
        }
        long long n = num * other.den;
        long long d = den * other.num;
        return Fraction(n, d);
    }

    // Операции присваивания
    Fraction& operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    // Операции сравнения
    bool operator==(const Fraction& other) const {
        return num == other.num && den == other.den;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return num * other.den < other.num * den;
    }

    bool operator<=(const Fraction& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator>=(const Fraction& other) const {
        return *this > other || *this == other;
    }
};
