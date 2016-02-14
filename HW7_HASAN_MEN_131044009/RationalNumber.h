/* 
 * File:   RationalNumber.h
 * Author: Hasan - 131044009
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:48
 * Rational classi icin header dosyasi
 */

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include "RealNumber.h"

namespace HMENN {

    using std::ostream;

    class RationalNumber : public RealNumber {
    public:
        RationalNumber();
        RationalNumber(const RationalNumber& object);
        RationalNumber(int _num, int _denom);
        RationalNumber(double _real);


        friend ostream& operator<<(ostream& output, const RationalNumber& object);
        RationalNumber operator-();
        friend bool operator<(const RationalNumber& first, const RationalNumber& second);
        friend RationalNumber operator+(const RationalNumber& first, const RationalNumber& second);
        friend RationalNumber operator-(const RationalNumber& first, const RationalNumber& second);
    };
}


#endif /* RATIONALNUMBER_H */

