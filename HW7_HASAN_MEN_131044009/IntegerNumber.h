/* 
 * File:   IntegerNumber.h
 * Author: Hasan - 131044009
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:50
 * Bu dosya turemis integer sinifi icin prototipleri icerir
 */

#ifndef INTEGERNUMBER_H
#define INTEGERNUMBER_H


#include "RationalNumber.h"


namespace HMENN {

    using std::ostream;

    class IntegerNumber : public RationalNumber {
    public:
        IntegerNumber();
        IntegerNumber(const IntegerNumber& object);
        IntegerNumber(int _num);

        // operator overloadlar
        friend ostream& operator<<(ostream& output, const IntegerNumber& object);
        IntegerNumber operator-();
        friend bool operator<(const IntegerNumber& first, const IntegerNumber& second);
        friend IntegerNumber operator+(const IntegerNumber& first, const IntegerNumber& second);
        friend IntegerNumber operator-(const IntegerNumber& first, const IntegerNumber& second);
    };
}





#endif /* INTEGERNUMBER_H */

