/* 
 * File:   Reversi.h
 * Author: hmenn - HASAN MEN - 131044009
 *
 * Created on November 29, 2015, 10:49 PM
 * Bu dosya reversi clasi ve namespacelere ait fonksiyonları icerir
 * 
 */

#include "Cell.h"

#ifndef REVERSI_H
#define	REVERSI_H

namespace {
    using std::string;
    string& fillStr(string& temp, int i);
}

namespace HmennReversi {

    typedef Cell* CellPtr;
    const int defWidth = 4;
    const int defHeight = 4;
    using std::ostream;
    using std::string;

    class Reversi {
    public:
        Reversi();
        Reversi(const Reversi& other); //copy const
        Reversi(int col, int row);
        virtual ~Reversi();

        inline int getWidth()const;
        inline int getHeight()const;
        void setWidth(int row);
        void setHeight(int column);
        friend ostream& operator<<(ostream& out, const Reversi& board);

        bool play(); // bilgisayar icin hamle yapmaya calisir
        bool play(const Cell& attack); // gelen celle hamle yapmaya calisir
        void playGame(); // oyunun ana dongusunu dondurur

        // canli reversi sayisini return edecek
        static int getNumLivingRev(){return m_livingReversi;} 

        Reversi& operator=(const Reversi& other); // assignment operator
        bool operator==(const Reversi& other)const;

        Reversi& operator++(); //return *this
        Reversi operator++(int ignore);

    private:
        void resizeGame(int newCol, int newRow); // oyunu yeniden olusturur
        char whoPlaceInReal(const Cell& object)const; // tablodaki cellde kim var
        bool isInBoard(const Cell& item)const; // hucerin gecerliligini kontrol eder
        bool isGameEnd()const; // oyunun durumunu kontrol eder
        /*
         *Bu fonksiyon aldigi koorinatin etrafina bakar
         * koorinati x y oranlarina gore gunceller. Dusmanı buldugunda yani yol
         * varsa kac adimlik yol oldugunu return eder.         * 
         */
        int isTherePath(const Cell& attack, int xRate, int yRate)const;

        /*
         * Girilen coordinati step kadar guncelleyerek yani ilerleyerek orada
         * oturan hucreyi usere gore gunceller
         */
        void drawPath(const Cell& attack, int xRate, int yRate, int step);

        // drawPath in aynisidir. bilgisayara gore gunceller
        void drawPathForComp(const Cell& attack, int xRate, int yRate, int step);

        /* Tablodaki tum uygun-bos koordinatlar uzerinde isTherePath ile
         * kontrol saglar ve en cok yol olan hucreyi return eder.
         */
        const Cell findBestAttack(const char whoPlay)const;

        // oyunu kazanan kisinin bilgilerini ekrana basar
        void whoWin() const;

        // tum hucreler tek boyutlu array uzerinde yer alacak
        CellPtr m_gameCells;

        // canli oyun sayisi
        static int m_livingReversi;

        int m_maxHeight; // tablo uzunlugu
        int m_maxWidth; // tablo genisligi
    };
}

#endif	/* REVERSI_H */