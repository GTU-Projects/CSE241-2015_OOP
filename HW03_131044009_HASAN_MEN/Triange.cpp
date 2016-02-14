/* 
 * File:   Triange.cpp
 * Author: HASAN_MEN_131044009
 * 
 * This file include implementation of member functions 
 * Created on October 21, 2015, 4:24 PM
 */

#include "Triange.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Constructors

Triangle::Triangle() {
  setTriangle();
}

Triangle::Triangle(double aLength) {
  setTriangle(aLength);
}

Triangle::Triangle(double aLength, double bLength) {
  setTriangle(aLength, bLength);
}

Triangle::Triangle(double aLength, double bLength, double cLength) {
  setTriangle(aLength, bLength, cLength);
}

// checks lenght, if valid , assigns private members, else close the program

void Triangle::setTriangle(double aLength, double bLength, double cLength) {
  if (aLength <= 0 || bLength <= 0 || cLength <= 0) {
    cerr << "Sides are not valid.Length not be less than 0.";
    cerr << "Please try again !!!" << endl;
    exit(1);
  }
  aSide=aLength;
  bSide=bLength;
  cSide=cLength;
}

// Shows member varialbles on standart output

void Triangle::output() const {
  cout << "Sides of Triangle  ";
  cout << "A :" << getASide() << "  B :" << getBSide() << "  C :" << getCSide() << endl;

}

// Changes lenght of triangle with new values which entered with std. input

void Triangle::input() {

  double tmpA, tmpB, tmpC;
  cout << "Enter length of A-B-C sides,respectively";
  cin >> tmpA >> tmpB>>tmpC;

  setTriangle(tmpA, tmpB, tmpC);
}

// return perimeter of triangle

double Triangle::getPerimeter() const {
  return getASide() + getBSide() + getCSide();
}

// find angle of sides with using cosinus theorem and returns

double Triangle::getAngleA() const {
return calculateAngle(getASide(),getBSide(),getCSide());
}

double Triangle::getAngleB() const {
return calculateAngle(getBSide(),getCSide(),getASide());
}

double Triangle::getAngleC() const {
return calculateAngle(getCSide(),getASide(),getBSide());
}

// calculate area of triangle with sinus theorem 

double Triangle::getArea() const {
  return getASide() * getBSide() * (sin(getAngleC() * PI / 180.0)) / 2.0;
}

// uses angle functons and checks that, if there are one or more right angle return true,else false;
// 90 not equal 90.000000001-> it is create error 

bool Triangle::isRightAngle() const {
  return (static_cast<int> (getAngleA()) == 90 || static_cast<int> (getAngleB()) == 90 || static_cast<int> (getAngleC()) == 90);
}

// calculate sides of whichside
double Triangle::calculateAngle(double whichSide, double side2, double side3) const
{
  return acos(((side2 * side2)+(side3 * side3)-(whichSide * whichSide)) / (2 * side2 * side3))*180 / PI;
}