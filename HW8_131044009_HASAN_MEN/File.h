/* 
 * File:   File.h
 * Author: Hasan MEN - 131044009
 *
 * Created on 18 Aralik 2015 Cuma, 18:47
 * Bu dosya abstract base classi ve namespace i icerir. Tum dosylar buradan
 * turemistir. 
 * 
 * FILE ICIN DESTRUCTORA GEREK YOKTUR
 */

#ifndef FILE_H
#define FILE_H

//#include "Time.h"
#include <set>
#include <string>

namespace GTU_HMENN {

    using std::string;
    using std::set; // sirali liste yapilacak
    using std::ostream;

    class File {
    public:
        // CONSTRUCTORS
        File();
        File(const File& orig);
        File(const string& newName, const string& newOwner, double newSize,
                const string& newTime, const string& newPath = "/root");

        // dosya adini ata
        void setName(const string& newName);

        //dosya sahibini ata
        void setOwner(const string& newOwner);

        //dosya boyutunu ata
        void setSize(int newSize);

        // son degistirme zamanini ata -- zamanlar deneme amaclidir
        void setTime(const string& newTime);

        //
        void setFileAll(const string& newName, const string& newOwner,
                double newSize, const string& newTime, const string& newPath);

        // dosya ismini dondur

        const string& getName()const {
            return m_name;
        }

        // son degisim zamanini dondur

        const string& getTime()const {
            return m_time;
        }

        //dosya sahibini dondur

        const string& getOwner()const {
            return m_owner;
        }

        // dosya boyutunu dondur

        double getSize()const {
            return m_size;
        }

        // dosya konumunu gunceller
        void updatePath(const string& newPath);

        // stream insertion
        friend ostream& operator<<(ostream& output, const File& dir);

        // dosya konumunu dondur

        const string& path()const {
            return m_path;
        }

        // dosya elemanlarini ekrana bas - stream insertion kullanir
        // param -> "a" -> gizli dosyalari goster
        // param -> "l" -> listeleyerek ayrintili goster
        // param -> "R" -> yinelemeli olarak tum icerigi goster
        // ls("Ral") gibi kullanilir
        virtual void ls(const string& param = "")const = 0;
        
        // Ismi girilen dosya varsa guncel path i ona gunceller.
        // Eger o isimde klasor yoksa root klasorunu return eder
        virtual File& cd(const string& go) = 0;
        
        //Parametre olarak alinan file turevi dosyalari aktif klasore ekler
        // kopyalama olmazsa false return eder
        virtual bool cp(const File& file) = 0;

    protected:

        // SET STL ICIN POINTER SIRALAMASI YAPACAK
        // SET ISIME GORE SIRALANMISTIR
        // SIRALAMA KUCUKTEN BUYUGEDIR
        class compareSTR {
        public:
            bool operator()(const File* lhs, const File* rhs) const {
                return lhs->getName() < rhs->getName();
            }
        };
               
        string m_path; //dosya konumu
        string m_name; // dosya ismi
        string m_owner; // dosya sahibi
        double m_size; // dosya boyuru
        string m_time; // dosya son degisim zamani
    }; // end of class

}//end of GTU_HMENN

#endif /* FILE_H */

