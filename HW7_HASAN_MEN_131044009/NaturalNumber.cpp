/* 
 * File:   NaturalNumber.cpp
 * Author: Hasan - 131044009
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Dogal sayilar sinifinin implementasyonunu icerir
 */
#include <iostream>
#include <cstdlib>
#include "NaturalNumber.h"

namespace HMENN {

  using std::ostream;
  using std::cout;
  using std::endl;
  using std::cin;

  NaturalNumber::NaturalNumber() : IntegerNumber() { // imajiner 0
  }

  NaturalNumber::NaturalNumber(const NaturalNumber& object) : IntegerNumber(object) {
  }

  // 0dan kucukse 0 ata

  NaturalNumber::NaturalNumber(int _num) : IntegerNumber(_num) {
    if (_num >= 0)
      setAll(_num, 0.0);
    else setAll(0.0, 0.0);
  }

  ostream& operator<<(ostream& output, const NaturalNumber& object) {
    output << "Natural Number : " << object.getNum() << endl;
    return output;
  }

  NaturalNumber NaturalNumber::operator-() {
    cout << "You can not assign a negative to natural number." << endl;
    return NaturalNumber(getNum());
  }

  NaturalNumber operator+(const NaturalNumber& first, const NaturalNumber& second) {
    return NaturalNumber(first.getNum() + second.getNum());
  }

  NaturalNumber operator-(const NaturalNumber& first, const NaturalNumber& second) {
    return NaturalNumber(first.getNum() - second.getNum());
  }

  bool operator<(const NaturalNumber& first, const NaturalNumber& second) {
    return first.getNum() < second.getNum();
  }



}