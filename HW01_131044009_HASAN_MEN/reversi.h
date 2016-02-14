/*
 * File:   reversi.h
 * Author: HASAN MEN - 131044009
 *
 * Created on September 16, 2015, 6:54 PM
 * This file include function prototypies and some constant values.
 */

#ifndef REVERSI_H
#define	REVERSI_H

// place in table

enum ePlace {
    available, player, computer
};

struct tCoordinat {
    int x, y;
};

const int MAX_ROW = 20;
const int MAX_COLUMN = 20;
const char USER_CHAR = 'O';
const char COMP_CHAR = 'X';

// checks row and column, if it will be a square table return true,false
extern bool isTable(int row, int column);

// take input from player and fill row and column value,if they true
extern bool takeInput(int* row, int* column);

// updates row and column number of created table.
extern void createBoard(int board[][MAX_COLUMN], int row, int column);

//prints board on termina
extern void printBoard(int board[][MAX_COLUMN], int row, int column);

// starts game
extern void playGame(int board[][MAX_COLUMN], int row, int column);

//controls the movement is available or not
extern bool movePlayer(int board[][MAX_COLUMN], int row, int column, tCoordinat move, ePlace attacker);

//will find all available movement and will return best coordinat
extern tCoordinat findBestAttack(int board[][MAX_COLUMN], int row, int column, ePlace whoPlay);

//precond: this func. will called from find best attacke
//postcond : will find number of eaten bait accordig to coordinats and will store in 'value'
extern void findEatenEnemy(int board[][MAX_COLUMN], int row, int column, int& value, int x, int y, int xRate, int Yrate, ePlace player);

// if new_coord different from the actual coordinat, there is a path and this function will draw/eat baits
extern void drawPath(int board[][MAX_COLUMN], int row, int column, int x, int y, int xRate, int yRate, ePlace player, tCoordinat& new_coord);

// outputs the game score
extern void outputScore(int board[][MAX_COLUMN], int row, int column);

#endif	/* REVERSI_H */
