#include <cstdint>
#include <string>
#include <sstream>
#include <numeric>
#include <iostream>

using namespace std;


class Rational {
private:
    int64_t num_;      // числитель
    uint64_t den_;     // знаменатель (всегда > 0: для дальнейшего удобства сравнения)

    // поиск НОД
    static int64_t gcd_int64(int64_t a, int64_t b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        return gcd(a, b);
    }

    // Перенос знака в числитель(для удобства сравнения чисел) и сокращение дроби
    void normalize() {
        if (den_ < 0) {
            den_ = -den_;
            num_ = -num_;
        }
        
        int64_t g = gcd_int64(num_, (int64_t)den_);
        if (g != 0) {
            num_ /= g;
            den_ /= g;
        }
    }

public:
    // Конструктор без аргументов -> 0/1
    Rational() : num_(0), den_(1) {}

    // Конструктор от целого
    Rational(int64_t x) : num_(x), den_(1) {}

    // Конструктор от числителя и знаменателя
    Rational(int64_t n, int64_t d) : num_(n), den_(d < 0 ? -d : d) {
        if (d < 0) num_ = -num_;
        normalize();
    }

    int64_t numerator() const { return num_; }
    uint64_t denominator() const { return den_; }
    
    // получения числа с плавающей точкой
    explicit operator double() const {   
        return (double)num_ / (double)den_;
    }

    // функция, которая вернет дробь типа string
    string str() const {            
        std::ostringstream oss;
        oss << num_ << "/" << den_;
        return oss.str();
    }

    // Арифметические операции
    Rational& operator+=(const Rational& other) {
        // a/b + c/d = (ad + bc) / bd
        // попытаемся минимизировать переполнение, разделив по gcd
        int64_t g = gcd_int64((int64_t)den_, (int64_t)other.den_);
        int64_t den1 = den_ / g;
        int64_t den2 = other.den_ / g;

        __int128 t = (__int128)num_ * den2 + (__int128)other.num_ * den1;
        __int128 d = (__int128)den1 * other.den_;

        num_ = (int64_t)t;
        den_ = (uint64_t)d;
        normalize();
        return *this;
    }

    Rational operator+(const Rational& r) const {
        Rational tmp = *this;
        tmp += r;
        return tmp;
    }

    Rational& operator-=(const Rational& other) {
        int64_t g = gcd_int64((int64_t)den_, (int64_t)other.den_);
        int64_t den1 = den_ / g;
        int64_t den2 = other.den_ / g;

        __int128 t = (__int128)num_ * den2 - (__int128)other.num_ * den1;
        __int128 d = (__int128)den1 * other.den_;

        num_ = (int64_t)t;
        den_ = (uint64_t)d;
        normalize();
        return *this;
    }

    Rational operator-(const Rational& r) const {
        Rational tmp = *this;
        tmp -= r;
        return tmp;
    }

    Rational& operator*=(const Rational& other) {
        int64_t g1 = gcd_int64(num_, (int64_t)other.den_);
        int64_t g2 = gcd_int64((int64_t)other.num_, (int64_t)den_);

        __int128 n = (__int128)(num_ / g1) * (other.num_ / g2);
        __int128 d = (__int128)(den_ / g2) * (other.den_ / g1);

        num_ = (int64_t)n;
        den_ = (uint64_t)d;
        normalize();
        return *this;
    }

    Rational operator*(const Rational& r) const {
        Rational tmp = *this;
        tmp *= r;
        return tmp;
    }

    Rational& operator/=(const Rational& other) {
    int64_t g1 = gcd_int64(num_, other.num_);
    int64_t g2 = gcd_int64((int64_t)den_, (int64_t)other.den_);

    int64_t a = num_ / g1;
    int64_t b = den_ / g2;
    int64_t c = other.num_ / g1;
    int64_t d = other.den_ / g2;

    // результат до нормализации:
    // num = a * d
    // den = b * c

    __int128 n128 = (__int128)a * d;
    __int128 d128 = (__int128)b * c;

    int64_t n64 = (int64_t)n128;
    int64_t d64 = (int64_t)d128;

    // нормализация знака перед тем, как превратить den в uint64_t
    if (d64 < 0) {
        d64 = -d64;
        n64 = -n64;
    }

    num_ = n64;
    den_ = (uint64_t)d64;

    normalize();
    return *this;
}


    Rational operator/(const Rational& r) const {
        Rational tmp = *this;
        tmp /= r;
        return tmp;
    }

    // Унарный минус
    Rational operator-() const {
        return Rational(-num_, den_);
    }

    // Операции сравнения
    bool operator==(const Rational& r) const {
        return num_ == r.num_ && den_ == r.den_;
    }

    bool operator!=(const Rational& r) const {
        return !(*this == r);
    }

    bool operator<(const Rational& r) const {
        // a/b < c/d => ad < cb
        __int128 left = (__int128)num_ * r.den_;
        __int128 right = (__int128)r.num_ * den_;
        return left < right;
    }

    bool operator<=(const Rational& r) const {
        return !(r < *this);
    }

    bool operator>(const Rational& r) const {
        return r < *this;
    }

    bool operator>=(const Rational& r) const {
        return !(*this < r);
    }
};


int main() {
    // Конструкторы
    Rational a;                 // 0/1
    Rational b(5);              // 5/1
    Rational c(6, -8);          // -3/4 после сокращения

    cout << "a = " << a.str() << "\n";
    cout << "b = " << b.str() << "\n";
    cout << "c = " << c.str() << "\n";

    // numerator(), denominator()
    cout << "c numerator = " << c.numerator() << "\n";
    cout << "c denumerator = " << c.denominator() << "\n";

    // Приведение к double
    cout << "c as double = " << (double)c << "\n\n";

    // Сложение
    Rational d = b + c;
    cout << "b + c = " << d.str() << "\n";

    d += Rational(1, 6);
    cout << "(b + c) += 1/6 = " << d.str() << "\n\n";

    // Вычитание
    Rational e = b - c;
    cout << "b - c = " << e.str() << "\n";

    e -= Rational(2, 3);
    cout << "(b - c) -= 2/3 = " << e.str() << "\n\n";

    // Умножение
    Rational f = b * c;
    cout << "b * c = " << f.str() << "\n";

    f *= Rational(7, 5);
    cout << "(b * c) *= 7/5 = " << f.str() << "\n\n";

    // Деление
    Rational g = b / c;
    cout << "b / c = " << g.str() << "\n";

    g /= Rational(2, 3);
    cout << "(b / c) /= 2/3 = " << g.str() << "\n\n";

    // Унарный минус
    Rational h = -c;
    cout << "-c = " << h.str() << "\n\n";

    // Сравнения
    Rational x(1, 2);
    Rational y(2, 3);

    cout << "x = " << x.str() << ", y = " << y.str() << "\n";
    cout << "x == y: " << (x == y) << "\n";
    cout << "x != y: " << (x != y) << "\n";
    cout << "x < y:  " << (x < y) << "\n";
    cout << "x <= y: " << (x <= y) << "\n";
    cout << "x > y:  " << (x > y) << "\n";
    cout << "x >= y: " << (x >= y) << "\n";

    return 0;
}
