/* 
 * File:   Cell.cpp
 * Author: hmenn - HASAN MEN - 131044009
 *
 * Created on November 29, 2015, 10:49 PM
 * Bu dosya oyun cell class ve fonksiyonlarinin implementationlarini icerir
 * 
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include "Cell.h"
#include <cctype> // toupper

namespace {
  
  int strToInt(const std::string& column) {
    if (column[0] == '-') // cikis icin negatif girilmesini kontrol
      return -1;
    return (column.length() - 1)*26 + static_cast<int> (column[0] - 97);
  }
}

namespace HmennReversi {

  using std::string;
  using std::cout;
  using std::cerr;
  using std::cin;
  using std::endl;
  using std::ostream;
  using std::istream;

  Cell::Cell() : m_rowCoord(0), m_colCoord(0), m_player(empty) {
    /*Intentionaly empty */
  }

  Cell::Cell(int column, int row, char player) {
    setAll(column, row, player);
  }

  Cell::Cell(const Cell& other) { //this nasil calisir
    this->setAll(other.getColCoord(), other.getRowCoord(), other.getPlayer());
  }

  bool Cell::setRowCoord(int newRowCoord) {
    if (newRowCoord >= 0 || newRowCoord == -1) {
      m_rowCoord = newRowCoord;
      return true;
    } else {
      cerr << "Row can not be negative.Row assigned 0(Zero)." << endl;
      m_rowCoord = 0;
      return false;
    }
  }

  bool Cell::setColCoord(int newColCoord) {
    if (newColCoord >= 0 || newColCoord == -1) {
      m_colCoord = newColCoord;
      return true;
    } else {
      cerr << "Column can not be negative.Column assigned 0(Zero)." << endl;
      m_colCoord = 0;
      return false;
    }
  }

  bool Cell::setPlayer(char newPlayer) {
    char tempPlayer = toupper(newPlayer);
    if (tempPlayer == empty || tempPlayer == user || tempPlayer == computer) {
      m_player = tempPlayer;
      return true;
    } else {
      cerr << "Player can not be outside '.' , 'X' or 'O'.Player assigned 'O'." << endl;
      m_player = user;
      return false;
    }
  }

  bool Cell::setAll(int cCoord, int rCoord, char player) {
    if (setRowCoord(rCoord) && setColCoord(cCoord) && setPlayer(player))
      return true;
    else return false;
  }

  ostream& operator<<(ostream& os, const Cell& cell) {
    os << "Column : " << cell.getColCoord() << " - Row : "
            << cell.getRowCoord() << " - Who : "
            << cell.getPlayer() << endl;
    return os;
  }

  // alinan koordinat icin sadece gecerli(tablo icinde) olup olmadigina bakilir.
  // Dogru hamle olup olmadigi reversi sinifinin isi
  istream& operator>>(istream& is, Cell& cell) {
    string xCoord;
    int yCoord;
    bool done = false;
    do {
      cout << "Enter X coordinat like a-b-aa-ccc (-1 to exit) :";
      cin>>xCoord;
      if (cell.setColCoord(strToInt(xCoord))) { // x koordinati dogru ise
        cout << "Enter Y coordinat line 0-5-95 :";
        cin>>yCoord;
       
        if (cell.setRowCoord(yCoord)) { // y dogru mu
          cell.setPlayer(user);
          done = true;
        } else done = false;
      } else done = true;
    } while (!done); // koordinatlar dogru degilse tekrar iste
  }

  bool Cell::operator==(const Cell& other)const {
    return this->getColCoord() == other.getColCoord() &&
            this->getRowCoord() == other.getRowCoord() &&
            this->getPlayer() == other.getPlayer();
  }

  bool Cell::operator!=(const Cell& other)const {
    return !(*this == other);
  }

  Cell& Cell::operator=(const Cell& other) {
    this->setAll(other.getColCoord(), other.getRowCoord(), other.getPlayer());
    return *this;
  }
}