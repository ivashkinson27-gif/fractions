#include <iostream>
#include "header.h"
using namespace std;

int main() {
    Fraction a(1, 2);
    Fraction b(10);
    Fraction c(4, -2);
    Fraction d;

    cout << "a = " << a.str() << endl;
    cout << "b = " << b.str() << endl;
    cout << "c = " << c.str() << endl;
    cout << "d = " << d.str() << endl;

    cout << "numerator a = " << a.numerator() << endl;
    cout << "denominator a = " << a.denominator() << endl;

    double value = static_cast<double>(a);
    cout << "a as double = " << value << endl;

    Fraction e = a + b;
    Fraction f = c - b;
    Fraction g = a * b;
    Fraction h = b / c;

    cout << "a + b = " << e.str() << endl;
    cout << "c - b = " << f.str() << endl;
    cout << "a * b = " << g.str() << endl;
    cout << "b / c = " << h.str() << endl;

    Fraction i_1(1, 2);
    Fraction i_2(1, 2);
    i_1 += Fraction(1, 3);
    i_2 *= Fraction(-2);
    cout << "1/2 + 1/3 = " << i_1.str() << endl;
    cout << "1/2 * (-2) = " << i_2.str() << endl;

    Fraction j = -c;
    cout << "-c = " << j.str() << endl;

    cout << "a == d: " << (a == d) << endl;
    cout << "b != c: " << (b != c) << endl;
    cout << "c < a: " << (c < a) << endl;

    return 0;
}