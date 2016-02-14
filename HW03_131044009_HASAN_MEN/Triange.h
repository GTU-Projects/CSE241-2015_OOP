/* 
 * File:   Triange.h
 * Author: HASAN_MEN_131044009
 *
 * 
 * This file include Triangle class,member func. member variables.
 * Created on October 21, 2015, 4:24 PM
 */

#ifndef TRIANGE_H
#define	TRIANGE_H



const double PI = 3.14159265;

class Triangle {
public:
    // Constructors 
    Triangle();
    Triangle(double a);
    Triangle(double a, double b);
    Triangle(double a, double b, double c);
    // getter
    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;

    double getASide() const {return aSide;}

    double getBSide() const {return bSide;}

    double getCSide() const {return cSide;}
    double getArea() const;
    double getPerimeter() const;
    //setter

    void setTriangle(double aLength = 1.0, double bLength = 1.0, double cLength = 1.0);

    bool isRightAngle() const;
    void input();
    void output() const;

private:
    double calculateAngle(double whichSide,double otherSide,double otherSide2) const;
    double aSide;
    double bSide;
    double cSide;

};

#endif	/* TRIANGE_H */

