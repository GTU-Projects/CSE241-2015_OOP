/*
 * File:   Cell.h
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:20 AM
 * This file include cell header
 */

#ifndef __H_CELL_HMENN
#define	__H_CELL_HMENN

using std::string;

class Cell {
public:
    Cell();
    Cell(int xCoord, int yCoord, char whoPlace);
    Cell(const Cell& other);
    bool input();
    bool setX(int xCoord);
    bool setY(int yCoord);
    bool setPlacer(char whoPlace);
    void set(int xCoord, int yCoord, char whoPlace);
    int getX()const {return m_x;}
    int getY()const {return m_y;}
    char getPlacer()const {return m_whoPlace;}
    bool compareCell(const Cell& other)const;
    void output()const;
private:
    int strToInt(const string& str)const;
    int m_x;
    int m_y;
    char m_whoPlace;
};

#endif	/* CELL_H */