/* 
 * File:   File.cpp
 * Author: Hasan MEN - 131044009
 * 
 * Created on 18 Aralik 2015 Cuma, 18:47
 * Bu dosya base class (FILE ) in implementasyonunu icerir.
 * FONKSIYON AYRINTILARI ICIN FILE.H OKUYUN
 */

#include <cstdlib>
#include <iostream>
#include "File.h"


namespace GTU_HMENN {

    // ABDULLAH HOCANIN ONERISI - KISA YOL - BAYA KULLANISLI - UNUTMA**
    typedef std::set<File*>::iterator setFileItr; // set iterator

    // default constructor

    File::File() : m_name("NoName"), m_owner("USER"), m_size(0),
    m_time("1/1/1990"), m_path("/root") {
    }

    // copy constructor -> pointerler icin donusum sagliyor

    File::File(const File& orig) {
        updatePath(orig.path());
        setName(orig.getName());
        setOwner(orig.getOwner());
        setSize(orig.getSize());
        setTime(orig.getTime());
    }

    //parametreli constructor
    // path default olarak root belirlenmistir

    File::File(const string& newName, const string& newOwner, double newSize,
            const string& newTime, const string& newPath) {
        updatePath(newPath);
        setTime(newTime);
        setName(newName);
        setOwner(newOwner);
        setSize(newSize);
    }

    // dosya boyutunu set eder

    void File::setSize(int newSize) {
        if (newSize < 0) {
            std::cerr << "Size can not less then 0." << std::endl;
            exit(1);
        }
        m_size = newSize;
    }

    // dosya adi bazi ozel karakterlele baslamasini engeller

    void File::setName(const string& newName) {

        for (int i = 0; i < newName.size(); ++i) {
            char fChar = newName.at(i); // charss
            // NOKTO ILE BASLAYABILIR
            if (fChar == '/' || fChar == ',' || fChar == '=' || fChar == '_'
                    || fChar == '-') // can add somethings else
            {
                std::cerr << "Invalid file name!!!" << std::endl;
                exit(1);
            }
        }
        m_name = newName;
    }

    //dosya sahibinin adini kontrol eder ve atama yapar

    void File::setOwner(const string& newOwner) {
        for (int i = 0; i < newOwner.size(); ++i) {
            char fChar = newOwner.at(i); // charss
            if (fChar == '.' || fChar == '/' || fChar == ',' ||
                    fChar == '=' || fChar == '_'
                    || fChar == '-') // can add somethings else
            {
                std::cerr << "Invalid file owner!!!" << std::endl;
                exit(1);
            }
        }
        m_owner = newOwner;
    }

    // zamani atar

    void File::setTime(const string& newTime) {
        m_time = newTime;
    }

    // dosya konumunu gunceller

    void File::updatePath(const string& newPath) {
        m_path = newPath;
    }

    // ALLL SETTER

    void File::setFileAll(const string& newName, const string& newOwner,
            double newSize, const string& newTime, const string& newPath) {
        updatePath(newPath);
        setName(newName);
        setOwner(newOwner);
        setSize(newSize);
        setTime(newTime);
    }

    // steam insertion operator
    // tureyen turler static cast yaparak kullanabilir
    // temel dosya bilgilerini ekrana basar

    ostream& operator<<(ostream& output, const File& file) {
        output << file.getName() << "\t" << file.getOwner() << "\t"
                << file.getSize() << "\t" << file.getTime();
        return output;
    }

}//end of GTU_HMENN
