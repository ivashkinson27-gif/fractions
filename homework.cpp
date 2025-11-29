#include <iostream>
#include <string>
#include <cstdint>
#include <numeric>
#include <cmath>
#include <limits>
#include <cassert>

class Rational {
private:
    int64_t num_;
    int64_t den_; 

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
            den_ = 1;
            return;
        }
        
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
        
        int64_t common = gcd(num_, den_);
        num_ /= common;
        den_ /= common;
        
        
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    
    Rational() : num_(0), den_(1) {}
    
    Rational(int64_t value) : num_(value), den_(1) {}
    
    Rational(int64_t numerator, int64_t denominator) 
        : num_(numerator), den_(denominator) {
        normalize();
    }

    
    int64_t numerator() const { return num_; }
    uint64_t denominator() const { return static_cast<uint64_t>(den_); }

    explicit operator double() const {
        return static_cast<double>(num_) / static_cast<double>(den_);
    }

    std::string str() const {
        if (den_ == 1) {
            return std::to_string(num_);
        } else {
            return std::to_string(num_) + "/" + std::to_string(den_);
        }
    }

    
    Rational operator+() const { return *this; }
    Rational operator-() const { return Rational(-num_, den_); }

    
    Rational operator+(const Rational& other) const {
        
        int64_t new_num = num_ * other.den_ + den_ * other.num_;
        int64_t new_den = den_ * other.den_;
        return Rational(new_num, new_den);
    }

    Rational operator-(const Rational& other) const {
        int64_t new_num = num_ * other.den_ - den_ * other.num_;
        int64_t new_den = den_ * other.den_;
        return Rational(new_num, new_den);
    }

    Rational operator*(const Rational& other) const {
        int64_t new_num = num_ * other.num_;
        int64_t new_den = den_ * other.den_;
        return Rational(new_num, new_den);
    }

    Rational operator/(const Rational& other) const {
        if (other.num_ == 0) {
            
            return Rational((num_ >= 0) ? 
                std::numeric_limits<int64_t>::max() : 
                std::numeric_limits<int64_t>::min(), 1);
        }
        
        int64_t new_num = num_ * other.den_;
        int64_t new_den = den_ * other.num_;
        return Rational(new_num, new_den);
    }

    
    bool operator==(const Rational& other) const {
        return num_ == other.num_ && den_ == other.den_;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return num_ * other.den_ < other.num_ * den_;
    }

    bool operator<=(const Rational& other) const {
        return num_ * other.den_ <= other.num_ * den_;
    }

    bool operator>(const Rational& other) const {
        return num_ * other.den_ > other.num_ * den_;
    }

    bool operator>=(const Rational& other) const {
        return num_ * other.den_ >= other.num_ * den_;
    }
};

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.str();
    return os;
}