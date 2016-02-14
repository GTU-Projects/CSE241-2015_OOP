/* 
 * File:   RealNumber.h
 * Author: Hasan - 131044009
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:44
 * Bu dosya real sayilar clasinin prototipini icerir
 */

#ifndef REALNUMBER_H
#define REALNUMBER_H

#include "ComplexNumber.h"


namespace HMENN {

    using std::ostream;

    class RealNumber : public ComplexNumber {
    public:
        RealNumber();
        RealNumber(const RealNumber& object);
        RealNumber(int _num, int _denom);
        RealNumber(double _real);

        // real ve rasyonel sayilarda kullanicalacak yeni eklentiler
        // inheritenceden yararlanilacak

        int getNum()const {
            return m_num;
        }

        int getDenom()const {
            return m_denom;
        }
        void setNum(int _num);
        void setDenom(int _denom);
        void setAll(int _num, int _denom); // num ve denomu assing eder

        friend ostream& operator<<(ostream& output, const RealNumber& object);
        RealNumber operator-();
        friend bool operator<(const RealNumber& first, const RealNumber& second);
        friend RealNumber operator+(const RealNumber& first, const RealNumber& second);
        friend RealNumber operator-(const RealNumber& first, const RealNumber& second);
    protected:
        // double olarak verilen sayiyin num ve denomunu bulup atar
        void convertToNumDenom();
        int m_num; // numerator // real sayinin pay kismi
        int m_denom; // denominator // real sayinin paydasi
    };
}

#endif /* REALNUMBER_H */

