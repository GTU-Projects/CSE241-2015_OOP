/* 
 * File:   main.cpp
 * Author: HASAN_MEN_131044009
 *
 * This file include test functions for triangle class
 * Created on October 16, 2015, 5:23 PM
 */

#include "Triange.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void testReadClass(Triangle testTri);
void testChangeClass(Triangle& testTri);

int main(int argc, char** argv) {

  Triangle test1(5, 12, 13), test2(3, 4, 2);
  Triangle test3, test4(2, 3);

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "TEST FOR CALL BY VALUES" << endl;
  testReadClass(test1);
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  testReadClass(test2);
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
  cout << "TEST FOR CALL BY REFERENCES" << endl;
  testChangeClass(test3);
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  testChangeClass(test4);

  return 0;
}

// test object with call by value

void testReadClass(Triangle testTri) {


  testTri.output();

  cout << "A angle = " << testTri.getAngleA() << endl;
  cout << "B angle = " << testTri.getAngleB() << endl;
  cout << "C angle = " << testTri.getAngleC() << endl << endl;

  cout << "Area of triangle = " << testTri.getArea() << endl;
  cout << "Perimeter of triangle = " << testTri.getPerimeter() << endl;

  if (testTri.isRightAngle())
    cout << "Right Anlgle" << endl;
  else cout << "Not right Anlgle" << endl<<"------"<<endl;
}

//test object with call by reference

void testChangeClass(Triangle& testTri) {

  cout << "Initial values : " << endl;
  testReadClass(testTri);
  cout << "Lets change sides of triangle ->" << endl;
  testTri.input();
  testReadClass(testTri);
}


