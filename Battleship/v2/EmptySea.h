#ifndef EMPTYSEA_H
#define EMPTYSEA_H

#include <string>
#include "Ship.h"

using namespace std;

class EmptySea : public Ship {
private: 
    static const int LEN = 1;
    static const char SYMBOL = 'x';
public:
    EmptySea(int bowRow, int bolCol, bool isHorizontal) : Ship(LEN, SYMBOL, bowRow, bolCol, isHorizontal) {}
    virtual bool shootAt(int row, int col);
};

#endif