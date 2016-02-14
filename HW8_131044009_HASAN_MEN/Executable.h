/* 
 * File:   Executable.h
 * Author: Hasan MEN - 131044009
 *
 * Created on 18 Aralik 2015 Cuma, 19:08
 * Bu dosya executable klasi icin prototipleri icerir
 * Executable file clasindan turemistir
 * FILE CLASS ini ayrintili inceleyin
 * 
 */

#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "File.h"

namespace GTU_HMENN {
    using std::ostream;

    class Executable : public File {
    public:
        // constructors 
        Executable();
        Executable(const Executable& orig);
        Executable(const string& newName, const string& newOwner,
                double newSize, const string& newTime,
                const string& newComp, const string& newPath = "/root");

        // executable  hangi derleyiciye ait oldugunu atar
        void setCompiler(const string& newComp);

        const string& getCompiler()const {
            return m_compiler;
        }

        // FILE DAN INHERIT EDILDI TAM OLARAK KULLANILMAYACAKLAR
        virtual void ls(const string& param = "")const;
        virtual File& cd(const string& go);
        virtual bool cp(const File& file);

        // stream insertion -> ls komutu icin 
        friend ostream& operator<<(ostream& output, const Executable& dir);

    private:
        string m_compiler;
    };
}//end of GTU_HMENN
#endif /* EXECUTABLE_H */

