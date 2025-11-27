#include "drob.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>
/////////////////ÇÀÄÀÍÈÅ ×ÈÑËÀ
drob::drob(){
	numir_=0;
	deter_=1;
}

drob::drob(int numir){
	numir_=numir;
	deter_=1;
}

drob::drob(int numir, int deter) {
	if (deter==0){
		deter=1;
	}
	if (deter<0){
		deter=-deter;
		numir=-numir; //Ïåğåâîæó âîçìîæíûé ìèíóñ â çíàìåíàòåëå â ÷èñëèòåëü äëÿ áîëåå óäîáíîé ğàáîòû ñ ÍÎÄ è ÍÎÊ â ïîñëåäñòâèè
	}
	numir_=numir;
	deter_=deter;
	sokrashat();
}

int drob::num() const {
    return numir_;
}
int drob::det() const {
	return deter_;
}
/////////////////////////////////ÏĞÈÂÅÄÅÍÈÅ Â ÄÀÁË,ÑÒĞÈÍÃ È ÓÍÀĞÍÛÅ ÎÏÅĞÀÖÈÈ
drob::operator double() const {
    return static_cast<double>(numir_) / static_cast<double>(deter_);
}

std::string drob::str() const {
    if (deter_ == 1) {
        return std::to_string(numir_);
    }
    return std::to_string(numir_) + "/" + std::to_string(deter_);
}


drob drob::operator+() const {
    return *this;
}
drob drob::operator-() const {
    return drob(-numir_, static_cast<int>(deter_));
}
///////////////////////ÁÈÍÀĞÍÛÅ ÎÏÅĞÀÖÈÈ=============

drob& drob::operator+=(const drob& other) {

    
    int common_deter = deter_ * other.deter_;
    int new_numir = numir_ * static_cast<int>(other.deter_) + 
                           other.numir_ * static_cast<int>(deter_);
    
    numir_ = new_numir;
    deter_ = common_deter;
    sokrashat();
    
    return *this;
}


drob& drob::operator-=(const drob& other) {
    int common_deter = deter_ * other.deter_;
    int new_numir = numir_ * static_cast<int>(other.deter_) - 
                           other.numir_ * static_cast<int>(deter_);
    
    numir_ = new_numir;
    deter_ = common_deter;
    sokrashat();
    
    return *this;
}

drob& drob::operator*=(const drob& other) {
	int common_deter = deter_ * other.deter_;
    int new_numir = numir_ * other.numir_;
    
    numir_ = new_numir;
    deter_ = common_deter;
    sokrashat();
    return *this;
}
drob& drob::operator/=(const drob& other) {
	int common_deter = deter_ * other.numir_;
    int new_numir = numir_ * other.deter_;
    
    numir_ = new_numir;
    deter_ = common_deter;
    sokrashat();
    return *this;
}
////////////////////////ÁÈÍÀĞÍÛÅ ÎÏåĞÀÖÈÈ

drob operator+(drob lhs, const drob& rhs) {
    lhs += rhs;
    return lhs;
}

drob operator-(drob lhs, const drob& rhs) {
    lhs -= rhs;
    return lhs;
}

drob operator*(drob lhs, const drob& rhs) {
    lhs *= rhs;
    return lhs;
}

drob operator/(drob lhs, const drob& rhs) {
    lhs /= rhs;
    return lhs;
}
////////////////////////////////////// ÑĞÀÂÍÅÍÈß
bool operator==(const drob& lhs, const drob& rhs) {
    return lhs.numir_ == rhs.numir_ && lhs.deter_ == rhs.deter_;
}
bool operator!=(const drob& lhs, const drob& rhs) {
    return !(lhs == rhs);
}
bool operator<(const drob& lhs, const drob& rhs) {
    return (lhs.numir_ * static_cast<int>(rhs.deter_)) < (rhs.numir_ * static_cast<int>(lhs.deter_));
}

bool operator>(const drob& lhs, const drob& rhs) {
    return (lhs.numir_ * static_cast<int>(rhs.deter_)) > (rhs.numir_ * static_cast<int>(lhs.deter_));
}
bool operator>=(const drob& lhs, const drob& rhs) {
    return (lhs > rhs) || (lhs == rhs);
}
bool operator<=(const drob& lhs, const drob& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}




/////////////////////////////////////////////// ÍÅ ÒĞÎÃÀÒÜ ×ÒÎ ĞÀÁÎÒÀÅÒ
int drob::gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void drob::sokrashat() {
    if (numir_ == 0) {
        deter_ = 1;
        return;
    }
    int abs_numir = static_cast<int>(std::abs(numir_));
    int common_divisor = gcd(abs_numir, deter_);

    numir_ /= static_cast<int>(common_divisor);
    deter_ /= common_divisor;
}
//////////////


int main() {
	drob yo(25,5);
	drob x(1, 2), y(2, 4), z(1, 3);
	//yo*=drob(4, 2);
	//std::cout
	//yo/=drob(4,2);
	std::cout<< double(x);
	//std::cout<< yo.det();
	
	
}

