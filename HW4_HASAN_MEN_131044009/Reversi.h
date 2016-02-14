/*
 * File:   Reversi.h
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:20 AM
 * This file include reversi header
 */

#ifndef REVERSI_H
#define	REVERSI_H

#include "Cell.h"

using std::string;
using std::vector;

class Reversi {
public:
    Reversi();
    Reversi(const char* filename);
    Reversi(int width,int height);
    void readBoard(const char* filename);
    void writeBoard(const char* filename)const;
    int getWidth()const{return m_width;}
    int getHeight()const{return m_height;}
    void setWidth(int x);
    void setHeight(int y);
    void displayBoard()const;
    bool play();
    bool play(const Cell& attack);
    void playGame();
    static int getNumOfLivCells(){ return numOfLivCells;}
    bool compare(const Reversi& other)const;
    
    
private:
    bool isGameEnd()const;
    bool isInBoard(const Cell& item)const;
    int isTherePath(const Cell& attack,int xRate,int yRate)const;
    void drawPath(const Cell& attack,int xRate,int yRate,int step);
    void drawPathForComp(const Cell& attack, int xRate, int yRate,int step);
    const Cell findBestAttack(const char whoPlay)const;
    void reDrawGameCell(const Cell& attack,char newPlacer);
    string& fillStr(string& temp,int i)const;
    int strToInt(const string& str)const;
    void dispVec()const;
    void pushCell(const Cell& item);
    void whoWin()const;
    vector<vector<Cell> > gameCells;
    static int numOfLivCells;
    int m_width;
    int m_height;

};

#endif	/* REVERSI_H */

