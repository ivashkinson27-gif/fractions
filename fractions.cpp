#include <iostream>
#include <numeric>  
#include <string>
#include <compare>  
#include <cstdint>

class Rational {
private:
    int64_t numerator;      
    uint64_t denominator;    
    void reduce() {
        int64_t gcd = std::gcd(std::abs(numerator), denominator);
        
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Rational() : numerator(0), denominator(1) {}
    Rational(int64_t n) : numerator(n), denominator(1) {}
    Rational(int64_t numerator, int64_t denominator) {
        if (denominator == 0) {
            numerator = 0; denominator = 1; 
            reduce();
        }
    }

    int64_t numerator() const {
        return numerator;
    }
    uint64_t denominator() const {
        return denominator;
    }

    explicit operator double() const {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    std::string str() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    Rational& operator+=(const Rational& other) {
        uint64_t lcm_val = std::lcm(denominator, other.denominator);
        numerator = numerator * (lcm_val / denominator) + other.numerator * (lcm_val / other.denominator);
        denominator = lcm_val;
        reduce();
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        uint64_t lcm_val = std::lcm(denominator, other.denominator);
        numerator = numerator * (lcm_val / denominator) - other.numerator * (lcm_val / other.denominator);
        denominator = lcm_val;
        reduce();
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        int64_t gcd1 = std::gcd(std::abs(numerator), other.denominator);
        int64_t gcd2 = std::gcd(std::abs(other.numerator), denominator);
        numerator = (numerator / gcd1) * (other.numerator / gcd2);
        denominator = (denominator / gcd2) * (other.denominator / gcd1);
        reduce(); 
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        int64_t other_num = other.numerator;
        uint64_t other_den = other.denominator;
        
        if (other_num < 0) {
            other_num = -other_num;
            return *this *= Rational(static_cast<int64_t>(other_den) * -1, std::abs(other.numerator)); 
        }
        
        return *this *= Rational(static_cast<int64_t>(other_den), other_num);
    }

    Rational operator-() const {
        return Rational(-numerator, static_cast<int64_t>(denominator));
    }

    friend Rational operator+(Rational lhs, const Rational& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend Rational operator-(Rational lhs, const Rational& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend Rational operator*(Rational lhs, const Rational& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend Rational operator/(Rational lhs, const Rational& rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend bool operator==(const Rational& lhs, const Rational& rhs) {
        return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
    }

    friend bool operator!=(const Rational& lhs, const Rational& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const Rational& lhs, const Rational& rhs) {
        return lhs.numerator * static_cast<int64_t>(rhs.denominator) < rhs.numerator * static_cast<int64_t>(lhs.denominator);
    }

    friend bool operator>(const Rational& lhs, const Rational& rhs) {
        return rhs < lhs;
    }

    friend bool operator<=(const Rational& lhs, const Rational& rhs) {
        return !(lhs > rhs);
    }

    friend bool operator>=(const Rational& lhs, const Rational& rhs) {
        return !(lhs < rhs);
    }
};

