/* 
 * File:   IntegerNumber.cpp
 * Author: Hasan - 131044009
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Integer sinifinin implementasyonunu icerir
 */
#include <iostream>
#include <cstdlib>
#include "IntegerNumber.h"

namespace HMENN {

  using std::ostream;
  using std::endl;
  using std::cin;

  // constructorlar base classlardan faydalandi

  IntegerNumber::IntegerNumber() : RationalNumber() { // imajiner 0
  }

  IntegerNumber::IntegerNumber(const IntegerNumber& object) : RationalNumber(object) {
  }

  IntegerNumber::IntegerNumber(int _num) : RationalNumber(_num, 0) {
  };

  ostream& operator<<(ostream& output, const IntegerNumber& object) {
    output << "Integer Number : " << object.getNum() << endl;
    return output;
  }

  IntegerNumber IntegerNumber::operator-() {
    setNum(-getNum());
    return IntegerNumber(getNum());
  }

  IntegerNumber operator+(const IntegerNumber& first, const IntegerNumber& second) {
    return IntegerNumber(first.getNum() + second.getNum());
  }

  IntegerNumber operator-(const IntegerNumber& first, const IntegerNumber& second) {
    return IntegerNumber(first.getNum() - second.getNum());
  }

  bool operator<(const IntegerNumber& first, const IntegerNumber& second) {
    return first.getNum() < second.getDenom();
  }




}