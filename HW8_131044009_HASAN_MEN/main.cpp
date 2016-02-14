/* 
 * File:   main.cpp
 * Author: Hasan MEN - 131044009
 *
 * Created on 18 Aralik 2015 Cuma, 18:45
 * Bu dosya FILE - DIRECTORY -EXECUTABLE -TEXT CLASSLARI ICIN TESTLER ICERIR
 */

#include <cstdlib>
#include <iostream>
#include <set>
#include "Time.h"
#include "File.h"
#include "Executable.h"
#include "Directory.h"  
#include "TextFile.h"

using namespace std;

int main(int argc, char** argv) {
    using namespace GTU_HMENN;
    {

        // KULLANILACAK BAZI ORNEKLER OLUSTURULDU
        Directory mydir("RootDir", "root", 5, "2/15/1995");

        Executable exe(".secret1", "hmenn", 2, "2/7/1885", "NetBeans");
        Executable exe1(".secret2", "hmenn", 4, "2/5/2014", "Eclipse");
        Executable exe2("ExecOnes", "hmenn", 728, "20/2/2015", "VisualStudio");
        Executable exe3("ExecTwos", "hmenn", 1, "25/9/1885", "Android Studio");
        Executable exe4("ExecThrees", "hmenn", 758, "5/3/1885", "NetBeans");
        TextFile txt1("TextTexts", "GTU", 1, "21/01/1997", "UNICODE");
        TextFile txt2(".TextTexts", "GTU", 1, "18/11/2013", "ASCII");

        // Ayni dosyalar eklenmeyecek ve sirali sekilde listeye koyulacak

        mydir.cp(exe);
        mydir.cp(exe2);
        mydir.cp(txt1);
        mydir.cp(exe); //same
        mydir.cp(exe1);
        mydir.cp(exe3);
        mydir.cp(exe4);
        mydir.cp(txt2);


        // yeni klasor yapip icine dosya ekleyelim
        Directory dir("TempDirr", "hmenn", 55, "4/9/2015");
        dir.cp(exe);
        dir.cp(exe4);
        dir.cp(txt1);


        mydir.cp(dir); // root dizini altina klasor ekle - cd olmadan

        
        Directory secDir("USR\t", "GTU", 99, "20/12/2015");
        secDir.cp(txt1);
        secDir.cp(exe);
        secDir.cp(exe3);
        // dirin kopyasi mydire atildi
        dir.cp(secDir); // Bagimsiz copy alindi

        // ana klasorde secdir olmayacak
        mydir.ls("alR");

        cout << "################################" << endl;
        cout << "################################" << endl;
        cout << "Test for Undependent COPY" << endl;
        dir.ls("alR"); // secdir asil olmasi gereken yerde duruyor

        cout << "---- MINI TEST FOR SECRET FILES IN USR" << endl;
        dir.ls("a");


        cout << "################################" << endl;
        cout << "################################" << endl;
        cout << "Test for CD Command" << endl;
        File* MOVE = NULL;

        MOVE = &(mydir.cd("TempDir2r"));
        cout << "Cannot find TempDir2r in root and return root folder." << endl;
        MOVE->ls("l");

        cout << "----------------" << endl;
        MOVE = &(mydir.cd("TempDirr"));
        cout << "Find TempDirr" << endl;
        MOVE->ls("l");

        cout << "---- MINI STEP ----" << endl;
        cout << "Lets add new directory in tempdirr after go new file"
                << "and add newtext file in here" << endl;

        // dosya yap ve dosyaya gir
        Directory newD("DOSYA", "hm", 1, "24/01/2015");
        MOVE->cp(newD);
        MOVE = &(MOVE->cd("DOSYA")); // pointeri guncelle

        // iceri text ekle ve son durumu ekrana bas
        TextFile txt3("TEXTTEXT", "GTU", 5, "11/9/2011", "ASCII");
        MOVE->cp(txt3);
        MOVE->ls("lR");

        MOVE = NULL; // dangling pointer
        
    }// destructorlar calisacak
    // bazen calismadan return atabiliyor kesinlik olsun 
    return 0;
}
/* END OF HW8_HASAN_MEN_131044009 */

