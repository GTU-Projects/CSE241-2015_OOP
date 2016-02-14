/*
 * File:   Executable.cpp
 * Author: Hasan MEN - 131044009
 * 
 * Created on 18 Aralik 2015 Cuma, 19:08
 * Bu dosya executable clasi icin implementasyonlari icerir
 * File.cpp ile baglantilidir
 */

#include <iostream>
#include <cstdlib>
#include "Executable.h"


namespace GTU_HMENN {

    // default construtor

    Executable::Executable() : File(), m_compiler("NoCompiler") {
    }

    // copy constructor

    Executable::Executable(const Executable& orig) :
    File(orig.getName(), orig.getOwner(), orig.getSize(), orig.getTime(), orig.path()) {
        setCompiler(orig.getCompiler());
    }

    // parameter constructor

    Executable::Executable(const string& newName, const string& newOwner,
            double newSize, const string& newTime,
            const string & newComp, const string& newPath) :
    File(newName, newOwner, newSize, newTime, newPath), m_compiler(newComp) {
    }

    // derleyicisini set eder

    void Executable::setCompiler(const string& newComp) {
        m_compiler = newComp;
    }

    // ayrintili exe dosyasini gosterir

    ostream& operator<<(ostream& output, const Executable& exe) {
        output << (static_cast<const File&> (exe)) << "\t" << exe.getCompiler() << std::endl;
        return output;
    }

    // parametre ye gore exeyi gosterir

    void Executable::ls(const string& param)const {
        bool all = false, longList = false;

        for (unsigned int i = 0; i < param.size(); ++i) {
            switch (param.at(i)) {
                case 'l': longList = true;
                    break;
                case 'a': all = true; // tum dosyalari goster
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

    // exe icin cp calistirilamaz
    // inherit edildi ama devre disi

    bool Executable::cp(const File& file) {
        std::cout << "YOU CANNOT COPY SOMETHING IN EXECUTABLE" << std::endl;
        return false;
    }

    // exe icin cd calistirilamaz
    // inherit edildi ama devre disi

    File& Executable::cd(const string& go) {
        std::cerr << "EXECUTABLE NOT A DIRECTORY.CD CANNOT MAKE MOVE." << std::endl;
        exit(1);
    }
}// end of GTU_HMENN

