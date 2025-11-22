#ifndef FRACTION.HPP
#define FRACTION.HPP

int GCD(int a, int b); // grand common divisor
int LCM(int a, int b); // least common multiple

class Fraction{
public:
    Fraction();
    Fraction(int number);
    Fraction(int numerator_, int denominator_);
    int GetNumerator();
    int GetDenominator();
    operator double() const;
    Fraction (const Fraction& f);
    friend string str(const Fraction& f);
    friend std::ostream& operator<<(std::ostream & os, Fraction const & n);
    Fraction& operator+= (const Fraction& other);
    Fraction& operator/= (const Fraction& other);
    Fraction& operator-= (const Fraction& other);
    Fraction& operator*= (const Fraction& other);
    Fraction operator-() const;
    friend Fraction operator+ (Fraction a, Fraction const b);
    friend Fraction operator/ (Fraction a, Fraction const b);
    friend Fraction operator* (Fraction a, Fraction const b);
    friend Fraction operator- (Fraction a, Fraction const b);
private:
    void Reduction();
}
bool operator== (Fraction a, Fraction b);
bool operator!= (Fraction a, Fraction b);
bool operator> (Fraction a, Fraction b);
bool operator< (Fraction a, Fraction b);
bool operator<= (Fraction a, Fraction b);
bool operator>= (Fraction a, Fraction b);
#endif