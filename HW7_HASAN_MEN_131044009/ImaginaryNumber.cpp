/* 
 * File:   Imaginary.cpp
 * Author: Hasan - 131044009
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Imajiner sinifinin implementasyonunu icerir
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "ImaginaryNumber.h"

namespace HMENN {

  using std::ostream;
  using std::endl;
  using std::cin;

  // based class constructoru cagirildi

  ImaginaryNumber::ImaginaryNumber() : ComplexNumber(0.0, 1.0) { // imajiner 0
  }

  ImaginaryNumber::ImaginaryNumber(const ImaginaryNumber& object) : ComplexNumber(object) {
  }

  ImaginaryNumber::ImaginaryNumber(double imag) {
    setAll(0.0, imag);
  }

  ostream& operator<<(ostream& output, const ImaginaryNumber& object) {
    output << "Imaginary Number : "
            << object.getImag()
            << " i " << endl;
    return output;
  }

  ImaginaryNumber ImaginaryNumber::operator-() {
    setImag(-getImag());
    return ImaginaryNumber(getImag());
  }

  ImaginaryNumber operator+(const ImaginaryNumber& first, const ImaginaryNumber& second) {
    return ImaginaryNumber(first.getImag() + second.getImag());
  }

  ImaginaryNumber operator-(const ImaginaryNumber& first, const ImaginaryNumber& second) {
    return ImaginaryNumber(first.getImag() - second.getImag());
  }

  bool operator<(const ImaginaryNumber& first, const ImaginaryNumber& second) {
    // orijin uzakligina gore karsilastir
    return pow(first.getImag(), 2) < pow(second.getImag(), 2);
  }
}