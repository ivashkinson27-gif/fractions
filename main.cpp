#include <iostream>
#include "rational.h"

int main() {
    Rational a(5, 9);
    Rational b(8, 18);

    Rational c = a + b;
    Rational g = a - b;
    Rational d = a * b;
    Rational e = a / b;

    std::cout << "a = " << a.str() << "\n";
    std::cout << "b = " << b.str() << "\n";
    std::cout << "a + b = " << c.str() << "\n";
    std::cout << "a - b = " << g.str() << "\n";
    std::cout << "a * b = " << d.str() << "\n";
    std::cout << "a / b = " << e.str() << "\n";
    
    std::cout << "double(a) = " << double(a) << "\n";
    
    std::cout << std::boolalpha;
    std::cout << "a < b = " << (a < b) << "\n";
    std::cout << "a <= a = " << (a <= b) << "\n";
    std::cout << "a > b = " << (a > b) << "\n";
    std::cout << "a >= b = " << (a >= b) << "\n";
    std::cout << "a == b = " << (a == b) << "\n";
    std::cout << "a != b = " << (a != b) << "\n";

    return 0;
}