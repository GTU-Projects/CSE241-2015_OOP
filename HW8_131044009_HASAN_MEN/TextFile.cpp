/* 
 * File:   TextFile.cpp
 * Author: Hasan MEN - 131044009
 * 
 * Created on 18 Aralik 2015 Cuma, 19:09
 * Bu dosya text clasinin implementasyonunu icerir
 * FILE.H FILE.CPP INCELEYIN
 */

#include <iostream>
#include <cstdlib>
#include "TextFile.h"

namespace GTU_HMENN {

    // default constructor

    TextFile::TextFile() : File(), m_textType("NoTYPE") {
    }

    // parameter consturcors

    TextFile::TextFile(const TextFile& orig) :
    File(orig.getName(), orig.getOwner(), orig.getSize(), orig.getTime(), orig.path()) {
        setType(orig.getType());
    }

    // parameter constuctor

    TextFile::TextFile(const string& newName, const string& newOwner,
            double newSize, const string& newTime,
            const string & newType, const string& newPath) :
    File(newName, newOwner, newSize, newTime, newPath), m_textType(newType) {
    }

    // set text type

    void TextFile::setType(const string& newType) {
        m_textType = newType;
    }

    ostream& operator<<(ostream& output, const TextFile& exe) {
        output << (static_cast<const File&> (exe)) << "\t" << exe.getType() << std::endl;
        return output;
    }

    // executable ile ayni icerige sahiptir

    void TextFile::ls(const string& param)const {
        bool all = false, longList = false;

        for (unsigned int i = 0; i < param.size(); ++i) {
            switch (param.at(i)) {
                case 'l': longList = true;
                    break;
                case 'a': all = true;
                default: break;
            }
        }
        if (all) // tum dosyalari bas
            if (longList) // l modunda bas
                std::cout << *this;
            else std::cout << getName() << std::endl; // sadece isim
        else if (getName().at(0) != '.') // gizlilik kontrolu yap 
            if (longList)
                std::cout << *this;
            else std::cout << getName() << std::endl;
    }

    // text dosyasina copy olamaz

    bool TextFile::cp(const File& file) {
        std::cout << "YOU CANNOT COPY SOMETHING IN TEXTFILE" << std::endl;
        return false;
    }

    // text dosyasina copy olamaz

    File& TextFile::cd(const string& go) {
        std::cerr << "TEXTFILE NOT A DIRECTORY.CD CANNOT MAKE MOVE." << std::endl;
        exit(1);
    }

}

