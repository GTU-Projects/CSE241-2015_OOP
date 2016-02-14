/* 
 * File:   Cell.h
 * Author: hmenn - HASAN MEN - 131044009
 *
 * Created on November 29, 2015, 10:49 PM
 * Bu dosya oyun namespacesini ve hucre klasimizi icerir
 * 
 */

#ifndef _HMENN_CELL_H
#define	_HMENN_CELL_H

namespace HmennReversi {
    using std::istream;
    using std::ostream;

    const static char user = 'O';
    const static char computer = 'X';
    const static char empty = '.';

    class Cell {
    public:
        // Constructors
        Cell();
        Cell(int column, int row, char player);
        Cell(const Cell& other); // copy constructor

        // Setter fonksiyonlari
        bool setRowCoord(int newRowCoord);
        bool setColCoord(int newColCoord);
        bool setPlayer(char newPlayer);
        bool setAll(int cCoord, int rCoord, char player = user);

        // inline getter fonksiyonlari
        int getColCoord()const {
            return m_colCoord;
        }

        int getRowCoord()const {
            return m_rowCoord;
        }

        char getPlayer()const {
            return m_player;
        }

        bool operator==(const Cell& other)const; // 2 huceryi karsilastirir
        Cell& operator=(const Cell& other); // hucrelerin iceriklerini atar
        bool operator!=(const Cell& other)const; // esitsizlik durumuna bakar


        // cell icin stream insertion and extraction operator overloadlari
        friend istream& operator>>(istream& is, Cell& cell);
        friend ostream& operator<<(ostream& os, const Cell& cell);

    private:
        int m_rowCoord; // satir koordinati
        int m_colCoord; // sutun koordinati
        char m_player; // cell de bulunan hucre turu 
    };
}

namespace {
    // alinan stringin cell koordinati icin int turunden karsiligini verir
    int strToInt(const std::string& str);
}

#endif	/* CELL_H */

