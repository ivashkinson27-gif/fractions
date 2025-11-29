#include "iostream"
#include "string"
#include "numeric"
using namespace std;


class Rational {
private:
	int64_t num;                   // числитель
	uint64_t denom;                 // знаменатель
	// функция сокращения дроби
	void reduce() {
		if (num != 0 and denom != 0) {
			int64_t nod = gcd(num, denom);
			num /= nod;
			denom /= nod;
		}
		else {
			num = 0;
			denom = 1;
		}
	}
public:
	// Конструирование без аргументов (дробь 0/1)
	Rational() {
		num = 0;
		denom = 1;
	};
	// Конструирование от одного аргумента (дробь numerator/1)
	Rational(int64_t n) {
		num = n;
		denom = 1;
	};
	// Конструирование от двух аргументов (дробь numerator/denomerator)
	Rational(int64_t n, int64_t d) {
		if (d < 0) {
			// если знаменатель отрицательный(домножаем дробь на -1)
			num = -n;
			denom = -d;
		}
		else {
			num = n;
			denom = d;
		}
		reduce();  // сократили дробь
	};
	// возвращает числитель
	int64_t numerator() const {
		return num;
	}
	// возвращает знаменатель
	uint64_t denomerator() const {
		return denom;
	}
	// приведение к double
	double to_double() {
		double result = static_cast<double>(num) / static_cast<double>(denom);
		return result;
	}
	// перевод в строку
	string do_string() {
		return to_string(num) + "/" + to_string(denom);
	}
	// Сложение +
	Rational operator+(const Rational& other) const {
		uint64_t common_denomerator = denom * other.denomerator();
		int64_t new_numerator = num * other.denomerator() + other.numerator() * denom;
		return Rational(new_numerator, common_denomerator);
	}
	// Сложение +=
	Rational& operator+=(const Rational& other) {
		*this = *this + other;
		return *this;
	}
	// Вычитание -
	Rational operator-(const Rational& other) const {
		uint64_t common_denomerator = denom * other.denomerator();
		int64_t new_numerator = num * other.denomerator() - other.numerator() * denom;
		return Rational(new_numerator, common_denomerator);
	}
	// Вычитание -=
	Rational& operator-=(const Rational& other) {
		*this = *this - other;
		return *this;
	}
	// Умножение *
	Rational operator*(const Rational& other) const {
		Rational a(num, denom);
		Rational b(other.numerator(), other.denomerator());
		return Rational(a.numerator() * b.numerator(), a.denomerator() * b.denomerator());
	}
	// Умножение *=
	Rational& operator*=(const Rational& other) {
		*this = *this * other;
		return *this;
	}
	// Деление
	Rational operator/(const Rational& other) {
		int64_t new_numerator = num * other.denomerator();
		uint64_t new_denomenator = denom * other.numerator();
		return Rational(new_numerator, new_denomenator);
	}
	// Деление /=
	Rational& operator/=(const Rational& other) {
		*this = *this / other;
		return *this;
	}
	// Унарный минус
	Rational operator-() const {
		return Rational(-num, denom);
	}
	// Сравнения
	bool operator==(const Rational& other) const {
		return num == other.numerator() and denom == other.denomerator();
	}
	bool operator!=(const Rational& other) const {
		return (1 - (*this == other));
	}
	bool operator<(const Rational& other) const {
		Rational diff = *this - other;
		return diff.numerator() < 0;
	}
	bool operator<=(const Rational& other) const {
		Rational diff = *this - other;
		return diff.numerator() <= 0;
	}
	bool operator>(const Rational& other) const {
		Rational diff = *this - other;
		return diff.numerator() > 0;
	}
	bool operator>=(const Rational& other) const {
		Rational diff = *this - other;
		return diff.numerator() >= 0;
	}
};


int main() {
	setlocale(LC_ALL, "RU");
	Rational n1(2, 4);  // (1/2)
	Rational n2(2, 8);  // (1/4)
	
	cout << "n1: " << n1.do_string() << " | n2: " << n2.do_string() << endl << endl;

	cout << "Числитель: " << n1.numerator() << endl;
	cout << "Знаменатель: " << n1.denomerator() << endl;
	cout << "Приведение к double: " << n1.to_double() << endl;
	cout << "Перевод в строку: " << n1.do_string() << endl;
	Rational yrm = -n1;
	cout << "Унарный минус: " << yrm.do_string() << endl << endl;
	

	Rational sum = n1 + n2;
	cout << "Сложение: " << sum.do_string() << endl;
	Rational diff = n1 - n2;
	cout << "Вычитание: " << diff.do_string() << endl;
	Rational mult = n1 * n2;
	cout << "Произведение: " << mult.do_string() << endl;
	Rational del = n1 / n2;
	cout << "Деление: " << del.do_string() << endl << endl;
	// Сравнения
	cout << n1.do_string() << " == " << n2.do_string() << ": " << (n1 == n2) << endl;
	cout << n1.do_string() << " != " << n2.do_string() << ": " << (n1 != n2) << endl;
	cout << n1.do_string() << " < " << n2.do_string() << ": " << (n1 < n2) << endl;
	cout << n1.do_string() << " <= " << n2.do_string() << ": " << (n1 <= n2) << endl;
	cout << n1.do_string() << " > " << n2.do_string() << ": " << (n1 > n2) << endl;
	cout << n1.do_string() << " >= " << n2.do_string() << ": " << (n1 >= n2) << endl;
	return 0;
}