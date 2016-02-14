/* 
 * File:   IrrationalNumber.cpp
 * Author: Hasan - 131044009
 * 
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Irratioan sinifinin implementasyonunu icerir
 */
#include <iostream>
#include "IrrationalNumber.h"
#include <cstdlib>
#include <cmath>

namespace HMENN {

  using std::cout;
  using std::endl;

  // base class contructor initializer

  IrrationalNumber::IrrationalNumber(const IrrationalNumber& object) {
    ComplexNumber::setAll(object.getReal(), 0);
  }

  // irrasyonel degilse uyari ver

  IrrationalNumber::IrrationalNumber(double _rat) {
    if (isIrrational(_rat))
      ComplexNumber::setAll(_rat, 0);
    else
      cout << _rat << " is not a irrational. Create new object." << endl;
  }

  //   irrasyonellik kontrolu yapar
  // virgulden sonra 15 basamaktan fazla varsa irrasyoneldir

  bool IrrationalNumber::isIrrational(double _rat) const {

    int i = 0;

    // virgulden sonraki kisim
    while (_rat - static_cast<int> (_rat) != 0) {
      _rat *= 10;
      ++i;
      if (i >= 14)
        return true;
    }
    return false;
  }

  ostream& operator<<(ostream& output, const IrrationalNumber& object) {

    cout << "Irrational :" << object.getReal() << endl;
    return output;
  }

  bool operator<(const IrrationalNumber& first, const IrrationalNumber& second) {
    return first.getReal() < second.getReal();
  }

  // TOPLAMA VE CIKARMA ISLEMLERI ATLANDI

  IrrationalNumber operator+(const IrrationalNumber& first, const IrrationalNumber& second) {
    cout << "This operation too dangerous!!!" << endl;
    return IrrationalNumber(static_cast<double> (1) / 3);
  }

  IrrationalNumber operator-(const IrrationalNumber& first, const IrrationalNumber& second) {
    cout << "This operation too dangerous!!!" << endl;
    return IrrationalNumber(static_cast<double> (1) / 3);
  }
}
