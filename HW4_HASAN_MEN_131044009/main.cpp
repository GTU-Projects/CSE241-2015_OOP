/*
 * File:   main.cpp
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:49 AM
 * 
 * This is main file to test reversi and cell classes
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Reversi.h"

using namespace std;

int main(int argc, char** argv) {


  Reversi game1("sixsix.txt");
  Reversi game2;
  Reversi game3(8, 10);
  Reversi game4(20, 30);
  Reversi game5("tenten.txt");
  Reversi game6("ab.txt");
    
  cout<<"Welcome game of reversi"<<endl;
  cout<<"I load 5 reversi game from files and new created objects."<<endl;
  cout<<"Lets play games respectively"<<endl;
  cout << "------------------" << endl;
  cout << "Now you play game1" << endl;
  cout << "------------------" << endl;
  game1.playGame();
  cout << "------------------" << endl;
  cout << "Now you play game2" << endl;
  cout << "------------------" << endl;
  game2.playGame();
  cout << "------------------" << endl;
  cout << "Now you play game3" << endl;
  cout << "------------------" << endl;
  game3.playGame();
  cout << "------------------" << endl;
  cout << "Now you play game4" << endl;
  cout << "------------------" << endl;
  game4.playGame();
  cout << "------------------" << endl;
  cout << "Now you play game5" << endl;
  cout << "------------------" << endl;
  game5.playGame();

  bool compare = true;
  do {
    
    cout<<"-----\n Game1 \n -----\n";
    game1.displayBoard();
    cout<<"-----\n Game2 \n -----\n";
    game2.displayBoard();
    cout<<"-----\n Game3 \n -----\n";
    game3.displayBoard();
    cout<<"-----\n Game4 \n -----\n";
    game4.displayBoard();
    cout<<"-----\n Game5 \n -----\n";
    game5.displayBoard();
    
    
    Reversi *first, *second;
    cout << "Wanna compare games which you played (y):";
    char x;
    cin>>x;
    if (x == 'Y' || x == 'y') {
      string name1, name2;
      cout << "Give name of first game :";
      cin>>name1;
      cout << "Give name of second game :";
      cin>>name2;
      
      if(name1=="game1") {first = &game1;}
      else if(name1=="game2") {first = &game2;}
      else if(name1=="game3") {first = &game3;}
      else if(name1=="game4") {first = &game4;}
      else if(name1=="game5") {first = &game5;}
      else cout << "Wrong game name1";

      if(name2=="game1") {second = &game1;}
      else if(name2=="game2") {second = &game2;}
      else if(name2=="game3") {second = &game3;}
      else if(name2=="game4") {second = &game4;}
      else if(name2=="game5") {second = &game5;}
      else cout << "Wrong game name2";

    }else compare=false;
    
    bool isFirstBig=false;
    if(compare){
      isFirstBig=first->compare(*second);
    }
      cout<<"First >= Second : "<<isFirstBig<<endl;
    
    
    char c;
    
    cout<<"Wanna write best game to file:(y)";
    cin>>c;
    if(c=='y' || c=='Y'){
      Reversi *wFile;
      if(isFirstBig)
        wFile=first;
      else wFile=second;
      
      wFile->writeBoard("BestCompared.txt");
    }
    
  } while (compare);

  return 0;
}

