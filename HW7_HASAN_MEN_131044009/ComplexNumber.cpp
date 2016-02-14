/* 
 * File:   ComplexNumber.cpp
 * Author: Hasan
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Complex sinifinin implementasyonunu icerir
 */

#include <iostream>
#include <cstdlib>
#include <cmath> // pow
#include "ComplexNumber.h"

namespace HMENN {

  using std::ostream;
  using std::endl;
  using std::cout;
  using std::cin;

  // default olarak 1+1i

  ComplexNumber::ComplexNumber() : m_real(1.0), m_imag(1.0) {
  }

  // copy contructor
  // friend fonksiyonlarda bolca kullanilacak

  ComplexNumber::ComplexNumber(const ComplexNumber& orig) {
    setAll(orig.getReal(), orig.m_imag);
  }

  ComplexNumber::ComplexNumber(double newReal, double newImag) {
    setAll(newReal, newImag);
  }

  void ComplexNumber::setAll(double _real, double _imag) {
    setReal(_real);
    setImag(_imag);
  }

  void ComplexNumber::setReal(double _real) {
    m_real = _real;
  }

  void ComplexNumber::setImag(double _imag) {
    m_imag = _imag;
  }

  ostream& operator<<(ostream& output, const ComplexNumber& object) {
    output << "Complex Number : "
            << object.getReal()
            << " ( + ) "
            << object.getImag()
            << " i" << endl;
    return output;
  }

  // sayiyin negatifini alir ve kopyasini return eder

  ComplexNumber ComplexNumber::operator-() {
    setReal(-getReal());
    setImag(-getImag());
    return ComplexNumber(getReal(), getImag());
  }

  // iki komplexi yada derived edilen classlari toplar

  ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second) {
    return ComplexNumber(first.getReal() + second.getReal(),
            first.getImag() + second.getImag());
  }

  // complex turundeki objecleri cikarir

  ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second) {
    return ComplexNumber(first.getReal() - second.getReal(),
            first.getImag() - second.getImag());
  }

  // kucukluk kontrolu
  // orjine uzaklik baz alindi

  bool operator<(const ComplexNumber& first, const ComplexNumber& second) {
    return sqrt(pow(first.getReal(), 2) + pow(first.getImag(), 2))
            < sqrt(pow(second.getReal(), 2) + pow(second.getImag(), 2));
  }
}