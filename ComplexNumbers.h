#pragma once

#include <iostream>

class ComplexNumber {
private:
	double re;
	double im;
public:
	ComplexNumber();
	ComplexNumber(double newRe, double newIm);

	double getRe();
	double getIm();

	ComplexNumber operator+(const ComplexNumber&);
	ComplexNumber operator-(const ComplexNumber&);
	ComplexNumber operator*(const ComplexNumber&);
	ComplexNumber operator/(const ComplexNumber&);
	ComplexNumber& operator=(const ComplexNumber&);

	friend std::ostream& operator<< (std::ostream& out, const ComplexNumber& number);
	friend std::istream& operator>> (std::istream& in, ComplexNumber& number);

};
ComplexNumber::ComplexNumber() :re(0), im(0) {}
ComplexNumber::ComplexNumber(double newRe, double newIm = 0) : re(newRe), im(newIm) {}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& object) {
	return ComplexNumber(re + object.re, im + object.im);
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& object) {
	return ComplexNumber(re - object.re, im - object.im);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& object) {
	return ComplexNumber(re * object.re - im * object.im, re * object.im + object.re * im);
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& object) {
	return ComplexNumber(re * object.re + im * object.im, re * object.im - object.re * im);
}
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& object) {
	re = object.re;
	im = object.im;
	return *this;
}
double ComplexNumber::getRe() {
	return re;
}
double ComplexNumber::getIm() {
	return im;
}
std::ostream& operator<< (std::ostream& out, const ComplexNumber& number)
{
	out << number.re << " + " << number.im << "i" << std::endl;
	return out;
}
std::istream& operator>> (std::istream& in, ComplexNumber& number)
{
	in >> number.re;
	in >> number.im;
	return in;
}
