#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <string>
#include "Ship.h"

using namespace std;

class Submarine : public Ship {
private: 
    static const int LEN = 1;
    static const char SYMBOL = 'S';
public:
    Submarine(int bowRow, int bolCol, bool isHorizontal) : Ship(LEN, SYMBOL, bowRow, bolCol, isHorizontal) {}
};

#endif