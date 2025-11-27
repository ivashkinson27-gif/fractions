#pragma once
#include <string>
#include <cstdint>
class drob{
public:
	//int numir;
	//int deter;
	drob();
	drob(int num);
	drob(int num, int det);
	
	int num() const;
	int det() const;
	
	explicit operator double() const; 
    std::string str() const;  
	
	drob operator+() const;  
    drob operator-() const; 
    
    
	drob& operator+=(const drob& other);
    drob& operator-=(const drob& other);
    drob& operator*=(const drob& other);
    drob& operator/=(const drob& other);
    
    friend drob operator+(drob lhs, const drob& rhs);
    friend drob operator-(drob lhs, const drob& rhs);
    friend drob operator*(drob lhs, const drob& rhs);
    friend drob operator/(drob lhs, const drob& rhs);
    
    friend bool operator==(const drob& lhs, const drob& rhs);
    friend bool operator!=(const drob& lhs, const drob& rhs);
    friend bool operator<(const drob& lhs, const drob& rhs);
    friend bool operator>(const drob& lhs, const drob& rhs);
    friend bool operator<=(const drob& lhs, const drob& rhs);
    friend bool operator>=(const drob& lhs, const drob& rhs);
    
    
private:
    int numir_;
    int deter_;

	void sokrashat();
	int gcd(int a, int b);
};
