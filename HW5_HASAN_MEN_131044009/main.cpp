/*
 * File:   main.cpp
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:49 AM
 * this file include driver
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Reversi.h"

using namespace std;

int main(int argc, char** argv) {

  bool inMenu = true;
  int goGame = 0; // game sequent
  Reversi game1, game2(6, 6), game3(8, 8), game4("tenten.txt"), game5;
  Reversi *game = &game1;
  bool endGame = false;
  while (!endGame) {

    switch (goGame) { // change game // gogame updated when choice go up menu
      case 0: game = &game1;
        break;
      case 1: game = &game2;
        break;
      case 2: game = &game3;
        break;
      case 3: game = &game4;
        break;
      case 4: game = &game5;
        break;
      default: endGame = true;
        break;
    }

    do {
      system("clear"); //clear screen
      cout << *game;
      cout << "Hi! Welcome to game of reversi -_-" << endl;
      cout << "Lets choice game option and play -_-" << endl << endl;
      cout << "1. Create new game according to sizes." << endl;
      cout << "2. Load a game from file." << endl;
      cout << "3. Control function overloads -> **HW5 - CHECKS**" << endl;
      cout << "4. Change game" << endl;
      cout << "5. CLose all program" << endl;

      int choice = 0;
      cin>>choice;
      char tmp;

      switch (choice) {

        case 1:
        {
          // will play game end of game or when user wanna go out
          game->playGame();
        }
          break;
        case 2:
        { // read game from file
          char fname[20];
          cout << "Enter file name :";
          cin>>fname;
          game->readBoard(fname);
          game->playGame();
        }
          break;
        case 3:
        {// there are some test function 
          bool menu2active = true;
          while (menu2active) {
            int menu2 = 0;
            system("clear");
            cout << *game;
            cout << "1.Test Cell overloads " << endl;
            cout << "2.Test Reversi overloads " << endl;
            cout << "3. Go up menu" << endl;

            cin>>menu2;

            switch (menu2) {
              case 1:
              {
                string pos1, pos2;
                Cell c1, c2, c3, c4;

                cout << "Enter cell1 coordinate like 'a5' , 'bb14' :" << endl;
                cin>>pos1;
                cout << "Enter cell1 coordinate like 'c9' , 'gg3' :" << endl;
                cin>>pos2;
                c1 = (*game)[pos1];
                c2 = (*game)[pos2];

                if (c1.getX() != -1000 && c2.getX() != -1000) {
                  cout << c1 << " '<' " << c2 << " = " << (c1 < c2) << endl;
                  cout << c1 << " '>' " << c2 << " = " << (c1 > c2) << endl;
                  cout << c1 << " '<=' " << c2 << " = " << (c1 <= c2) << endl;
                  cout << c1 << " '>=' " << c2 << " = " << (c1 >= c2) << endl;

                  cout << (c1) << " '++cell1' " << " = ";
                  c3 = ++c1;
                  cout << (c3) << endl;

                  cout << c1 << " 'cell1++' " << " = ";
                  c3 = c1++;
                  cout << c3 << endl;
                  cout << "Last cell1 =" << c1 << endl;

                  cout << (c2) << " '--cell2' " << " = ";
                  c4 = --c2;
                  cout << (c4) << endl;

                  cout << c2 << " 'cell2--' " << " = ";
                  c4 = c2--;
                  cout << c4 << endl;
                  cout << "Last cell1 =" << c2 << endl;

                } else {
                  cout << "Cell invalid. Please try again ";
                }
                cout << "Enter something to go up menu " << endl;
                cin>>tmp;
              }
                break;
              case 2:
              {
                system("clear");
                cout << *game;
                cout << "#########\nGAME++ :";
                cout << ((*game)++);
                cout << "########\nGAME :";
                cout << *game;
                cout << "########\n++GAME :";
                cout << (++(*game));

                cout << "########\nGAME-- :";
                cout << ((*game)--);
                cout << "########\nGAME :";
                cout << *game;
                cout << "########\n--GAME :";
                cout << (--(*game));

                cout << " Game[c2]" << (*game)["c2"] << endl;
                cout << " Game[f25]" << (*game)["f25"] << endl;
                cout << " Game[dd0]" << (*game)["a0"] << endl;

                cout << " Game(\"a\",2) :" << (*game)("a", 2) << endl;
                cout << " Game(\"b\",1) :" << (*game)("b", 1) << endl;
                cout << " Game(\"gg\",15) :" << (*game)("gg", 15) << endl;

                cout << " Game+= cell(0,1,'O')" << endl;
                (*game) += Cell(0, 1, 'O');
                cout << *game;

                cout << "Enter something to go up menu " << endl;
                cin>>tmp;
              }
                break;
              case 3: menu2active = false;
                break;
              default: cout << "Wrong menu option try again ";
                break;
            }
          }
        }
          break;
        case 4: inMenu = false;
          ++goGame;
          break;
        case 5: goGame = 5; endGame=true;
          inMenu = false;
          break;
        default: cout << "Invalid menu choice. Please choice valid option.";
      }
    } while (inMenu);
  }
  cout << "Good Bye... " << endl;
  return 0;
}