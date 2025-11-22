#include <iostream>

int GCD(int a, int b){
    while (a != 0 && b != 0){
        if (b > a)
            b %= a;
        else
            a %= b;
    }
    return a + b;
}

int LCM(int a, int b){
    int d = GCD(a, b);
    return a * b / d;
}

class Fraction{
    int numerator;
    int denominator;
public:
    Fraction(): numerator(1), denominator(1) {}
    Fraction(int number): numerator(number), denominator(1) {}
    Fraction(int numerator_, int denominator_): numerator(numerator_),  denominator(denominator_) {reduction();}
    int GetNumerator() {return numerator;}
    int GetDenominator() {return denominator;}
private:
    void Reduction(){
        int d = GCD(numerator, denominator);
        numerator %= d;
        denominator %= d;
    }

};



using std::cout;
int main(){
    cout << GCD(4, 5) << '\n';
    cout << LCM(5, 4) << '\n';
    return 0;
}