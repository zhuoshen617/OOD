#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <string>
#include "Ship.h"

using namespace std;

class Battleship : public Ship {
private: 
    static const int LEN = 4;
    static const char SYMBOL = 'B';
public:
    Battleship(int bowRow, int bolCol, bool isHorizontal) : Ship(LEN, SYMBOL, bowRow, bolCol, isHorizontal) {}
};

#endif