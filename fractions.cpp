#include <iostream>
#include <string>
#include <cstdint>
#include <numeric> 
#include <cmath>
#include <limits> //импорт библиотек


class Rational {
private:
    int64_t num_;
    uint64_t den_;

    static int64_t gcd(int64_t a, int64_t b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int64_t temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    void normalize() {
        if (den_ == 0) {
            std::cout << ("Denominator cannot be zero");
        }

        if (num_ == 0) {
            den_ = 1;
            return;
        }

        int64_t g = gcd(std::abs(num_), den_);
        num_ /= g;
        den_ /= g;



    }

public:

    Rational() : num_(0), den_(1) {}

  
    Rational(int64_t numerator) : num_(numerator), den_(1) {}


    Rational(int64_t numerator, int64_t denominator) : num_(numerator), den_(denominator) {
        if (denominator == 0) {
            std::cout << ("Denominator cannot be zero");
        }
        normalize();
    }


    int64_t numerator() const { return num_; }


    uint64_t denominator() const { return den_; }

    explicit operator double() const {
        return static_cast<double>(num_) / static_cast<double>(den_);
    }


    std::string str() const {
        if (den_ == 1) {
            return std::to_string(num_);
        }
        else {
            return std::to_string(num_) + "/" + std::to_string(den_);
        }
    }

  
    Rational operator-() const {
        return Rational(-num_, den_);
    }

  
    Rational operator+(const Rational& other) const {
        int64_t new_num = num_ * static_cast<int64_t>(other.den_) + other.num_ * static_cast<int64_t>(den_);
        uint64_t new_den = den_ * other.den_;
        return Rational(new_num, new_den);
    }

    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }

 
    Rational operator-(const Rational& other) const {
        int64_t new_num = num_ * static_cast<int64_t>(other.den_) - other.num_ * static_cast<int64_t>(den_);
        uint64_t new_den = den_ * other.den_;
        return Rational(new_num, new_den);
    }

    Rational& operator-=(const Rational& other) {
        *this = *this - other;
        return *this;
    }

    Rational operator*(const Rational& other) const {
        int64_t new_num = num_ * other.num_;
        uint64_t new_den = den_ * other.den_;
        return Rational(new_num, new_den);
    }

    Rational& operator*=(const Rational& other) {
        *this = *this * other;
        return *this;
    }


    Rational operator/(const Rational& other) const {
        if (other.num_ == 0) {
            std::cout << ("Division by zero");
        }
        int64_t new_num = num_ * static_cast<int64_t>(other.den_);
        uint64_t new_den = den_ * static_cast<uint64_t>(std::abs(other.num_));

 
        if (other.num_ < 0) {
            new_num = -new_num;
        }
        return Rational(new_num, new_den);
    }

    Rational& operator/=(const Rational& other) {
        *this = *this / other;
        return *this;
    }


    bool operator==(const Rational& other) const {
        return num_ == other.num_ && den_ == other.den_;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return num_ * static_cast<int64_t>(other.den_) < other.num_ * static_cast<int64_t>(den_);
    }

    bool operator<=(const Rational& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Rational& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

  
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.str();
        return os;
    }
};


int main() {

    Rational r1; 
    Rational r2(5); 
    Rational r3(1, 2); 
    Rational r4(2, 4); 
    Rational r5(-3, 6);

    std::cout << "r1: " << r1.str() << std::endl;
    std::cout << "r2: " << r2.str() << std::endl;
    std::cout << "r3: " << r3.str() << std::endl;
    std::cout << "r4: " << r4.str() << std::endl;
    std::cout << "r5: " << r5.str() << std::endl;
    

    return 0;
}

















