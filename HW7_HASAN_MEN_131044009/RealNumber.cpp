/* 
 * File:   RealNumber.cpp
 * Author: Hasan - 131044009
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Reel sayilar sinifinin implementasyonunu icerir
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "RealNumber.h"

namespace HMENN {

  using std::ostream;
  using std::endl;
  using std::cin;

  RealNumber::RealNumber() : ComplexNumber(1.0, 0.0) { // imajiner 0
    setAll(1, 1);
  }

  RealNumber::RealNumber(const RealNumber& object) : ComplexNumber(object) {
    RealNumber::setAll(object.getNum(), object.getDenom());
  }

  RealNumber::RealNumber(double _real) {
    ComplexNumber::setAll(_real, 0.0);
    convertToNumDenom(); // ComplexNumber constructor cagirdim diyebiliriz
    //daha sonrada kullanilacak ilk gosterim
    // bundan sonrası num ve denom uzerine oldugu icin onemli
  }

  RealNumber::RealNumber(int _num, int _denom) {
    ComplexNumber::setAll(static_cast<double> (_num) / _denom, 0);
    setAll(_num, _denom); // override
  }

  ostream& operator<<(ostream& output, const RealNumber& object) {
    output << "Real Number : " << object.getReal() << " == "
            << object.getNum() << " / " << object.getDenom() << endl;
    return output;
  }

  RealNumber RealNumber::operator-() {
    setReal(-getReal());
    return RealNumber(getReal());
  }

  RealNumber operator+(const RealNumber& first, const RealNumber& second) {
    return RealNumber(first.getReal() + second.getReal());
  }

  RealNumber operator-(const RealNumber& first, const RealNumber& second) {
    return RealNumber(first.getReal() - second.getReal());
  }

  bool operator<(const RealNumber& first, const RealNumber& second) {
    return first.getReal() < second.getReal();
  }

  void RealNumber::convertToNumDenom() {
    int i = 0;
    double temp = getReal();
    // virgul sonrasi 0 olana kadar 
    while (temp - int(temp) != 0) {
      temp *= 10;
      ++i;
    }
    setAll(temp, static_cast<int> (pow(10, i))); // num ve denom u ilklendir
  }

  void RealNumber::setAll(int _num, int _denom) {
    setNum(_num);
    setDenom(_denom);
  }

  void RealNumber::setNum(int _num) {
    m_num = _num;
  }

  void RealNumber::setDenom(int _denom) {
    m_denom = _denom;
  }
}