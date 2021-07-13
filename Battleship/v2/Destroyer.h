#ifndef DESTORYER_H
#define DESTORYER_H

#include <string>
#include "Ship.h"

using namespace std;

class Destroyer : public Ship {
private: 
    static const int LEN = 2;
    static const char SYMBOL = 'D';
public:
    Destroyer(int bowRow, int bolCol, bool isHorizontal) : Ship(LEN, SYMBOL, bowRow, bolCol, isHorizontal) {}
};

#endif