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
private:
    void Reduction();
}
#endif