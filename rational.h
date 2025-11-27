#ifndef RATIONAL_H  
#define RATIONAL_H

#include <cstdint>
#include <string>

class Rational {
private:
    int64_t num; //numerator
    uint64_t den; //denominator

    void normalize();

public:
    Rational();
    Rational(int64_t value);
    Rational(int64_t numerator, uint64_t denominator);


    int64_t numerator() const;
    uint64_t denominator() const;


    explicit operator double() const;

    std::string str() const;


    Rational operator + (const Rational& other) const;
    Rational operator - (const Rational& other) const;
    Rational operator * (const Rational& other) const;
    Rational operator / (const Rational& other) const;

    Rational& operator += (const Rational& other);
    Rational& operator -= (const Rational& other);
    Rational& operator *= (const Rational& other);
    Rational& operator /= (const Rational& other);

    Rational operator-() const; // унарный минус

    bool operator == (const Rational& other) const;
    bool operator != (const Rational& other) const;
    bool operator < (const Rational& other) const;
    bool operator <= (const Rational& other) const;
    bool operator > (const Rational& other) const;
    bool operator >= (const Rational& other) const;

};

#endif
