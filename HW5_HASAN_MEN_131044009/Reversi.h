/*
 * File:   Reversi.h
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:20 AM
 * This file include reversi header
 */

#ifndef _MEN_131044009_REVERSI_H
#define	_MEN_131044009_REVERSI_H

#include "Cell.h"
using std::vector;

class Reversi {
public:
    Reversi();
    Reversi(const char* filename);
    Reversi(int width, int height);
    void readBoard(const char* filename);
    void writeBoard(const char* filename)const;

    int getWidth()const {
        return m_width;
    }

    int getHeight()const {
        return m_height;
    }
    void setWidth(int x);
    void setHeight(int y);
    friend std::ostream& operator<<(std::ostream& os, const Reversi& item);
    bool play(); // play for computer
    bool play(const Cell& attack); // play one step for user
    void playGame(); // plays all game

    static int getNumOfLivCells() {
        return numOfLivCells;
    }
    bool compare(const Reversi& other)const;

    Cell operator[](const std::string& pos) const;
    Cell operator()(const std::string& xPos, int yPos) const;

    Reversi operator--();
    Reversi operator--(int ignore);
    Reversi operator++();
    Reversi operator++(int ignore);
    Reversi operator+=(const Cell& attack);


private:
    vector<vector<vector<Cell> > > previousGames; // previous games(all games))
    bool isGameEnd()const; // checks game sitiation
    bool isInBoard(const Cell& item)const; // check cell is available
    int isTherePath(const Cell& attack, int xRate, int yRate)const; // control all sides
    void drawPath(const Cell& attack, int xRate, int yRate, int step); // draw available paths
    void drawPathForComp(const Cell& attack, int xRate, int yRate, int step);
    //finds best attack for computer
    const Cell findBestAttack(const char whoPlay)const;
    // find attack cell end replace it with new placer
    void reDrawGameCell(const Cell& attack, char newPlacer);
    std::string& fillStr(std::string& temp, int i)const;
    void dispVec()const; // it is test fonction for programmer.Not important
    void pushCell(const Cell& item); // adds new cell in board;
    void whoWin() const; // checks the winner and show resuly on screen;
    vector<vector<Cell> > gameCells;
    static int numOfLivCells;
    int m_width;
    int m_height;

};
#endif	/* REVERSI_H */