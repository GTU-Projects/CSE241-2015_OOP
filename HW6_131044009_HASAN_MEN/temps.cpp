//#################### CELL ######################

/*bool operator<(const Cell& other)const;
bool operator>(const Cell& other)const;
bool operator>=(const Cell& other)const;
bool operator<=(const Cell& other)const;
        
Cell& operator++(); //
Cell operator++(int ignore); //
Cell& operator--(); //
Cell operator--(int ignore); //   */

/*
    Cell& Cell::operator++() {
      setColCoord(getColCoord() + 1);
      setRowCoord(getRowCoord() + 1);
      return (*this);
    }

    Cell Cell::operator++(int ignore) {
      int xC = getColCoord();
      int yC = getRowCoord();

      setColCoord(getColCoord() + 1);
      setRowCoord(getRowCoord() + 1);
      return Cell(xC, yC, getPlayer());
    }

    Cell& Cell::operator--() {
      setColCoord(getColCoord() - 1);
      setRowCoord(getRowCoord() - 1);
      return (*this);
    }

    // take independent copy, make changes

    Cell Cell::operator--(int ignore) {
      int xC = getColCoord();
      int yC = getRowCoord();

      setColCoord(getColCoord() - 1);
      setRowCoord(getRowCoord() - 1);
      return Cell(xC, yC, getPlayer());
    }
 */
