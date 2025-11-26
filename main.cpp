#include <iostream>
#include "fraction.h"


int main() {
    using std::cout;
    using std::endl;

    Fraction a;                
    Fraction b(5);
    Fraction c(6, -8);         

    cout << "a = " << a.str() << endl;
    cout << "b = " << b.str() << endl;
    cout << "c = " << c.str() << endl;

    Fraction x(1, 2);
    Fraction y(1, 3);

    cout << "x = " << x.str() << endl;
    cout << "y = " << y.str() << endl;
    cout << "x + y = " << (x + y).str() << endl;
    cout << "x - y = " << (x - y).str() << endl;
    cout << "x * y = " << (x * y).str() << endl;
    cout << "x / y = " << (x / y).str() << endl;
    Fraction p(2, 5);
    Fraction q(3, 7);

    cout << "p = " << p.str() << endl;
    cout << "q = " << q.str() << endl;

    Fraction t = p;
    t += q;
    cout << "p += q -> " << t.str() << endl;

    t = p;
    t -= q;
    cout << "p -= q -> " << t.str() << endl;

    t = p;
    t *= q;
    cout << "p *= q -> " << t.str() << endl;

    t = p;
    t /= q;
    cout << "p /= q -> " << t.str() << endl;
    cout << "-x = " << (-x).str() << endl;
    cout << "x = " << x.str() << " , y = " << y.str() << endl;
    cout << "x == y " << (x == y) << endl;
    cout << "x != y " << (x != y) << endl;
    cout << "x < y " << (x < y) << endl;
    cout << "x > y " << (x > y) << endl;
    cout << "x <= y " << (x <= y) << endl;
    cout << "x >= y " << (x >= y) << endl;

    Fraction d(7, 4);
    cout << "d = " << d.str() << " = " << static_cast<double>(d) << endl;
}