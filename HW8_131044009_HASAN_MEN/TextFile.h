/* 
 * File:   TextFile.h
 * Author: Hasan MEN - 131044009
 *
 * Created on 18 Aralik 2015 Cuma, 19:09
 * Bu dosya text clasinin prototipini icerir
 * TEXT FILE DAN TUREMISTIR
 * ISLERIN COGUNU FILE HALLETMEKTEDIR
 */

#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "File.h"

namespace GTU_HMENN {
    using std::cout;

    class TextFile : public File {
    public:
        // constructorlar
        TextFile();
        TextFile(const TextFile& orig);
        TextFile(const string& newName, const string& newOwner,
                double newSize, const string& newTime,
                const string& newType, const string& newPath = "/root");

        // text dosyasi turunu set eder
        // ascii unicode ornek tiplerdir
        void setType(const string& newType);

        // text dosyasini turunu return eder

        const string& getType()const {
            return m_textType;
        }

        // FILE DAN DERIVE EDILDILER AMA TAM CALISMAYACAKLAR
        virtual void ls(const string& param = "")const;
        virtual File& cd(const string& go);
        virtual bool cp(const File& file);

        friend ostream& operator<<(ostream& output, const TextFile& text);


    private:
        string m_textType; // text turu -> asci/unicode/uts8 ...
    };
}//end of GTU_HMENN
#endif /* TEXTFILE_H */

