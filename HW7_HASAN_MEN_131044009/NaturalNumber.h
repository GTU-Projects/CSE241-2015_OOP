/* 
 * File:   NaturalNumber.h
 * Author: Hasan
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:52
 * Bu dosya dogal sayilar kumesi icin class prototipleri icerir
 */

#ifndef NATURALNUMBER_H
#define NATURALNUMBER_H

#include "IntegerNumber.h"

namespace HMENN {

    using std::ostream;

    class NaturalNumber : public IntegerNumber {
    public:
        NaturalNumber();
        NaturalNumber(const NaturalNumber& object);
        NaturalNumber(int _num);

        // operator overloadlar
        friend ostream& operator<<(ostream& output, const NaturalNumber& object);
        NaturalNumber operator-();
        friend bool operator<(const NaturalNumber& first, const NaturalNumber& second);
        friend NaturalNumber operator+(const NaturalNumber& first, const NaturalNumber& second);
        friend NaturalNumber operator-(const NaturalNumber& first, const NaturalNumber& second);
    };
}


#endif /* NATURALNUMBER_H */

