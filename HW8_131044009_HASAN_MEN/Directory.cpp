/* 
 * File:   Directory.cpp
 * Author: Hasan MEN - 131044009
 * 
 * Created on 18 Aralik 2015 Cuma, 18:57
 * Bu dosya Directory implementasylarini icerir
 * DAHA IYI KULLANIM ICIN FILE INTERFACE DOSYASINI OKUYUNUZ
 */

#include <iostream>
#include <cstdlib>
#include <set>
#include <string>
#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"

namespace GTU_HMENN {
    using std::endl;
    using std::set;
    using std::cout;
    using std::string;

    int Directory::numOfIn = 0;

    //default constuctor

    Directory::Directory() : File() {
    }

    // parameter constructor

    Directory::Directory(const string& newName, const string& newOwner,
            double newSize, const string& newTime, const string& newPath) :
    File(newName, newOwner, newSize, newTime, newPath) {
    }

    //copy constructor

    Directory::Directory(const Directory& orig) :
    File(orig.getName(), orig.getOwner(), orig.getSize(), orig.m_time, orig.path()) {
        for (setFileItr itr = orig.m_inFiles.begin(); itr != orig.m_inFiles.end(); ++itr)
            this->cp(**itr); // klasor icinde klasor dosya atamasini cp ye birak
    }

    // disctructor yazilacak
    // MAALESEF AZICIK MEMORY LEAK VAR GIBI
    // YEDEK FONKSIYON ILE SILMEYE CALISILDI
    // UFAK FOR VE RECURSIVE GIBI OLDU
    // EN KOTU USTTEN BI TEMIZLIK YAPALIM

    Directory::~Directory() {
        setFileItr itr = m_inFiles.begin();
        Directory *temp;

        for (; itr != m_inFiles.end(); ++itr)
            if (NULL != (temp = dynamic_cast<Directory*> (*itr)))
                deleteDir(*temp); // KLASOR ISE ICINI SILMEYE CALIS
            else delete *itr; // normal dosya ise direk free et

        temp = NULL; // dangling
    }

    void Directory::deleteDir(const Directory& dir) {
        Directory* temp;
        setFileItr itr = dir.m_inFiles.begin();

        for (; itr != dir.m_inFiles.end(); ++itr)
            if (NULL != (temp = dynamic_cast<Directory*> (*itr)))
                deleteDir(*temp); // kendini cagir klasorler bitene kadar
            else delete *itr;

        temp = NULL; //dangling        
    }


    // klasor icerigini ekrana basar

    void Directory::ls(const string& param)const {
        //   ayrintili yaz    -- icerde ne varsa yaz
        bool longList = false, recursive = false;

        for (unsigned int i = 0; i < param.size(); ++i) {
            switch (param.at(i)) {
                case 'l': longList = true;
                    break;
                case 'R': recursive = true;
                    break;
                default: break;
            }
        }
        cout << "\t\t\nFile ->";
        if (longList) // ls cagirilan klasoru bas
            cout << *this << endl;
        else cout << getName() << endl;
        // dosya konumunu bas
        cout << "(" << path() << ")" << endl;

        cout << "-------------------------------------"
                << "--------------------------" << endl;
        cout << "NAME\t\tUSER\tSize\tLast Time\tCompiler/CODE" << endl;
        cout << "-------------------------------------"
                << "--------------------------" << endl;

        // containerin basini goster
        setFileItr itr = m_inFiles.begin();
        Directory* temp;
        // look all elements

        // sadece ussten dosyalari falan bas
        for (; itr != m_inFiles.end(); ++itr) {
            temp = dynamic_cast<Directory*> (*itr);
            if (temp != NULL) { // klasorun varsa adini tek bas
                std::cout << *temp << endl;
            } else (*itr)->ls(param); // klasor degilse icini bas
        }

        // recursive durumunda ic klasorler icin ls cagirimi yap
        if (recursive) // teker teker klasorleri bas
            for (itr = m_inFiles.begin(); itr != m_inFiles.end(); ++itr) {
                temp = dynamic_cast<Directory*> (*itr);
                if (temp != NULL) // klasorun bilgisini bas
                    (*itr)->ls(param); // klasorun icindekileride bas

            }
        temp = NULL; // dangling pointer
    }

    // konumu gunceller

    File& Directory::cd(const string& go) {

        setFileItr temp = m_inFiles.begin();
        Directory *here = NULL;

        for (; temp != m_inFiles.end(); ++temp) {
            here = dynamic_cast<Directory*> (*temp); // klasor mu 
            if (here != NULL) // klasor var ama adi aynimi bakalim
                if (here->getName() == go) {
                    return *here;
                }
        }
        here = NULL; // dangling pointers
        return *this; // klasor yoksa roota don
    }

    bool Directory::cp(const File& file) {

        // exe ise direk deep-independet copy al 
        const Executable *temp = dynamic_cast<const Executable *> (&file);
        if (temp != NULL) {
            Executable *nExe = new Executable(*temp);
            nExe->setTime("18/12/15"); // zamanlar temsilidir
            nExe->updatePath(this->path() + "/" + nExe->getName()); //path guncelle
            m_inFiles.insert(nExe); // containere sirali olarak ekle
        }

        // klasor ise copy constuctor ile o klasorun deep copy sini al
        const Directory *temp1 = dynamic_cast<const Directory *> (&file);
        if (temp1 != NULL) {
            Directory *nDir = new Directory(*temp1);
            nDir->setTime("19/12/15"); // zamanlar temsilidir
            nDir->updatePath(this->path() + "/" + nDir->getName()); // path upd.
            m_inFiles.insert(nDir);
        }

        // text dosyasi ise direk copy al
        const TextFile *temp2 = dynamic_cast<const TextFile *> (&file);
        if (temp2 != NULL) {
            TextFile *nText = new TextFile(*temp2);
            nText->setTime("21/12/15"); // zamanlar temsilidir
            nText->updatePath(this->path() + "/" + nText->getName());
            m_inFiles.insert(nText);
        }
        // dangling pointers
        temp = NULL;
        temp1 = NULL;
        temp2 = NULL;

        return true;
    }

    //ls icin kullanilmistir. LS fonksiyonuna bakabilirsiniz

    ostream& operator<<(ostream& output, const Directory& dir) {
        output << dir.getName() << "\t" << dir.getOwner() << "\t"
                << dir.getSize() << "\t" << dir.getTime();
        return output;
    }

}// end of GTU_HMENN
