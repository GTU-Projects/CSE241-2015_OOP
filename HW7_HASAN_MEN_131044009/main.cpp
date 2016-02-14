/* 
 * File:   main.cpp
 * Author: Hasan
 *
 * Created on 14 Aralık 2015 Pazartesi, 18:42
 * TEST DRIVER
 */

#include <cstdlib>
#include <iostream>
#include "ComplexNumber.h"
#include "ImaginaryNumber.h"
#include "IntegerNumber.h"
#include "IrrationalNumber.h"
#include "NaturalNumber.h"
#include "RationalNumber.h"
#include "RealNumber.h"
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

  using namespace HMENN;


  cout << endl << "Test For Complex Numbers :" << endl
          << "--------------------------" << endl;
  ComplexNumber c1, c2(14, 0), c3(18.2, 5), c4(0, -5);
  cout << "C1." << c1 << "C2." << c2 << "C3." << c3 << "C4." << c4 << endl;
  cout << "C1 - C2 :" << c1 - c2;
  cout << "-C2 :" << (-c2);
  cout << "C3 - C4 :" << c3 - c4;
  cout << "C4 + C3 :" << c4 + c3;
  cout << "C1 + C4 :" << c4 + c1;
  cout << "C1 + C4 - C3:" << c4 + c1 - c2;
  cout << "C2 < C3 :" << (c2 < c3) << endl;
  cout << "C4 < C1 :" << (c4 < c1) << endl;
  cout << "C4 < C3 :" << (c4 < c3) << endl;

  cout << endl << "Test For Real Numbers :" << endl
          << "-----------------------" << endl;
  RealNumber r1, r2(15), r3(-9), r4(2.59), r5(-7.5), r6(r2);
  cout << "R1." << r1 << "R2." << r2 << "R3." << r3 << "R4." << r4 << "R5." << r5 << "R6." << r6 << endl;
  cout << "-R6 :" << -r6;
  cout << "R1 - R2 :" << r1 - r2;
  cout << "R3 - R5 :" << r3 - r5;
  cout << "R4 + R3 :" << r4 + r3;
  cout << "R1 + R3 :" << r1 + r3;
  cout << "R4 < R3 :" << (r4 < r3) << endl;
  cout << "R5 < R4 :" << (r5 < r4) << endl;

  cout << endl << "Test For Imaginary Numbers :" << endl
          << "----------------------------" << endl;
  ImaginaryNumber i1, i2(32.9), i3(-9), i4(i2);
  cout << "I1." << i1 << "I2." << i2 << "I3." << i3 << "I4." << i4 << endl;
  cout << "-I4." << -i4;
  cout << "-I3." << -i3;
  cout << "I1 + I2 :" << (i1 + i2);
  cout << "I2 + I3 :" << (i2 + i3);
  cout << "I1 + I3 :" << (i1 + i3);
  cout << "I1 - I3 :" << (i1 - i3);
  cout << "I1 < I3 :" << (i1 < i3) << endl;
  cout << "I3 < I1 :" << (i3 < i1) << endl;
  cout << "I2 < I4 :" << (i2 < i4) << endl;

  cout << "Test for Rational Numbers :" << endl
          << "---------------------------" << endl;
  RationalNumber ra1, ra2(3, 7), ra3(0, 9), ra4(-ra2), ra5(12);
  cout << "RA1." << ra1 << "RA2." << ra2 << "RA3." << ra3 << "RA4." << ra4 << "RA5." << ra5;
  cout << "-RA1 :" << -ra1;
  cout << "-RA5 :" << -ra5;
  cout << "RA1 + RA4 :" << (ra1 + ra4);
  cout << "RA3 + RA2 :" << (ra3 + ra2);
  cout << "RA2 - RA3 :" << (ra2 - ra3);
  cout << "RA1 < RA5 :" << (ra1 < ra5) << endl;
  cout << "RA2 < RA3 :" << (ra2 < ra3) << endl;

  cout << endl << "Test for Integer Numbers :" << endl
          << "--------------------------" << endl;
  IntegerNumber in1, in2(5), in3(-8), in4(-1), in5(in2);
  cout << "In1." << in1 << "In2." << in2 << "In3." << in3 << "In4." << in4 << "In5." << in5;
  cout << "-In1 :" << -in1;
  cout << "In1 + In2 :" << in1 + in2;
  cout << "In3 + In5 :" << in3 + in5;
  cout << "In4 + In1 :" << in1 + in4;
  cout << "In4 - In3 :" << in4 - in3;
  cout << "In5 - In1 :" << in5 - in1;
  cout << "In3 < In4 :" << (in3 < in4) << endl;
  cout << "In1 < In5 :" << (in1 < in5) << endl;
  cout << "In4 < In3 :" << (in4 < in3) << endl;

  cout << endl << "Test for Natural Numbers :" << endl
          << "--------------------------" << endl;
  NaturalNumber n1, n2(13), n3(-4), n4(n2);
  cout << "N1." << n1 << "N2." << n2 << "N3." << n3 << "N4." << n4;
  cout << "-N1 :" << -n1;
  cout << "N1 + N2 :" << n1 + n2;
  cout << "N3 + N4 :" << n3 + n4;
  cout << "N2 - N1 :" << n2 - n1;
  cout << "N3 - N1 :" << n3 - n1;
  cout << "N1 < N2 :" << (n1 < n2) << endl;
  cout << "N2 < N3 :" << (n2 < n3) << endl;

  cout << endl << "Test for Irrational Numbers :" << endl
          << "-----------------------------" << endl;
  IrrationalNumber ir1(1.0 / 3), ir2(sqrt(2)), ir3(3.0 / 9), ir4(1);
  cout << "IR1 :" << ir1 << "IR2 :" << ir2 << "IR3 :" << ir3 << "IR4 :" << ir4;
  cout << " IR1 + IR2 " << ir1 + ir2;

  cout << endl << "END OF FIRST TESTS" << endl;
  cout << endl << "------------------" << endl;
  cout << endl << endl << "Lets try some comlex situations." << endl;

  cout << "Complex(C2) + Integer(In1) :";
  ComplexNumber newC = c2 + in1;
  cout << newC;

  cout << "Complex(C3) + Real(R3) :";
  newC = c3 + r3;
  cout << newC;

  cout << "Complex(C4) + Imaginary(I4)";
  newC = c4 + i4;
  cout << newC;

  return 0;
}