/* 
 * File:   ImaginaryNumber.h
 * Author: Hasan - 131044009
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:47
 * Bu dosya Imajiner clasi icin prototipleri icerir.Imaginer turemis bir siniftir
 */

#ifndef IMAGINARYNUMBER_H
#define IMAGINARYNUMBER_H

#include "ComplexNumber.h"


namespace HMENN {

    using std::ostream;

    class ImaginaryNumber : public ComplexNumber {
    public:
        ImaginaryNumber();
        ImaginaryNumber(const ImaginaryNumber& object);
        ImaginaryNumber(double _imag);

        // operator overloads
        friend ostream& operator<<(ostream& output, const ImaginaryNumber& object);
        ImaginaryNumber operator-();
        friend bool operator<(const ImaginaryNumber& first, const ImaginaryNumber& second);
        friend ImaginaryNumber operator+(const ImaginaryNumber& first, const ImaginaryNumber& second);
        friend ImaginaryNumber operator-(const ImaginaryNumber& first, const ImaginaryNumber& second);
    };
}


#endif /* IMAGINARYNUMBER_H */

