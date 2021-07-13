#ifndef CRUISER_H
#define CRUISER_H

#include <string>
#include "Ship.h"

using namespace std;

class Cruiser : public Ship {
private: 
    static const int LEN = 3;
    static const char SYMBOL = 'C';
public:
    Cruiser(int bowRow, int bolCol, bool isHorizontal) : Ship(LEN, SYMBOL, bowRow, bolCol, isHorizontal) {}
};

#endif