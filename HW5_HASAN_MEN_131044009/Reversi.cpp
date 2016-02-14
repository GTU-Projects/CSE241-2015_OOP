/*
 * File:   Reversi.cpp
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:20 AM
 * This file include reversi class implementation
 * You can find some minor information other will be in report file.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Reversi.h"
#include "Cell.h"
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//#define DEBUG

int Reversi::numOfLivCells = 0;


// it will create default game 4*4;

Reversi::Reversi() {
  int midX = (m_width = 4) / 2 - 1;
  int midY = (m_height = 4) / 2 - 1;

  vector<Cell> rowCell; // rows
  Cell temp; // live cells

  temp.set(midX, midY, 'X');
  rowCell.push_back(temp);
  numOfLivCells++;


  temp.set(midX + 1, midY, 'O');
  rowCell.push_back(temp);
  numOfLivCells++;
  gameCells.push_back(rowCell);


  temp.set(midX, midY + 1, 'O');
  rowCell.clear();
  rowCell.push_back(temp);
  numOfLivCells++;

  temp.set(midX + 1, midY + 1, 'X');
  rowCell.push_back(temp);
  numOfLivCells++;
  gameCells.push_back(rowCell);
}

// will create a gamecell board according to given sizes

Reversi::Reversi(int width, int height) {
  int midX = (m_width = width) / 2 - 1;
  int midY = (m_height = height) / 2 - 1;

  vector<Cell> rowCell;
  Cell temp;
  // add live cell on empty gamecell
  // their exact coordinat will be in the middle of the board
  temp.set(midX, midY, 'X');
  rowCell.push_back(temp);
  numOfLivCells++;

  temp.set(midX + 1, midY, 'O');
  rowCell.push_back(temp);
  numOfLivCells++;
  gameCells.push_back(rowCell);

  temp.set(midX, midY + 1, 'O');
  rowCell.clear();
  rowCell.push_back(temp);
  numOfLivCells++;

  temp.set(midX + 1, midY + 1, 'X');
  rowCell.push_back(temp);
  numOfLivCells++;
  gameCells.push_back(rowCell);
}

Reversi::Reversi(const char* filename) {
  readBoard(filename);
}


// fill string and return reference
// if i=1->a i=26->aa ...

string& Reversi::fillStr(string& temp, int i)const {

  int base = i / 26;
  int mod = i % 26;
  temp.erase();
  temp.push_back(char(mod) + 'a');
  while (base) {
    temp.push_back(char(mod) + 'a');
    base = base / 26;
  }
  return temp;
}

// it will read gameboard from file(just living cells)

void Reversi::readBoard(const char* filename) {
  ifstream file(filename);

  int height = 0;
  string line;
  if (file.is_open()) {
    // read a line
    while (getline(file, line)) {
      bool found = false;
      vector<Cell> row;
      row.clear();

      // split line and count live cells, add gameCells vector
      for (unsigned int i = 0; i < line.length(); ++i) {
        if (line[i] == 'O' || line[i] == 'X') {
          Cell column;
          column.set(i, height, line[i]);
          row.push_back(column);
          numOfLivCells++;
          found = true;
        }
      }
      if (found)
        gameCells.push_back(row);
      m_width = line.length();
      height++;
      line.erase();
    }
  } else {
    cerr << "File" << filename << "couldn't open!" << endl;
    exit(1);
  }
  m_height = height;
  file.close();


}

// write board in outputfile

void Reversi::writeBoard(const char* filename)const {

  ofstream file(filename);

  bool found = false;
  for (int i = 0; i < getHeight(); ++i) {
    for (int j = 0; j < getWidth(); ++j) {

      for (unsigned int r = 0; r < gameCells.size(); ++r) {
        for (unsigned int c = 0; c < gameCells[r].size(); ++c) {

          // if coordinats match
          if (gameCells[r][c].getY() == i && gameCells[r][c].getX() == j) {
            file << gameCells[r][c].getPlacer();
            found = true;
          }
        }
      }
      if (!found) file << ".";
      found = false;
    }
    file << endl;
  }
  file.close();
}

void Reversi::setWidth(int x) {
  if (x < 4) {
    cout << "Invalid new width, I will do it 4.";
    m_width = 4;
  } else m_width = x;
}

void Reversi::setHeight(int y) {
  if (y < 4) {
    cout << "Invalid new height, I will do it 4.";
    m_height = 4;
  } else m_height = y;
}

// it can change game size , which load in main
// ask user a step then pass computer, if user want stop game it will save
// game and break the funcion

void Reversi::playGame() {

  bool changeGame = false;
  Cell attack;
  string xCoord;
  int yCoord;
  int newWidth;
  int newHeight;
  bool coordOkey = false;
  int gameMenu = 0;

  system("clear");
  cout << *this;
  previousGames.push_back(gameCells); // add first table
  cout << "I load a game but you can change board size:" << endl;
  cout << "Press y/Y to change board size(Just board size not cell coordinats)" << endl;
  char change;
  cin>> change;
  if (change == 'y' || change == 'Y') {
    cout << "New X size ";
    cin>>newWidth;
    cout << "New Y size ";
    cin>>newHeight;
    setWidth(newWidth);
    setHeight(newHeight);
  }
  do { // return loop until user stop game or game ends 

    cout << *this;
    cout << "What you wanna do ?" << endl;
    cout << "1.Play one step more" << endl;
    cout << "2.Undo game(go back my last attack)" << endl;
    cout << "3.Make one more step for computer" << endl;
    cout << "4.Exit" << endl;

    if (isGameEnd()) {
      changeGame = true;
    } else {
      cin>>gameMenu;
      switch (gameMenu) {
        case 1:
        {
          do { // go on until coordinats available
            cin>>attack;
            if (attack.getX() == -1) {
              coordOkey = true;
              changeGame = true;
            } else {
              if (attack.getY() >= 0 && attack.getY() < getHeight() &&
                      attack.getX() >= 0 && attack.getY() < getWidth()) {
                if (play(attack)) {
                  previousGames.push_back(gameCells); // add after player attack
                  coordOkey = true;
                  cout << *this;
                }
              } else {
                coordOkey = false;
                cout << "You can not play there. Please enter valid coordinat :" << endl;
              }
            }
          } while (!coordOkey);

          if (!changeGame) {
            play(); // computer play
            previousGames.push_back(gameCells); // add after computer
          }
        }
          break;
        case 2:
        {
          --(*this); // take one step undo - will go last computer attack
        }
          break;

        case 3:
        {
          if (play())
            cout << "Computer played one step more" << endl;
          else cout << "Computer can not play." << endl;
        }
          break;

        case 4: changeGame = true;
          break;
      }
    }
  } while (!changeGame || !isGameEnd());

  whoWin(); // show game stats
}


// this function control the cells and count the num of players then send
// information to display

void Reversi::whoWin() const {

  int user = 0;
  int computer = 0;
  for (unsigned int i = 0; i < gameCells.size(); ++i)
    for (unsigned int j = 0; j < gameCells[i].size(); ++j) {
      if (gameCells[i][j].getPlacer() == 'X')
        ++computer;
      else if (gameCells[i][j].getPlacer() == 'O')
        ++user;
    }

  cout << "User : " << user << " --  Computer : " << computer << endl;
  if (user > computer)
    cout << "Congrats. You win :)" << endl;
  else if (user < computer)
    cout << "Ohh nooo. You lose. Try again :(" << endl;
  else
    cout << "Woow you are good. Lets try.Next time there will a winner." << endl;

  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

bool Reversi::isGameEnd() const {
  // there is no attack for computer and user
  if (findBestAttack('O').getX() == -1 || findBestAttack('X').getX() == -1)
    return true;
  return false;
}

bool Reversi::play(const Cell& attack) {
  bool play = true;
  Cell go;
  int step = 0;

  cout << "Attack : " << attack.getPlacer() << " Y:" << attack.getY() <<
          " X:" << attack.getX() << endl;
  // find cell in board and if available play game
  for (unsigned int r = 0; r < gameCells.size(); ++r) {
    for (unsigned int c = 0; c < gameCells[r].size(); ++c) {

      if (attack.getY() < 0 && attack.getY() >= gameCells[r].size() &&
              attack.getX() < 0 && attack.getX() >= gameCells[r].size() &&
              gameCells[r][c].getY() == attack.getY() &&
              gameCells[r][c].getX() == attack.getX()) {
        play = false;
      }
    }
  }

  if (play) { // if coordinats okey

    bool foundWay = false;
    int xRate = 0;
    int yRate = 0;

    // look down - calcualte number of x 
    // if there is enemy draw the path
    xRate = 0;
    yRate = 1;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X'); // look x-computer
    if ((step = isTherePath(go, xRate, yRate)) > 0) { // look x
      drawPath(go, xRate, yRate, step); // draw X to O
      foundWay = true;
    }

    //look up
    xRate = 0;
    yRate = -1;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }

    //look left
    xRate = -1;
    yRate = 0;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look right

    xRate = 1;
    yRate = 0;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }

    //look right-down
    xRate = 1;
    yRate = 1;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }

    //look right-up
    xRate = 1;
    yRate = -1;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look left-down
    xRate = -1;
    yRate = 1;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }

    //look left-up
    xRate = -1;
    yRate = -1;
    go.set(attack.getX() + xRate, attack.getY() + yRate, 'X');
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }

    if (foundWay) {
      pushCell(attack);
    } else return false;
  } else return false;
  return true;
}

// play one step for computer, if there is no attack will return false

bool Reversi::play() {
  int xRate = 0;
  int yRate = 0;
  int step = 0;

  Cell attack = findBestAttack('X'); // find best attack
  cout << "Best Attack = row: '" << attack.getY() << "' - column '" <<
          attack.getX() << "' - who:" << attack.getPlacer() << endl;

  Cell go = attack;
  string tempStr;

  // there is no attack return false
  if (attack.getY() == -1)
    return false;

  bool foundWay = false;
  // look down
  xRate = 0;
  yRate = 1;
  // look if there is a player calculate num of them
  // and draw the path with computer cells
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O'); // look player
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  //look up
  xRate = 0;
  yRate = -1;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  //look left
  xRate = -1;
  yRate = 0;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  //look right
  xRate = 1;
  yRate = 0;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  //look right-down
  xRate = 1;
  yRate = 1;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  //look right-up
  xRate = 1;
  yRate = -1;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }
  //look left-down
  xRate = -1;
  yRate = 1;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  //look left-up
  xRate = -1;
  yRate = -1;
  go.set(attack.getX() + xRate, attack.getY() + yRate, 'O');
  if ((step = isTherePath(go, xRate, yRate)) > 0) {
    drawPathForComp(go, xRate, yRate, step);
    foundWay = true;
  }

  if (foundWay) {
    pushCell(attack);
  } else return false;
}

// will find best attack according to whoPlay parameter

const Cell Reversi::findBestAttack(const char whoPlay)const {

  char enemy;
  string xCoord;
  Cell checkCell;
  Cell checkCell2;
  Cell maxCell;
  int max = 0;

  if (whoPlay == 'X')
    enemy = 'O';
  else if (whoPlay == 'O') {
    enemy = 'X';
  } else {
    cerr << "Please. Dont attack game functions." << endl;
    exit(1);
  }

  for (unsigned int i = 0; i < getHeight(); ++i) {
    for (unsigned int j = 0; j < getWidth(); ++j) {

      checkCell.set(j, i, whoPlay);
      checkCell2.set(j, i, enemy);

      // if board is empty
      if (!isInBoard(checkCell) && !isInBoard(checkCell2)) {
        // look down
        int xRate = 0;
        int yRate = 1;
        int numOfEat = 0;
        int temp = 0;

        checkCell.set(j + xRate, i + yRate, enemy); // update cell
        temp = isTherePath(checkCell, xRate, yRate); // look path is valid
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play down" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        //look up
        xRate = 0;
        yRate = -1;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play up" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        //look left
        xRate = -1;
        yRate = 0;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play left" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        // look right
        xRate = +1;
        yRate = 0;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play rigth" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        // look right-up
        xRate = +1;
        yRate = -1;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play rigth" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        // look right-down
        xRate = +1;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play rigth" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        // look left-up
        xRate = -1;
        yRate = -1;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play rigth" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }
        // look left-down
        xRate = -1;
        yRate = 1;
        checkCell.set(j + xRate, i + yRate, enemy);
        temp = isTherePath(checkCell, xRate, yRate);
        if (temp > 0) {
          numOfEat += temp;
#ifdef DEBUG
          cout << "I can play rigth" << i << "-" << j << "--->";
          cout << "Can Eat" << numOfEat << endl;
#endif
        }

        if (numOfEat >= max) {
          // will choice best coordinat to eat to much bait
          // i will improve this codes... ####
          max = numOfEat;
          maxCell.set(j, i, whoPlay);
        }
      }
    }
  }

  if (max == 0) // if there is no attack return a information :D
    maxCell.set(-1, -1, whoPlay);

  return maxCell;
}

// update coordinat according to xrate and yrate then check new cell 
// when it see yourself stop and return how mant bait on road

int Reversi::isTherePath(const Cell& player, int xRate, int yRate)const {

  int amount = 0;
  int temp = 0;
  char wanted;
  Cell tmpCell = player;

  char attacker = player.getPlacer();
  if (attacker == 'X')
    wanted = 'O';
  else wanted = 'X';

  // if enemy in board go on
  while (isInBoard(tmpCell)) {
    temp++;
    tmpCell.setX(tmpCell.getX() + xRate);
    tmpCell.setY(tmpCell.getY() + yRate);
  }

  // if find him/it, the path is available and return num of bait
  tmpCell.setPlacer(wanted);
  if (isInBoard(tmpCell))
    amount = temp;

  return amount;
}
// draw path with user 
void Reversi::drawPath(const Cell& attack, int xRate, int yRate, int step) {

  Cell temp = attack;
  for (int i = 0; i < step; ++i) {
    reDrawGameCell(temp, 'O'); // change with O
    //getActualCell(temp).setPlacer('O'); it is old function
    temp.set(temp.getX() + xRate, temp.getY() + yRate, 'X'); // to find next x sign
  }
}
//draw path with computer
void Reversi::drawPathForComp(const Cell& attack, int xRate, int yRate, int step) {
  Cell temp = attack;
  for (int i = 0; i < step; ++i) {
    reDrawGameCell(temp, 'X');
    temp.set(temp.getX() + xRate, temp.getY() + yRate, 'O');
  }
}
// find cell in actual coordinat and change it

void Reversi::reDrawGameCell(const Cell& attack, char newPlacer) {
  for (unsigned int r = 0; r < gameCells.size(); ++r) {
    for (unsigned int c = 0; c < gameCells[r].size(); ++c) {
      if (gameCells[r][c] == attack)
        gameCells[r][c].setPlacer(newPlacer);
    }
  }
}
// is cell in board - is cell true

bool Reversi::isInBoard(const Cell & item)const {
  for (unsigned int r = 0; r < gameCells.size(); ++r) {
    for (unsigned int c = 0; c < gameCells[r].size(); ++c) {
      if (gameCells[r][c] == item)
        return true;
    }
  }
  return false;
}
// this function for debugging
// show number of elements in rows and in gamecell vector

void Reversi::dispVec()const {
  int i = 0;

  for (unsigned int r = 0; r < gameCells.size(); ++r) {
    i = gameCells[r].size();
    cout << "R:" << r << " - " << i << " Item" << endl;
    i = 0;
  }
}

// this function compare two games

bool Reversi::compare(const Reversi & other)const {
  int userScore1 = 0;
  int compScore1 = 0;
  int userScore2 = 0;
  int compScore2 = 0;

  for (unsigned int i = 0; i < gameCells.size(); ++i) {
    for (unsigned int j = 0; j < gameCells[i].size(); ++j) {
      if (gameCells[i][j].getPlacer() == 'X')
        ++compScore1;
      else ++userScore1;
    }
  }

  for (unsigned int i = 0; i < other.gameCells.size(); ++i) {
    for (unsigned int j = 0; j < other.gameCells[i].size(); ++j) {
      if (other.gameCells[i][j].getPlacer() == 'X')
        ++compScore2;
      else ++userScore2;
    }
  }

  cout << "User-Computer in first game :" << userScore1 << "-" << compScore1 << endl;
  cout << "User-Computer in second game :" << userScore2 << "-" << compScore2 << endl;
  return (userScore1 - compScore1) > (userScore2 - compScore2);
}
// this overload return cell in the position
// if dont find it , return -1000
// negatif cell will check in invoker function
Cell Reversi::operator[](const string & pos)const {

  string xCoord;
  string yCoord;
  // first casts coordinat to mean exact coords
  for (int i = 0; i < pos.length(); ++i) {
    if (pos[i] >= 'a' && pos[i] <= 'z') // a-z
      xCoord.push_back(pos[i]);
    else if (pos[i] >= '0' && pos[i] <= '9') // 0-9 
      yCoord.push_back(pos[i]);
    else {
      cerr << "You entered an invalid char program aborted.Will return junk element" << endl;
      return Cell(-1000, -1000, 'O');
    }
  }

  int y = 0;

  // string 69 will be int 69
  for (int i = 0; i < yCoord.length(); ++i)
    y += (static_cast<int> (yCoord[i] - '0')) * pow(10, yCoord.length() - i - 1);

  Cell temp;
  temp.setX(temp.strToInt(xCoord));
  temp.setY(y);

  for (unsigned int i = 0; i < gameCells.size(); ++i) {
    for (unsigned int j = 0; j < gameCells[i].size(); ++j) {
      if (gameCells[i][j].getX() == temp.getX() && gameCells[i][j].getY() == temp.getY())
        return gameCells[i][j];
    }
  }
  return Cell(-1000, -1000, 'O');
}

// this function run like [] operator just takes two parameter
Cell Reversi::operator()(const string& xPos, int yPos) const {

  string xCoord;

  for (int i = 0; i < xPos.length(); ++i) {
    if (xPos[i] >= 'a' && xPos[i] <= 'z') // a-z
      xCoord.push_back(xPos[i]);
    else {
      cerr << "You entered an invalid char program aborted.Will return junk element" << endl;
      return Cell(-1000, -1000, 'O');
    }
  }
  Cell temp;
  temp.setX(temp.strToInt(xCoord));
  temp.setY(yPos);
  for (unsigned int i = 0; i < gameCells.size(); ++i) {
    for (unsigned int j = 0; j < gameCells[i].size(); ++j) {
      if (gameCells[i][j].getX() == temp.getX() && gameCells[i][j].getY() == temp.getY())
        return gameCells[i][j];
    }
  }
  return Cell(-1000, -1000, 'O');
}

// this function show the game board on standart output
ostream& operator<<(ostream& os, const Reversi & item) {
  bool found = false;
  cout << endl;
  string cols;
  cout << " ";

  for (int col = 0; col < item.getWidth(); ++col)
    cout << item.fillStr(cols, col);
  cout << endl;

  for (int i = 0; i < item.getHeight(); ++i) {
    cout << i;
    for (int j = 0; j < item.getWidth(); ++j) {

      for (unsigned int r = 0; r < item.gameCells.size(); ++r) {
        for (unsigned int c = 0; c < item.gameCells[r].size(); ++c) {

          if (item.gameCells[r][c].getY() == i && item.gameCells[r][c].getX() == j) {
            cout << item.gameCells[r][c].getPlacer();
            found = true;
          }
        }
      }
      if (!found)
        cout << ".";
      found = false;
    }
    cout << endl;
  }
}

// takes game one step back
// prefix
Reversi Reversi::operator--() {

  if (previousGames.size() > 0) {
    this->gameCells = previousGames[previousGames.size() - 1];
    previousGames.pop_back();
  }
  return *this;
}

// take game one step back but return prev game
// postfix
Reversi Reversi::operator--(int ignore) {

  Reversi temp = *this;
  if (previousGames.size() > 0) {
    this->gameCells = previousGames[previousGames.size() - 1];
    previousGames.pop_back();
  }
  return temp;
}

// when all situations okey, this function will add new cell on the gameboard
// adds on exact place
// gameCell will be in a sequent
void Reversi::pushCell(const Cell & item) {
  bool foundRow = false;
  bool foundColumn = false;
  int addRow = 0;
  int addColumn = 0;

  for (unsigned int r = 0; r < gameCells.size(); ++r) {
    for (unsigned int c = 0; c < gameCells[r].size(); ++c) {

      if (!foundColumn && gameCells[r][c].getY() == item.getY()) { // first look rows
        if (item.getX() > gameCells[r][c].getX()) {
          addColumn = c + 1;
          addRow = r;
          foundColumn = true;
          foundRow = true;
        } else if (item.getX() < gameCells[r][c].getX()) {
          addColumn = c;
          addRow = r;
          foundColumn = true;
          foundRow = true;
        }
      } else if (!foundRow && !foundColumn && gameCells[r][c].getY() > item.getY()) { // if rows not equal, will add top or bottom
        foundRow = true;
        addRow = 0;
      } else if (!foundRow && !foundColumn && gameCells[r][c].getY() < item.getY()) { // add bottom
        foundRow = true;
        addRow = gameCells.size();

      }
    }

  }
#ifdef DEBUG
  cout << "Will add row: " << addRow << "- column: " << addColumn << endl;
#endif

  if (foundColumn) {
    // just add cell on position
    gameCells[addRow].insert(gameCells[addRow].begin() + addColumn, Cell(item));
  } else if (foundRow) {
    // create new vector fill and pus it on game, table will grow up or buttom
    vector<Cell> temp;
    temp.push_back(Cell(item));
    gameCells.insert(gameCells.begin() + addRow, temp);
  }
  numOfLivCells++;
}

// plays one step for computer
// prefix
Reversi Reversi::operator++() {

  if (play())
    previousGames.push_back(gameCells);
  return *this;
}

// plays one step for computer - postfix
Reversi Reversi::operator++(int ignore) {
  Reversi temp = *this;

  if (play())
    previousGames.push_back(gameCells);

  return temp;
}

// take one cell and if this is okey , plays this cell
// cell must be for user
Reversi Reversi::operator+=(const Cell& attack) {
  if (play(attack))
    previousGames.push_back(gameCells);
  return *this;
}
/* END OF REVERSI.CPP*/