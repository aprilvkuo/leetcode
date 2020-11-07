//
// Created by April Kuo on 2020/10/21.
//

#include "data.h"



Complex Complex::operator+(const Complex& c2)
{
	Complex c;
	c.real = real + c2.real;
	c.imag = imag + c2.imag;
	return c;
}
Complex Complex::operator-(const Complex& c2)
{
	Complex c;
	c.imag = imag - c2.imag;
	return c;
}
Complex Complex::operator*(const Complex& c2)
{
	Complex c;
	c.imag = imag * c2.imag;
	return c;
}
Complex Complex::operator/(const Complex& c2)
{
	Complex c;
	c.imag = imag / c2.imag;
	return c;
}
void Complex::display()
{
	cout << "(" << real << "," << imag << "i)" << endl;
}



void Real::display()
{
	cout << real << endl;
}
Real Real::operator+(const Real& c2)
{
	Real c;
	c.real = real + c2.real;
	return c;
}
Real Real::operator-(const Real& c2)
{
	Real c;
	c.real = real - c2.real;
	return c;
}
Real Real::operator*(const Real& c2)
{
	Real c;
	c.real = real * c2.real;
	return c;
}
Real Real::operator/(const Real& c2)
{
	Real c;
	c.real = real / c2.real;
	return c;
}