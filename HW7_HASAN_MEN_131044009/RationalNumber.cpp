/* 
 * File:   RationalNumber.cpp
 * Author: Hasan - 131044009
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Rasyonel sinifinin implementasyonunu icerir
 */

#include <iostream>
#include <cstdlib>

#include "RationalNumber.h"

namespace HMENN {

  using std::ostream;
  using std::endl;
  using std::cin;

  RationalNumber::RationalNumber() : RealNumber() { // imajiner 0
  }

  RationalNumber::RationalNumber(double newReal) : RealNumber(newReal) {
  };

  RationalNumber::RationalNumber(const RationalNumber& object) {
    setAll(object.getNum(), object.getDenom()); //fill num and denom
  }

  RationalNumber::RationalNumber(int _num, int _denom) : RealNumber(_num, _denom) {
  }

  ostream& operator<<(ostream& output, const RationalNumber& object) {
    output << "Real Number : " << object.getNum() << " / " << object.getDenom() << endl;
    return output;
  }

  RationalNumber RationalNumber::operator-() {
    setNum(-getNum()); // negatif yap
    return RationalNumber(getNum(), getDenom());
  }

  RationalNumber operator+(const RationalNumber& first, const RationalNumber& second) {
    return RationalNumber(first.getReal() + first.getReal());
  }

  RationalNumber operator-(const RationalNumber& first, const RationalNumber& second) {
    return RationalNumber(first.getReal() - first.getReal());
  }

  bool operator<(const RationalNumber& first, const RationalNumber& second) {
    return first.getReal() < second.getReal();
  }




}