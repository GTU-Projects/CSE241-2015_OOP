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
#include "Reversi.h"
#include <cctype> // to upper

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
    cerr << "Invalid placer in setPlace!!!";
    return false;
  }
  return true;
}

void Cell::set(int xCoord, int yCoord, char whoPlace) {
  setX(xCoord);
  setY(yCoord);
  setPlacer(whoPlace);
}

bool Cell::operator==(const Cell& other)const {
  return this->getX() == other.getX() &&
          this->getY() == other.getY() &&
          this->getPlacer() == other.getPlacer();
}

bool Cell::operator!=(const Cell& other)const {
  return !(*this == other);
}

Cell Cell::operator++() {
  setX(getX() + 1);
  setY(getY() + 1);

  return *this;
}

Cell Cell::operator++(int ignore) {
  int xC = getX();
  int yC = getY();

  setX(getX() + 1);
  setY(getY() + 1);

  return Cell(xC, yC, getPlacer());
}

Cell Cell::operator--() {
  setX(getX() - 1);
  setY(getY() - 1);

  return *this;
}

// take independent copy, make changes

Cell Cell::operator--(int ignore) {
  int xC = getX();
  int yC = getY();

  setX(getX() - 1);
  setY(getY() - 1);

  return Cell(xC, yC, getPlacer());
}

ostream& operator<<(ostream& os, const Cell& myCell) {

  os << "## C:" << myCell.getX() << " - R:"
          << myCell.getY() << " - Who :"
          << myCell.getPlacer() << " ##";
}

istream& operator>>(istream& is, Cell& myCell) {
  string xCoord;
  int yCoord;
  bool done = false;
  do {

    cout << "Enter X coordinat like a-b-aa-ccc (-1 to exit) :";
    cin>>xCoord;
    if (myCell.setX(myCell.strToInt(xCoord))) {
      cout << "Enter Y coordinat line 0-5-95 :";
      cin>>yCoord;
      if (myCell.setY(yCoord)) {
        myCell.setPlacer('O');
        done = true;
      } else done = false;
    } else done = true;
  } while (!done); // if coordinats not okey
}

int Cell::strToInt(const string& str)const {

  if (str[0] == '-') // if enter negatif number to escape
    return -1;

  return (str.length() - 1)*26 + static_cast<int> (str[0] - 97);

}

// control minor

bool Cell::operator<(const Cell& other) const {
  if (this->getY() < other.getY())
    return true;
  else if (this->getY() > other.getY())
    return false;
  else if (this->getY() == other.getY()) {
    if (this->getX() < other.getX())
      return true;
    else return false;
  }
}

//control majority

bool Cell::operator>(const Cell& other) const {
  if (this->getY() > other.getY())
    return true;
  else if (this->getY() < other.getY())
    return false;
  else { // they are equal
    if (this->getX() > other.getX())
      return true;
    else return false;
  }
}

// control equal or bigger

bool Cell::operator>=(const Cell& other) const {
  if (this->getY() > other.getY())
    return true;
  else if (this->getY() < other.getY())
    return false;
  else { // y equal
    if (this->getX() >= other.getX())
      return true;
    else return false;
  }
}

//control euqal or smaller

bool Cell::operator<=(const Cell& other) const {
  if (this->getY() < other.getY())
    return true;
  else if (this->getY() > other.getY())
    return false;
  else if (this->getY() == other.getY()) {
    if (this->getX() <= other.getX())
      return true;
    else return false;
  }
}