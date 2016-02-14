/*
 * File:   main.cpp
 * Author: HASAN MEN - 131044009
 *
 * Created on September 16, 2015, 2:29 PM
 * This file include main function and starts game
 */
#include <iostream>
#include <cstdlib> //srand time
#include <ctime> // srand time
#include "reversi.h"

using namespace std;

int main(int argc, char** argv) {

  int row, column;
  int board[MAX_ROW][MAX_COLUMN];

  srand(time(NULL));
  if (takeInput(&row, &column)) { // if inputs true play game
    createBoard(board, row, column);
    playGame(board, row, column);
    outputScore(board, row, column);
  } else {
    cout << "Good Bye..." << endl;
  }
  return 0;
}
