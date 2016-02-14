/*
 * File:   Cell.cpp
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:20 AM
 * This file include cell class and function implementations
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include "Cell.h"
#include <cctype>

using namespace std;

Cell::Cell() {
  set(0, 0, 'X');
}

Cell::Cell(int xCoord, int yCoord, char whoPlace) {
  setX(xCoord);
  setY(yCoord);
  setPlacer(whoPlace);
}

Cell::Cell(const Cell& other) {
  set(other.getX(), other.getY(), other.getPlacer());
}

bool Cell::setX(int xCoord) {

  if (xCoord >= 0)
    m_x = xCoord;
  else {
    m_x = xCoord;
    //cerr << "X coordinat can not initialized(X is negative)." << endl;
    return false;
  }
  return true;
}

bool Cell::setY(int yCoord) {

  if (yCoord >= 0)
    m_y = yCoord;
  else {
    m_y = yCoord;
    //cerr << "Y coordinat can not initialized(X is negative)" << endl;
    return false;
  }
  return true;
}

bool Cell::setPlacer(char whoPlace) {

  char ch = toupper(whoPlace);
  if (ch == 'X' || ch == 'O')
    m_whoPlace = ch;
  else {
    cerr << "Invalid placer int setPlace!!!";
    return false;
  }
  return true;
}

void Cell::set(int xCoord, int yCoord, char whoPlace) {
  setX(xCoord);
  setY(yCoord);
  setPlacer(whoPlace);
}

bool Cell::compareCell(const Cell& other)const {
  return getX() == other.getX() &&
          getY() == other.getY() &&
          getPlacer() == other.getPlacer();
}

bool Cell::input() {

  string xCoord;
  int yCoord;
  bool done = false;
  do {

    cout << "Enter X coordinat like a-b-aa-ccc (-1 to exit) :";
    cin>>xCoord;
    if (strToInt(xCoord) != -1) {
      if (this->setX(strToInt(xCoord))) {
        cout << "Enter Y coordinat line 0-5-95 :";
        cin>>yCoord;
        if(this->setY(yCoord))
          done=true;
        else done=false;
      }else done=false;
    } else {
      return false;
    }

  } while (!done);

  setPlacer('O');
  return true;
}

int Cell::strToInt(const string& str)const {

  if (str[0] == '-')
    return -1;

  return (str.length()-1)*26 +  static_cast<int> (str[0]-97);

}

void Cell::output()const{
  cout<<"Cell ->  X :"<<getX()<<" - Y :"<<getY()<<" - Placer :"<<getPlacer()<<endl;
}







