/* 
 * File:   Directory.h
 * Author: Hasan MEN - 131044009
 *
 * Created on 18 Aralik 2015 Cuma, 18:57
 * Bu dosya directory sinifinin interfaceini icerir.
 * Directory file clasindan turemistir
 * DISTRUCTOR ICIN BIG THREE YAZILMISTIR
 */

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <set>
#include "File.h"


namespace GTU_HMENN {

    using std::ostream;
    typedef std::set<File*>::iterator setFileItr; // SET STL ITERATOR

    class Directory : public File {
    public:
        // CONSTRUCTORLAR
        Directory();
        Directory(const Directory& orig);
        Directory(const string& newName, const string& newOwner, double newSize,
                const string& newTime, const string& newPath = "/root");
        virtual ~Directory();
        void deleteDir(const Directory& dir);

        // FILE CLASS IMPLENTASYONUNU OKUYUNUZ
        virtual void ls(const string& param = "")const;
        virtual File& cd(const string& go);
        virtual bool cp(const File& file);

        friend ostream& operator<<(ostream& output, const Directory& dir);

        // icerdeki uye sayisini return eder

        static int getNumOfInside() {
            return numOfIn;
        }

    private:

        std::set<File*, compareSTR> m_inFiles; // container
        static int numOfIn; // cp calisinca artacak
    };

}//end of GTU_HMENN

#endif /* DIRECTORY_H */

