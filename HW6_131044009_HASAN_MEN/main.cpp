/* 
 * File:   main.cpp
 * Author: hmenn -- HASAN MEN 131044009 
 *
 * Created on November 29, 2015, 10:49 PM
 * Bu dosya reversi ve cell classlari icin test kismini icerir
 */
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Cell.h"
#include "Reversi.h"

using namespace std;

int main(int argc, char** argv) {
  using namespace HmennReversi;
  // desctuctorlar calissin diye block yapildi
  {
    Reversi game1;
    Reversi game2(game1);

    cout << "Welcome game of reversi" << endl;
    cout << "I load 5 reversi game from files and new created objects." << endl;
    cout << "Lets play games respectively" << endl;
    cout << "------------------" << endl;
    cout << "Now you play game1" << endl;
    cout << "------------------" << endl;
    game1.playGame();
    cout << "------------------" << endl;
    cout << "Now you play game2" << endl;
    cout << "------------------" << endl;
    game2.playGame();

    cout << "First >= Second : " << (game1 == game2) << endl;

    cout << endl << "~~" << endl << "Living games : " <<
            Reversi::getNumLivingRev() << endl << "~~" << endl;

  } // canli reversiler destuctor ile olduruldu
  cout << endl << "~~" << endl << "Living games : " <<
          Reversi::getNumLivingRev() << endl << "~~" << endl;

  return 0;
}