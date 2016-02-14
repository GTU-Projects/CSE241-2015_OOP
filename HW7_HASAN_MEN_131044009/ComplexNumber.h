/* 
 * File:   ComplexNumber.h
 * Author: Hasan _ 131044009
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * Bu dosya complex base classinin prototipini icerir
 */

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H


namespace HMENN {

    using std::ostream;

    class ComplexNumber {
    public:
        ComplexNumber();
        ComplexNumber(double a, double b);
        ComplexNumber(const ComplexNumber& orig);

        // GETTERS

        double getReal()const {
            return m_real;
        }

        double getImag()const {
            return m_imag;
        }

        // SETTERS
        void setReal(double _num);
        void setImag(double _num);
        void setAll(double _real, double _imag);

        //Stream insertion
        friend ostream& operator<<(ostream& output, const ComplexNumber& object);


        // toplama cikarma kucuk ve unary minus operator overloadlari
        ComplexNumber operator-();
        friend bool operator<(const ComplexNumber& first, const ComplexNumber& second);
        friend ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second);
        friend ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second);
    protected:
        double m_real;
        double m_imag;
    };

}// HMENN namespace

#endif /* COMPLEXNUMBER_H */

