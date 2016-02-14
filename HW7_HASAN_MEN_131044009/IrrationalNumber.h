/* 
 * File:   IrrationalNumber.h
 * Author: Hasan - 131044009
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:49
 * Bu dosya irrational clasini ornekler
 */

#ifndef IRRATIONALNUMBER_H
#define IRRATIONALNUMBER_H

#include "RealNumber.h"

namespace HMENN {

    class IrrationalNumber : public RealNumber {
    public:
        IrrationalNumber(const IrrationalNumber& object);
        IrrationalNumber(double _rat);

        // gelen sayinin irrastonelligini kontrol eder.
        // gelen ifade matematiksel ifadeler olabilir
        // double cast unutma
        bool isIrrational(double _rat)const;


        friend ostream& operator<<(ostream& output, const IrrationalNumber& object);
        friend bool operator<(const IrrationalNumber& first, const IrrationalNumber& second);
        friend IrrationalNumber operator+(const IrrationalNumber& first, const IrrationalNumber& second);
        friend IrrationalNumber operator-(const IrrationalNumber& first, const IrrationalNumber& second);
    };


}


#endif /* IRRATIONALNUMBER_H */

