/*
 * File:   reversi.cpp
 * Author: HASAN MEN - 131044009
 *
 * This file include reversi class implementation
 * You can find some minor information other will be in report file.
 */
#include <iostream>
#include <cstdlib> // srand and rand
#include <ctime> // srand time and rand
#include "reversi.h"
#include <cctype> //tolower

//#define DEBUG
// when open, will show some tricks and informations

using namespace std;

// checks the row and column and if they can create a table return true
// if not a table return false

bool isTable(int row, int column) {
  bool table = true;
  if (column == row && column >= 4 && column % 2 == 0 && column <= 20)
    table = true;
  else
    table = false;
  return table;
}

// takes tempRow and tempColumn and checks values.If they compose a table
// return true and our game will begin, else program will end

bool takeInput(int* row, int* column) {
  bool done = true; // check loop
  bool inputState = true; // return value to start game
  int temp;
  char choice;

  cout << "Enter an oven number in range of [4,20] to create game board >> ";
  cin >> temp;

  done = isTable(temp, temp);

  // if inputs are invalid, takes new inputs or exit the game
  while (!done) {
    cout << temp << " not an oven square table or not in range" << endl;
    cout << "Do you wanna enter new value(Y/N) >>";
    cin>>choice;
    if (choice == 'Y' || choice == 'y') {
      cout << "Enter an oven number in range of [4,20] >> ";
      cin >> temp;
      done = isTable(temp, temp);
    } else {
      done = true;
      inputState = false;
    }
  }
  // inputs accepted
  if (done && inputState) {
    *row = temp;
    *column = temp;
  }
  return inputState;
}

void createBoard(int board[][MAX_COLUMN], int row, int column) {
  int midX;
  int temp; // store random number 0-1

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < column; ++j)
      board[i][j] = available;

  // specified middle coordinat
  midX = row / 2.0 - 1;

  // calculate user first coordinat
  temp = rand() % 2;

  if (temp == 0) { //
    board[midX][midX] = player;
    board[midX + 1][midX + 1] = player;
    board[midX][midX + 1] = computer;
    board[midX + 1][midX] = computer;
  } else {
    board[midX][midX] = computer;
    board[midX + 1][midX + 1] = computer;
    board[midX][midX + 1] = player;
    board[midX + 1][midX] = player;
  }
}

void printBoard(int board[][MAX_COLUMN], int row, int column) {
  char letter = 'a';

  //int letterAscii;
  // a is 97 in ascii
  //letterAscii=static_cast<int>(letter);

  cout << "  ";
  for (int i = 0; i < column; ++i)
    cout << letter++ << " ";

  cout << endl;
  for (int i = 0; i < row; ++i) {
    cout << i + 1;
    if (i + 1 < 10) cout << " "; // escape space overflow, when number bigger than 10
    for (int j = 0; j < column; ++j) {
      switch (board[i][j]) {
        case available: cout << ". ";
          break;
        case player: cout << "O ";
          break;
        case computer: cout << "X ";
          break;
        default: cerr << "Board include notavailable type!!!";
          break;
      }
    }
    cout << endl;
  }
}

tCoordinat findBestAttack(int board[][MAX_COLUMN], int row, int column, ePlace whoPlay) {
  int values[MAX_ROW][MAX_COLUMN]; // attack will write int there sequently
  ePlace enemy;

  if (whoPlay == computer) // if player is computer,will find player like enemy
    enemy = player;
  else enemy = computer; // or enemy is computer


  for (int i = 0; i < row; ++i)
    for (int j = 0; j < column; ++j)
      values[i][j] = 0;

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      if (board[i][j] == available) {
        /*~~~~~~~~~~~~~~~~CONTROL RIGHT~~~~~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i, j + 1, 0, 1, enemy);

        /*~~~~~~~~~~~~~~~~CONTROL LEFT~~~~~~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i, j - 1, 0, -1, enemy);

        /*~~~~~~~~~~~~~~CONTROL DOWN~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i + 1, j, 1, 0, enemy);

        /*~~~~~~~~~~~~~~~~CONTROL UP~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i - 1, j, -1, 0, enemy);

        /*~~~~~~~~~~~~~~~~~~~~CONTROL RIGHT DOWN~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i + 1, j + 1, 1, 1, enemy);

        /*~~~~~~~~~~~~~~~CONROL RIGHT UP~~~~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i - 1, j + 1, -1, 1, enemy);

        /*~~~~~~~~~~~~~~~~CONTROL LEFT UP~~~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], j - 1, i - 1, -1, -1, enemy);

        /*~~~~~~~~~~~~~~~~CONTROL LEFT DOWN~~~~~~~~~~~~~~~~~~~~*/
        findEatenEnemy(board, row, column, values[i][j], i + 1, j - 1, 1, -1, enemy);
      }
    }
  }

  /*~~~~~~~~ find best attack ~~~~~~~~~~~~~~~*/

  int max = 0;
  tCoordinat maxCoord;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      if (values[i][j] > max) {
        max = values[i][j];
        maxCoord.x = i;
        maxCoord.y = j;
      } else if (values[i][j] == max) // if its same, change coordinat sometimes
        if (rand() % 2) {
          max = values[i][j];
          maxCoord.x = i;
          maxCoord.y = j;
        }
    }
  }

#ifdef DEBUG
  /*~~~~~ contol temp values ~~~~~~~~~*/
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j)
      cout << " " << values[i][j];
    cout << endl;
  }
#endif
  // there is no attack for computer
  if (max == 0) {
    maxCoord.x = -1;
    maxCoord.y = -1;
  }
  return maxCoord;
}

void playGame(int board[][MAX_COLUMN], int row, int column) {
  int whoPlay = 1; // 0 ->computer 1-> who
  int play = 0;
  int xCoord;
  char yCoord;
  tCoordinat move;
  bool done = false;
  int noAttack;

  whoPlay = rand() % 2;

  while (!done) {

    printBoard(board, row, column);
    if (whoPlay == 0) {
      int max = 0;
      move = findBestAttack(board, row, column, computer);
      if (move.x != -1 || move.y != -1) {
#ifdef DEBUG
        cout << "Computer Play :" << move.x << " " << move.y << endl;
#endif
        movePlayer(board, row, column, move, computer);
        whoPlay = 1;
        noAttack = 0;
      } else {
        cout << "There is no move for computer!!!" << endl;
        ++noAttack;
        whoPlay = 1;
      } // pass the sequence
    } else if (whoPlay == 1) {
      do {
        // if there are no available move, pass sequence
        move = findBestAttack(board, row, column, player);
        if (move.x != -1 || move.y != -1) {
          cout << endl << "Enter coordinats like 4e/2A... >>";
          cin >> xCoord>>yCoord;
          move.x = xCoord - 1;
          move.y = static_cast<int> (tolower(yCoord)) - 97;
          play = movePlayer(board, row, column, move, player);
          noAttack = 0;
        } else {
          cout << "There is no move for player!!!" << endl;
          ++noAttack;
        } // pass the sequence

        if (noAttack >= 2) // consequtives no moves
          play = 1;
      } while (!play);
      whoPlay = 0;
    }

    if (noAttack >= 2) {
      done = true; //game over
    }
    system("clear");
  }
}

bool movePlayer(int board[][MAX_COLUMN], int row, int column, tCoordinat move, ePlace whoPlay) {
  int i = move.x, j = move.y;
  int x = 0, y = 0; // temp x,y coordinats
  int z = 0, v = 0;
  bool draw = false;

  int numEnemy = 0;
  if (board[i][j] == available) {
    tCoordinat new_coord = {i, j + 1};

    /*~~~~~~~~~~~~~~~~DRAW RIGHT~~~~~~~~~~~~~~~~~~~~~~~~~*/
    drawPath(board, row, column, i, j + 1, 0, 1, whoPlay, new_coord);
    if (new_coord.y != j + 1) { //found something right
      while (new_coord.y >= j) {
        board[i][new_coord.y] = whoPlay;
        --(new_coord.y);
      }
      draw = true;
    }
    /*~~~~~~~~~~~~~~~~DRAW LEFT~~~~~~~~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i;
    new_coord.y = j - 1;
    drawPath(board, row, column, i, j - 1, 0, -1, whoPlay, new_coord);
    if (new_coord.y != j - 1) { //found something right
      while (new_coord.y <= j) {
        board[i][new_coord.y] = whoPlay;
        ++(new_coord.y);
      }
      draw = true;
    }

    /*~~~~~~~~~~~~~~~~DRAW DOWN~~~~~~~~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i + 1;
    new_coord.y = j;
    drawPath(board, row, column, i + 1, j, 1, 0, whoPlay, new_coord);
    if (new_coord.x != i + 1) {
      while (new_coord.x >= i) {
        board[new_coord.x][j] = whoPlay;
        --(new_coord.x);
      }
      draw = true;
    }

    /*~~~~~~~~~~~~~~~~DRAW UP~~~~~~~~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i - 1;
    new_coord.y = j;
    drawPath(board, row, column, i - 1, j, -1, 0, whoPlay, new_coord);
    if (new_coord.x != i - 1) {
      while (new_coord.x <= i) {
        board[new_coord.x][j] = whoPlay;
        ++(new_coord.x);
      }
      draw = true;
    }

    /*~~~~~~~~~~~~~~~~DRAW RIGHT DOWN~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i + 1;
    new_coord.y = j + 1;
    drawPath(board, row, column, i + 1, j + 1, 1, 1, whoPlay, new_coord);
    if (new_coord.x != i + 1 && new_coord.y != j + 1) {
      while (new_coord.x >= i && new_coord.y >= j) {
        board[new_coord.x][new_coord.y] = whoPlay;
        --(new_coord.x);
        --(new_coord.y);
      }
      draw = true;
    }
    /*~~~~~~~~~~~~~~~~DRAW RIGHT up~~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i - 1;
    new_coord.y = j + 1;
    drawPath(board, row, column, i - 1, j + 1, -1, 1, whoPlay, new_coord);
    if (new_coord.x != i - 1 && new_coord.y != j + 1) {
      while (new_coord.x <= i && new_coord.y >= j) {
        board[new_coord.x][new_coord.y] = whoPlay;
        ++(new_coord.x);
        --(new_coord.y);
      }
      draw = true;
    }
    /*~~~~~~~~~~~~~~~~DRAW LEFT UP~~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i - 1;
    new_coord.y = j - 1;
    drawPath(board, row, column, i - 1, j - 1, -1, -1, whoPlay, new_coord);
    if (new_coord.x != i - 1 && new_coord.y != j - 1) {
      while (new_coord.x <= i && new_coord.y <= j) {
        board[new_coord.x][new_coord.y] = whoPlay;
        ++(new_coord.x);
        ++(new_coord.y);
      }
      draw = true;
    }
    /*~~~~~~~~~~~~~~~~DRAW LEFT DOWN~~~~~~~~~~~~~~~~~~~*/
    new_coord.x = i + 1;
    new_coord.y = j - 1;
    drawPath(board, row, column, i + 1, j - 1, +1, -1, whoPlay, new_coord);
    if (new_coord.x != i + 1 && new_coord.y != j - 1) {
      while (new_coord.x >= i && new_coord.y <= j) {
        board[new_coord.x][new_coord.y] = whoPlay;
        --(new_coord.x);
        ++(new_coord.y);
      }
      draw = true;
    }
  }
  return draw;
}

void findEatenEnemy(int board[][MAX_COLUMN], int row, int column, int& value, int x, int y, int xRate, int Yrate, ePlace foundWho) {
  int numEnemy = 0;
  bool found = false;
  ePlace gamer;

  if (foundWho == player)
    gamer = computer;
  else gamer = player;

  if (y > 0 && x > 0 && x < row && y < column && board[x][y] == foundWho) { //found the enemy nums.
    while (x >= 0 && y >= 0 && x < row && y < column) {
      if (!found && board[x][y] == foundWho) // found first occurence
        ++numEnemy;
      if (board[x][y] == gamer) {
        value += numEnemy;
        found = true;
      }
      x += xRate;
      y += Yrate;
    }
  }
}

void drawPath(int board[][MAX_COLUMN], int row, int column, int x, int y, int xRate, int yRate, ePlace who, tCoordinat& new_coord) {
  ePlace attacker, enemy;
  bool found = false;
  int numEnemy = 0;
  int i = 0, j = 0;

  if (who == player) {
    attacker = player;
    enemy = computer;
  } else {
    attacker = computer;
    enemy = player;
  }

  if (y < column && y >= 0 && x >= 0 && x < row && board[x][y] == enemy) {
    while (y < column && y >= 0 && x >= 0 && x < row) {
      if (!found && board[x][y] == enemy)
        ++numEnemy;
      // found cordination will assigned new_coord pointer
      if (!found && board[x][y] == attacker && numEnemy > 0) {
        found = true;
        new_coord.x = x; // end coordinats
        new_coord.y = y;
      }
      x += xRate;
      y += yRate;
    }
  }
}

void outputScore(int board[][MAX_COLUMN], int row, int column) {
  int numOfComp = 0;
  int numOfPlayer = 0;

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < column; ++j)
      if (board[i][j] == player)
        ++numOfPlayer;
      else if (board[i][j] == computer)
        ++numOfComp;

  if (numOfComp > numOfPlayer)
    cout << "Computer win : " << numOfComp << " - " << numOfPlayer << endl;
  else if (numOfPlayer > numOfComp)
    cout << "Player win : " << numOfPlayer << " - " << numOfComp << endl;
  else
    cout << "Game draws : " << numOfPlayer << " - " << numOfComp << endl;
}
