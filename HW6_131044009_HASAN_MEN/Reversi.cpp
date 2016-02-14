/* 
 * File:   Reversi.cpp
 * Author: hmenn - HASAN MEN - 131044009
 *
 * Created on November 29, 2015, 10:49 PM
 * Bu dosya reversi clasina ait fonksiyonlari icerir.
 * Oyun icin gerekli tum fonksiyonlar implement edelmistir.
 * Iyi oyunlar.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Cell.h"
#include "Reversi.h"

//#define DEBUG

namespace {
  using std::string;

  // sadece aaa bb dddd stringleri olusturmak icin kullanilacak

  string& fillStr(string& temp, int i) {
    int base = i / 26;
    int mod = i % 26;
    temp.erase();
    temp.push_back(char(mod) + 'a');
    while (base) {
      temp.push_back(char(mod) + 'a');
      base = base / 26;
    }
    return temp;
  }
};


namespace HmennReversi {

  int Reversi::m_livingReversi = 0;

  using std::cout;
  using std::cin;
  using std::endl;
  using std::cerr;
  using std::ostream;

  Reversi::~Reversi() {
    delete [] m_gameCells;
    m_gameCells = NULL; //dangling pointer
    --m_livingReversi;
  }

  Reversi::Reversi() {

    // BU FONKSIYONDADA RESIZE KULLANILABILIR - CESITLILIK ICIN BIRAZ UZUN 
    // TANIMLANILMISTIR
    setWidth(defWidth);
    setHeight(defHeight);

    int midRow = getHeight() / 2 - 1;
    int midCol = getWidth() / 2 - 1;

    //def cell const. ile hepsi '.' ile dolduruldu
    m_gameCells = new Cell[getHeight() * getWidth()];

    for (unsigned int i = 0; i < getHeight(); ++i)
      for (unsigned int j = 0; j < getWidth(); ++j) {
        m_gameCells[i * getHeight() + j].setAll(j, i, empty);
      }

    // oraya user ve computer icin baslangic eklendi
    m_gameCells[midRow * getHeight() + midCol].setPlayer(computer);
    m_gameCells[midRow * getHeight() + midCol + 1].setPlayer(user);
    m_gameCells[(midRow + 1) * getHeight() + midCol].setPlayer(user);
    m_gameCells[(midRow + 1) * getHeight() + midCol + 1].setPlayer(computer);

    ++m_livingReversi; // canli reversi sayisi +1

  }

  Reversi::Reversi(const Reversi& other) {
    setHeight(other.getHeight());
    setWidth(other.getWidth());

    m_gameCells = new Cell[getHeight() * getWidth()];
    for (unsigned int i = 0; i < getHeight() * getWidth(); ++i)
      m_gameCells[i] = other.m_gameCells[i];

    ++m_livingReversi;
  }

  // resize fonksiyonum cok yonlu bir fonksiyon oldu diger isleride buna yiktim
  // var olan resize ile yeniden olusturur gibi olustur. code-reuse icin lazim

  Reversi::Reversi(int newCol, int newRow) {
    // null verdim ki resize fonksiyonu kullaninca gidip olmayan
    // yere erisip segmentation fault almasın diye
    // code-reuse icin ufak bir oyun oynadim
    //m_gameCells = new Cell; (gecici bir cellde koyulabilir))

    m_gameCells = NULL;
    resizeGame(newCol, newRow);
    ++m_livingReversi;
  }

  void Reversi::setWidth(int x) {
    if (x < 4) {
      cout << "Invalid new width, I will do it 4." << endl;
      m_maxWidth = 4;
    } else m_maxWidth = x;
  }

  void Reversi::setHeight(int y) {
    if (y < 4) {
      cout << "Invalid new height, I will do it 4." << endl;
      m_maxHeight = 4;
    } else m_maxHeight = y;
  }

  int Reversi::getHeight() const {
    return m_maxHeight;
  }

  int Reversi::getWidth() const {
    return m_maxWidth;
  }

  ostream& operator<<(ostream& out, const Reversi& board) {
    int row = board.getHeight();
    int col = board.getWidth();

    // satir basindaki ve x coordinatlari kayiyor onlari sonra duzenle @hmenn_back
    string cols;
    cout << " ";
    for (int i = 0; i < col; ++i)
      cout << " " << fillStr(cols, i); // from unnamed namespace
    cout << endl;

    for (unsigned int i = 0; i < row; ++i) {
      out << i;
      for (unsigned int j = 0; j < col; ++j)
        out << " " << board.m_gameCells[i * row + j].getPlayer();
      out << endl;
    }

    return out;
  }

  bool Reversi::play(const Cell& attack) {

    Cell go;
    int step = 0;

    cout << "Attack : " << attack.getPlayer()
            << " Row : " << attack.getRowCoord()
            << " Column : " << attack.getColCoord() << endl;
    // find cell in board and if available play game

    // if cell not empty go out
    if (m_gameCells[attack.getRowCoord() * getHeight() + attack.getColCoord()].getPlayer() != empty)
      return false;


    bool foundWay = false;
    int xRate = 0;
    int yRate = 0;

    // look down - calcualte number of x 
    // if there is enemy draw the path
    xRate = 0;
    yRate = 1;
    // look x-computer
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) { // belirtilen yonde dusman
      drawPath(go, xRate, yRate, step); // draw X to O
      foundWay = true;
    }

    //look up
    xRate = 0;
    yRate = -1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }

    //look left
    xRate = -1;
    yRate = 0;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look right

    xRate = 1;
    yRate = 0;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look right-down
    xRate = 1;
    yRate = 1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look right-up
    xRate = 1;
    yRate = -1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look left-down
    xRate = -1;
    yRate = 1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }
    //look left-up
    xRate = -1;
    yRate = -1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, user);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPath(go, xRate, yRate, step);
      foundWay = true;
    }


    if (foundWay) { // dusman bulundu ve hamle yapildi o zaman asil hucreyi al
      m_gameCells[attack.getRowCoord() * getHeight() + attack.getColCoord()].setPlayer(user);
    } else return false;

    return true;
  }

  int Reversi::isTherePath(const Cell& player, int xRate, int yRate)const {

    int temp = 0; // bulunan dusman sayisi
    int amount = 0; // toplam gecerli dusman sayisi 
    char wanted;
    Cell tmpCell = player;

    char attacker = tmpCell.getPlayer();
    if (attacker == computer)
      wanted = user;
    else wanted = computer;

    // Dusmanlari gordukce saymaya devam
    while (isInBoard(tmpCell) && whoPlaceInReal(tmpCell) == wanted) {
      temp++;
      tmpCell.setColCoord(tmpCell.getColCoord() + xRate);
      tmpCell.setRowCoord(tmpCell.getRowCoord() + yRate);
    }

    // belli birseyler buldu ama koseyede carpmıs olabilir
    // eger son buldugu kendisi ise dogru yoldur ve yem sayisini return eder
    if (isInBoard(tmpCell) && whoPlaceInReal(tmpCell) == attacker)
      amount = temp;

    return amount;
  }

  // DRAW PATH VE DRAW PATHCOMP AYNIDIR 
  //PARAMETRELERİ UZATMAMAK ICIN AYNI YAZILDI
  // CELL ICIN constuctor ve assignment gosterildi

  void Reversi::drawPath(const Cell& attack, int xRate, int yRate, int step) {
    Cell temp(attack); // copy constructor
    for (int i = 0; i < step; ++i) {
      m_gameCells[temp.getRowCoord() * getHeight() + temp.getColCoord()].setPlayer(user);
      temp.setAll(temp.getColCoord() + xRate, temp.getRowCoord() + yRate, computer); // to find next x sign
    }
  }

  void Reversi::drawPathForComp(const Cell& attack, int xRate, int yRate, int step) {
    Cell temp = attack; // assignment operator
    for (int i = 0; i < step; ++i) {
      m_gameCells[temp.getRowCoord() * getHeight() + temp.getColCoord()].setPlayer(computer);
      temp.setAll(temp.getColCoord() + xRate, temp.getRowCoord() + yRate, user);
    }
  }

  bool Reversi::isInBoard(const Cell & item)const {
    // once tablo icindemi diye bakilir

    if (item.getColCoord() >= 0 && item.getColCoord() < getWidth() &&
            item.getRowCoord() >= 0 && item.getRowCoord() < getHeight()) {
      return true;
    } else return false;
  }

  char Reversi::whoPlaceInReal(const Cell& object)const {
    return m_gameCells[object.getRowCoord() * getHeight() + object.getColCoord()].getPlayer();
  }

  const Cell Reversi::findBestAttack(const char whoPlay)const {

    Cell checkCell;
    Cell maxCell;
    int max = 0;

    if (!(whoPlay == computer || whoPlay == user)) {
      cerr << "Please. Dont attack game functions." << endl;
      exit(1);
    }

    for (unsigned int i = 0; i < getHeight(); ++i) {
      for (unsigned int j = 0; j < getWidth(); ++j) {

        checkCell.setAll(j, i, whoPlay);

        // if cell is empty
        if (m_gameCells[i * getHeight() + j].getPlayer() == empty) {

          // look down
          int xRate = 0;
          int yRate = 1;
          int numOfEat = 0;
          int temp = 0;

          checkCell.setAll(j + xRate, i + yRate, whoPlay); // update cell
          temp = isTherePath(checkCell, xRate, yRate); // look path is valid
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play down" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }


          //look up
          xRate = 0;
          yRate = -1;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play up" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }
          //look left
          xRate = -1;
          yRate = 0;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play left" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }
          // look right
          xRate = +1;
          yRate = 0;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play rigth" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }
          // look right-up
          xRate = +1;
          yRate = -1;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play rigth up" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }
          // look right-down
          xRate = +1;
          yRate = +1;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play rigth down" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }
          // look left-up
          xRate = -1;
          yRate = -1;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play rigth" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }
          // look left-down
          xRate = -1;
          yRate = 1;
          checkCell.setAll(j + xRate, i + yRate, whoPlay);
          temp = isTherePath(checkCell, xRate, yRate);
          if (temp > 0) {
            numOfEat += temp;
#ifdef DEBUG
            cout << "I can play rigth" << i << "-" << j << "--->";
            cout << "Can Eat" << numOfEat << endl;
#endif
          }

          if (numOfEat >= max) {
            // will choice best coordinat to eat to much bait
            // i will improve this codes... ####
            max = numOfEat;
            maxCell.setAll(j, i, whoPlay);
          }
        }
      }
    }



    if (max == 0) // if there is no attack return a information :D
      maxCell.setAll(-1, -1, whoPlay);
    return maxCell;
  }

  void Reversi::whoWin() const {

    int userNum = 0;
    int compNum = 0;
    for (unsigned int i = 0; i < getHeight()*getWidth();++i) {
        if (m_gameCells[i].getPlayer() == computer)
          ++compNum;
        else if (m_gameCells[i].getPlayer() == user)
          ++userNum;
      }

    cout << "User : " << userNum << " --  Computer : " << compNum << endl;
    if (userNum > compNum)
      cout << "Congrats. You win :)" << endl;
    else if (userNum < compNum)
      cout << "Ohh nooo. You lose. Try again :(" << endl;
    else
      cout << "Woow you are good. Lets try.Next time there will a winner." << endl;
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }

  bool Reversi::isGameEnd() const {
    // there is no attack for computer and user

    if (findBestAttack(user).getColCoord() == -1 ||
            findBestAttack(computer).getColCoord() == -1) {
      return true;
    }
    return false;
  }

  bool Reversi::play() {
    int xRate = 0;
    int yRate = 0;
    int step = 0;

    Cell attack = findBestAttack('X'); // find best attack
    cout << "Best Attack = row: '" << attack.getRowCoord() << "' - column '" <<
            attack.getColCoord() << "' - who:" << attack.getPlayer() << endl;

    Cell go = attack;
    string tempStr;

    // there is no attack return false
    if (attack.getRowCoord() == -1)
      return false;

    bool foundWay = false;
    // look down
    xRate = 0;
    yRate = 1;
    // look if there is a player calculate num of them
    // and draw the path with computer cells
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer); // look player
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    //look up
    xRate = 0;
    yRate = -1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    //look left
    xRate = -1;
    yRate = 0;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    //look right
    xRate = 1;
    yRate = 0;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    //look right-down
    xRate = 1;
    yRate = 1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    //look right-up
    xRate = 1;
    yRate = -1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }
    //look left-down
    xRate = -1;
    yRate = 1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    //look left-up
    xRate = -1;
    yRate = -1;
    go.setAll(attack.getColCoord() + xRate, attack.getRowCoord() + yRate, computer);
    if ((step = isTherePath(go, xRate, yRate)) > 0) {
      drawPathForComp(go, xRate, yRate, step);
      foundWay = true;
    }

    if (foundWay) {
      m_gameCells[attack.getRowCoord() * getHeight() + attack.getColCoord()].setPlayer(computer);
    } else return false;
  }

  Reversi& Reversi::operator++() {
    play();
    // bu 3satir ileriye donuktur. @hmenn_undo
    //if (play()) // undo icin lazim - kis odevine hazirlik
    //previousGames.push_back(gameCells);
    return *this;
  }

  // plays one step for computer - postfix

  Reversi Reversi::operator++(int ignore) {
    Reversi temp = *this;
    play();
    //if (play()) -- undo icindir // ileriye donuk. @hmenn_undo
    //previousGames.push_back(gameCells);

    return temp;
  }

  // kullanıcı-pc arasindaki fark ne kadar buyukse kullanici daha iyidir

  bool Reversi::operator==(const Reversi & other)const {
    int userScore1 = 0;
    int compScore1 = 0;
    int userScore2 = 0;
    int compScore2 = 0;

    for (unsigned int i = 0; i < getHeight() * getWidth(); ++i) {
      if (this->m_gameCells[i].getPlayer() == computer)
        ++compScore1;
      else if(this->m_gameCells[i].getPlayer() == user)
        ++userScore1;
    }

    for (unsigned int i = 0; i < (other.getHeight())*(other.getWidth()); ++i) {
      if (other.m_gameCells[i].getPlayer() == computer)
        ++compScore2;
      else if(other.m_gameCells[i].getPlayer() == user)
        ++userScore2;
    }

    cout << "User-Computer in first game : " << userScore1 << "-" << compScore1 << endl;
    cout << "User-Computer in second game : " << userScore2 << "-" << compScore2 << endl;
    return (userScore1 - compScore1) > (userScore2 - compScore2);
  }

  Reversi& Reversi::operator=(const Reversi& other) {
    cout<<"asdasd";

    // kendini kendine atarken gereksiz islem ve hatalari onlemek
    if (this == &other)
      return *this;

    // boyutları farkli ise boyutunu guncelle
    if (!(this->getHeight() == other.getHeight() &&
            this->getWidth() == other.getWidth())) {
      this->setWidth(other.getWidth());
      this->setHeight(other.getHeight());
      delete [] m_gameCells;
      m_gameCells = new Cell[(this->getWidth())*(this->getHeight())];
    }

    // tek tek celleri aktar
    for (unsigned int i = 0; i < (this->getHeight())*(this->getWidth()); ++i)
      this->m_gameCells[i] = other.m_gameCells[i];
    // uzerinde calistigi objeyi dondur.
    return *this;
  }

  void Reversi::resizeGame(int newCol, int newRow) {
    // NULL veya boyutlar farkli ise ilklendirme yap
    // short circuit evaluationa dikkat !!! 
    if (m_gameCells == NULL || !(this->getHeight() == newRow &&
            this->getWidth() == newCol)) {

      this->setWidth(newCol);
      this->setHeight(newRow);

      if(m_gameCells!=NULL)
        delete [] m_gameCells;
      m_gameCells = new Cell[(this->getWidth())*(this->getHeight())];
    }

    // boyutlar guncellendi. Hucreleri sifirla ve oyuna hazirla
    this->setWidth(newCol);
    this->setHeight(newRow);
    int midRow = getHeight() / 2 - 1;
    int midCol = getWidth() / 2 - 1;

    for (unsigned int i = 0; i < getHeight(); ++i)
      for (unsigned int j = 0; j < getWidth(); ++j) {
        m_gameCells[i * getHeight() + j].setAll(j, i, empty);
      }

    m_gameCells[midRow * getHeight() + midCol].setPlayer(computer);
    m_gameCells[midRow * getHeight() + midCol + 1].setPlayer(user);
    m_gameCells[(midRow + 1) * getHeight() + midCol].setPlayer(user);
    m_gameCells[(midRow + 1) * getHeight() + midCol + 1].setPlayer(computer);
  }

  void Reversi::playGame() {

    cout << *this;

    bool changeGame = false;
    Cell attack;
    string xCoord;
    int yCoord;
    int newWidth;
    int newHeight;
    bool coordOkey = false;

    cout << "I load Width :" << getWidth() << " - Height : " << getHeight() << " a game." << endl;
    cout << "Do you wanna change table size : (y or anything)" << endl;

    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
      cout << "New Width :";
      cin>>newWidth;
      cout << "New Height :";
      cin>>newHeight;

      resizeGame(newWidth, newHeight);

      cout << "New sizes , Width :" << getWidth() << " - Height :" << getHeight() << endl;

      //////////////////////////////////

    }
    do { // return loop until user stop game or game ends 
      cout << *this;
      if (isGameEnd()) {
        changeGame = true;
        whoWin();
      } else {
        do {
          // go on until coordinats available
          cin>>attack;
          if (attack.getColCoord() == -1) {
            coordOkey = true;
            changeGame = true;
          } else {
            if (whoPlaceInReal(attack) == empty) {

              if (play(attack)) {
                coordOkey = true;
                cout << *this;
              } else {
                coordOkey = false;
              }
            } else {
              coordOkey = false;
              cout << "You can not play there. Please enter valid coordinat :" << endl;
            }
          }
        } while (!coordOkey);
        if (!changeGame)
          ++(*this); // computer play

      }
    } while (!changeGame);
  }
};