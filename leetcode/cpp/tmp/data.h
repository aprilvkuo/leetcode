//
// Created by April Kuo on 2020/10/21.
//

#ifndef LEETCODE_DATA_H
#define LEETCODE_DATA_H

#include <iostream>
using namespace std;


class Real         //实数类
{
public:
	Real() {};
	Real(double r) { real = r; }
	void display();
	Real operator+(const Real& c2);
	Real operator-(const Real& c2);
	Real operator*(const Real& c2);
	Real operator/(const Real& c2);

private:
	double real;
};



class Complex :public Real           //复数类
{
public:
	Complex() {};
	Complex(double r, double i) { real = r; imag = i; }
	void display();
	Complex operator+(const Complex& c2);
	Complex operator-(const Complex& c2);
	Complex operator*(const Complex& c2);
	Complex operator/(const Complex& c2);
private:
	double real;
	double imag;
};






#endif //LEETCODE_DATA_H
