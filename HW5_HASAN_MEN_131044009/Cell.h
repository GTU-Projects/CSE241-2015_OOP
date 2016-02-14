/*
 * File:   Cell.h
 * Author: hmenn - HASAN MEN 131044009
 *
 * Created on November 8, 2015, 1:20 AM
 * This file include cell header
 */

#ifndef _MEN_131044009_CELL_H
#define	_MEN_131044009_CELL_H

class Cell {
public:
    Cell();
    Cell(int xCoord, int yCoord, char whoPlace);
    Cell(const Cell& other);
    bool setX(int xCoord);
    bool setY(int yCoord);
    bool setPlacer(char whoPlace);
    void set(int xCoord, int yCoord, char whoPlace);

    int getX()const {
        return m_x;
    }

    int getY()const {
        return m_y;
    }

    char getPlacer()const {
        return m_whoPlace;
    }
    int strToInt(const std::string& str)const;

    bool operator<(const Cell& other)const;
    bool operator>(const Cell& other)const;
    bool operator>=(const Cell& other)const;
    bool operator<=(const Cell& other)const;
    bool operator==(const Cell& other)const; //
    bool operator!=(const Cell& other)const; //
    Cell operator++(); //
    Cell operator++(int ignore); //
    Cell operator--(); //
    Cell operator--(int ignore); //

    friend std::ostream& operator<<(std::ostream& os, const Cell& myCell); //
    friend std::istream& operator>>(std::istream& is, Cell& myCell);

private:

    int m_x;
    int m_y;
    char m_whoPlace;
};

#endif	/* CELL_H */