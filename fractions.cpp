#include <iostream>
#include <string>

using std::cout, std::string, std::to_string;

int GCD(int a, int b){
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
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
    Fraction(int numerator_, int denominator_): numerator(numerator_),  denominator(denominator_) {Reduction();}
    int GetNumerator() {return numerator;}
    int GetDenominator() {return denominator;}
    operator double() const {
        return (double)numerator / double(denominator);
    }
    friend string str(const Fraction& f);
    friend std::ostream & operator <<(std::ostream & os, Fraction const & n);
    Fraction& operator+= (const Fraction& other){
        int m = LCM(denominator, other.denominator);
        numerator = numerator * (m / denominator) + other.numerator * (m / other.denominator);
        denominator = m;
        Reduction();
        return *this;
    }
    Fraction& operator-= (const Fraction& other){
        int m = LCM(denominator, other.denominator);
        numerator = numerator * (m / denominator) - other.numerator * (m / other.denominator);
        denominator = m;
        Reduction();
        return *this;
    }
    Fraction& operator*= (const Fraction& other){
        numerator *= other.numerator;
        denominator *= other.denominator;
        Reduction();
        return *this;
    }
    Fraction& operator/= (const Fraction& other){
        numerator *= other.denominator;
        denominator *= other.numerator;
        Reduction();
        return *this;
    }
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }
    friend Fraction operator+ (Fraction a, Fraction const b);
    friend Fraction operator* (Fraction a, Fraction const b);
    friend Fraction operator/ (Fraction a, Fraction const b);
    friend Fraction operator- (Fraction a, Fraction const b);
    ~Fraction() {}
    Fraction(const Fraction& f): numerator(f.numerator), denominator(f.denominator) {}
private:
    void Reduction(){
        int d = GCD(numerator, denominator);
        numerator /= d;
        denominator /= d;
    }
    
};

string str(Fraction const & f){
    return to_string(f.numerator) + '\\' + to_string(f.denominator);
}
std::ostream& operator<<(std::ostream & os, Fraction const & n){
    os << str(n);
    return os;
}

Fraction operator+ (Fraction a, Fraction const b){
    return a += b;
}

Fraction operator* (Fraction a, Fraction const b){
    return a *= b;
}
Fraction operator/ (Fraction a, Fraction const b){
    return a /= b;
}
Fraction operator- (Fraction a, Fraction const b){
    return a -= b;
}
bool operator==(Fraction a, Fraction b){
    int m = LCM(a.GetDenominator(), b.GetDenominator());
    int n1 = a.GetNumerator() * (m / a.GetDenominator());
    int n2 = b.GetNumerator() * (m / b.GetDenominator());
    return n1 == n2;
}
bool operator!=(Fraction a, Fraction b){
    int m = LCM(a.GetDenominator(), b.GetDenominator());
    int n1 = a.GetNumerator() * (m / a.GetDenominator());
    int n2 = b.GetNumerator() * (m / b.GetDenominator());
    return n1 != n2;
}
bool operator>(Fraction a, Fraction b){
    int m = LCM(a.GetDenominator(), b.GetDenominator());
    int n1 = a.GetNumerator() * (m / a.GetDenominator());
    int n2 = b.GetNumerator() * (m / b.GetDenominator());
    return n1 > n2;
}
bool operator<(Fraction a, Fraction b){
    int m = LCM(a.GetDenominator(), b.GetDenominator());
    int n1 = a.GetNumerator() * (m / a.GetDenominator());
    int n2 = b.GetNumerator() * (m / b.GetDenominator());
    return n1 < n2;
}
bool operator<=(Fraction a, Fraction b){
    int m = LCM(a.GetDenominator(), b.GetDenominator());
    int n1 = a.GetNumerator() * (m / a.GetDenominator());
    int n2 = b.GetNumerator() * (m / b.GetDenominator());
    return n1 <= n2;
}
bool operator>=(Fraction a, Fraction b){
    int m = LCM(a.GetDenominator(), b.GetDenominator());
    int n1 = a.GetNumerator() * (m / a.GetDenominator());
    int n2 = b.GetNumerator() * (m / b.GetDenominator());
    return n1 >= n2;
}
int main(){
    {
    cout << GCD(4, 5) << '\n';
    cout << LCM(5, 4) << '\n';
    Fraction a(5, 5);
    double b = (double)a + 1.0;
    cout << b << '\n';
    cout << str(a) << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        a += b;
        cout << a << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        a *= b;
        cout << a << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        a -= b;
        cout << a << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        a /= b;
        cout << a << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        cout << a + b << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        cout << a * b << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        cout << a / b << '\n';
    }
    {
        Fraction a(5, 7);
        Fraction b(4, 3);
        cout << a - b << '\n';
    }
    {
        Fraction a(1, 2);
        cout << -a << '\n';
    }
    {
        Fraction a(1, 3);
        Fraction b(1, 3);
        Fraction c (2, 3);
        cout << (a == b) << '\n';
        cout << (a == c) << '\n';
        cout << (a > c) << '\n';
        cout << (a < c) << '\n';
    }
    return 0;
}