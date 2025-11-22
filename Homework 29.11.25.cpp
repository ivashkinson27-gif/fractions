#include <iostream>
#include <cmath>
#include <string>
#include "Homework 29.11.25.h"
using namespace std;

int64_t gcd(const int64_t a, const int64_t b) {
    if (b == 0) {return a;}
    return gcd(b, a % b);
}

void Rational_number::showinfo() const {
    cout << num << "/" << den << endl;
}

void Rational_number::normalize() {
    if (den == 0) {
        throw runtime_error("Denominator cannot be zero");
    }
    if (den < 0) {
        num = -num;
     }
    int64_t common = gcd(abs(num), abs(den));
    num /= common;
    den /= common;

    if (num == 0) {
        den = 1;
    }
}
Rational_number::Rational_number() : simple(0), num(0), den(1) {};
Rational_number::Rational_number(int64_t s) : simple(s), num(s), den(1) {};
Rational_number::Rational_number(int64_t n, int64_t d) : simple(0), num(n), den(d) {};
int64_t Rational_number::get_numerator() const {
    return num;
}
int64_t Rational_number::get_denominator() const {
    return den;
}
double Rational_number::convert_to_double() const {
    return static_cast<double>(num) / static_cast<double>(den);
}
std::string Rational_number::str() const {
    if (den == 1) {return std::to_string(num);}
    else {return std::to_string(num) + "/" + std::to_string(den);}
}

Rational_number Rational_number::operator+(const Rational_number& other) const {
    int64_t new_num = num * other.den + other.num * den;
    int64_t new_den = den * other.den;
    return {new_num, new_den};
}
Rational_number Rational_number::operator-(const Rational_number& other) const {
    int64_t new_num = num * other.den - other.num * den;
    int64_t new_den = den * other.den;
    return {new_num, new_den};
}
void Rational_number::operator+=(const Rational_number& other) {
    num = num * other.den + other.num * den;
    den = den*other.den;
}
void Rational_number::operator-=(const Rational_number& other) {
    num = num * other.den - other.num * den;
    den = den*other.den;
}
Rational_number Rational_number::operator*(const Rational_number& other) const {
    return {num * other.num, den * other.den};
}
void Rational_number::operator*=(const Rational_number& other) {
    num *= other.num;
    den *= other.den;
}
Rational_number Rational_number::operator/(const Rational_number& other) const {
    if (other.den == 0) {
        throw runtime_error("Denominator cannot be zero");
    }
    int64_t new_num = num * other.den;
    int64_t new_den = den * other.num;
    return {new_num, new_den};
}
void Rational_number::operator/=(const Rational_number& other) {
    num *= other.den;
    den *= other.num;
}
Rational_number Rational_number::operator-() const {
    return {-num, den};
}
bool Rational_number::operator==(const Rational_number &other) const{
    return num*other.den == other.num*den;
}
bool Rational_number::operator!=(const Rational_number &other) const{
    return num*other.den != other.num*den;
}
bool Rational_number::operator<(const Rational_number &other) const {
    return num*other.den < other.num*den;
}
bool Rational_number::operator<=(const Rational_number &other) const {
    return num*other.den <= other.num*den;
}
bool Rational_number::operator>(const Rational_number &other) const {
    return num*other.den > other.num*den;
}
bool Rational_number::operator>=(const Rational_number &other) const {
    return num*other.den >= other.num*den;
}



int main() {
    Rational_number r(1000, 7);
    Rational_number r2(993, 1007);
    Rational_number r3 = r.operator*(r2);
    r3.showinfo();
}
