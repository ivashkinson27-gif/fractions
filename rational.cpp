#include "header.h"
#include <sstream>
#include <cmath>
#include <stdexcept>

// НОД

uint64_t Fraction::gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Сокращение

void Fraction::reduce() {
    if (num_ == 0) {
        den_ = 1;
        return;
    }
    
    uint64_t abs_num = (num_ < 0) ? -num_: num_;
    uint64_t com_div = gcd(den_, abs_num);

    num_ /= static_cast<int64_t>(com_div);
    den_ /= com_div;
}

//Конструкторы

Fraction::Fraction(){
    num_ = 0;
    den_ = 1;
}

Fraction::Fraction(int64_t value){
    num_ = value;
    den_ = 1;
}

Fraction::Fraction(int64_t numerator, int64_t denominator){
    if (denominator == 0){
        denominator = 1;
    }

    if (denominator < 0){
        num_ = -numerator;
        den_ = static_cast<uint64_t>(-denominator);
    } else {
        num_ = numerator;
        den_ = static_cast<uint64_t>(denominator);
    }

    reduce();   
}


//double

Fraction::operator double() const{
    return static_cast<double>(num_) / static_cast<double>(den_);
}

//string

std::string Fraction::str() const{
    std::ostringstream oss;
    if (den_ == 1){
        oss << num_;
    } else {
        oss << num_ << "/" << den_;
    }
    return oss.str();
}

//арифм. операции:  "+"

Fraction Fraction::operator+(const Fraction& other) const {
    int64_t new_num = num_ * static_cast<int64_t>(other.den_) + static_cast<int64_t>(den_) * other.num_;
    uint64_t new_den = den_ * other.den_;
    return Fraction(new_num, static_cast<int64_t>(new_den));
}

// "-"

Fraction Fraction::operator-(const Fraction& other) const {
    int64_t new_num = num_ * static_cast<int64_t>(other.den_) - static_cast<int64_t>(den_) * other.num_;
    uint64_t new_den = den_ * other.den_;
    return Fraction(new_num, static_cast<int64_t>(new_den));
}

// "*"

Fraction Fraction::operator*(const Fraction& other) const{
    int64_t new_num = num_ * other.num_;
    uint64_t new_den = den_ * other.den_;
    return Fraction(new_num, static_cast<int64_t>(new_den));
}

// "/"

Fraction Fraction::operator/(const Fraction& other) const{
    if (other.num_ == 0) {
        return Fraction(0);
    }
    int64_t new_num = num_ * static_cast<int64_t>(other.den_);
    uint64_t new_den = den_ * static_cast<uint64_t>(other.num_);
    return Fraction(new_num, static_cast<int64_t>(new_den));
}

//присваивания: "+="

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

// "-="

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

// "*="

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

// "/="

Fraction& Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

//унарный минус

Fraction Fraction::operator-() const{
    return Fraction(-num_, static_cast<int64_t>(den_));
}

//сравнения: "=="

bool Fraction::operator==(const Fraction& other) const {
    return num_ * static_cast<int64_t>(other.den_) == other.num_ * static_cast<int64_t>(den_);
}

// "!="

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

// "<"

bool Fraction::operator<(const Fraction& other) const {
    return num_ * static_cast<int64_t>(other.den_) < other.num_ * static_cast<int64_t>(den_);
}

// "<="

bool Fraction::operator<=(const Fraction& other) const {
    return *this < other || *this == other;
}

// ">"

bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

// ">="

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}
