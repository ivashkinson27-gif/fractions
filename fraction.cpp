#include "fraction.hpp"
#include <numeric>
#include <cmath>

void fraction::reduce_fractions() {
    if (num == 0) {
        den = 1;
        return;
    }
    
    int64_t gcd = std::gcd(std::abs(num), den);
    
    num /= gcd;
    den /= gcd;
}

// конструкторы
fraction::fraction() : num(0), den(1) {}
fraction::fraction(int64_t n) : num(n), den(1) {}
fraction::fraction(int64_t numerator, int64_t denominator) {
    if (denominator == 0) {
        denominator = 1;
    }
    
    if (denominator < 0) {
        num = -numerator;
        den = -denominator;
    } else {
        num = numerator;
        den = denominator;
    }
    
    reduce_fractions();
}

// методы доступа
int64_t fraction::numerator() const {
    return num; 
}

uint64_t fraction::denominator() const { 
    return den; 
}


fraction::operator double() const {
    return static_cast<double>(num) / static_cast<double>(den);
}

std::string fraction::str() const {
    if (den == 1) {
        return std::to_string(num);
    }
    return std::to_string(num) + "/" + std::to_string(den);
}

// арифметические операции
fraction fraction::operator+(const fraction& other) const {
    uint64_t common_denominator = std::lcm(den, other.den);

    int64_t new_num1 = num * (common_denominator / den);
    int64_t new_num2 = other.num * (common_denominator / other.den);
    
    int64_t result_num = new_num1 + new_num2;
    
    return fraction(result_num, common_denominator);
}

fraction fraction::operator-(const fraction& other) const {
    uint64_t common_denominator = std::lcm(den, other.den);
    int64_t new_num1 = num * (common_denominator / den);
    int64_t new_num2 = other.num * (common_denominator / other.den);
    int64_t result_num = new_num1 - new_num2;
    return fraction(result_num, common_denominator);
}

fraction fraction::operator*(const fraction& other) const {
    return fraction(num * other.num, den * other.den);
}

fraction fraction::operator/(const fraction& other) const {
    return fraction(num * other.den, den * other.num);
}

fraction fraction::operator-() const {
    return fraction(-num, den);
}


fraction& fraction::operator+=(const fraction& other) {
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction& other) {
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction& other) {
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction& other) {
    *this = *this / other;
    return *this;
}

// операции сравнения
bool fraction::operator==(const fraction& other) const {
    return num == other.num && den == other.den;
}

bool fraction::operator!=(const fraction& other) const {
    return !(*this == other);
}

bool fraction::operator<(const fraction& other) const {
    int64_t left_side = num * static_cast<int64_t>(other.den);
    int64_t right_side = other.num * static_cast<int64_t>(den);
    return left_side < right_side;
}

bool fraction::operator<=(const fraction& other) const {
    return *this < other || *this == other;
}

bool fraction::operator>(const fraction& other) const {
    return other < *this;
}

bool fraction::operator>=(const fraction& other) const {
    return other <= *this;
}
