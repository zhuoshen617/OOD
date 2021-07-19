#ifndef SNAKETILE_H
#define SNAKETILE_H

#include "Tile.h"

class SnakeTile : public Tile {
private:
    static const int SYMBOL = 'o'; 
public:   
	SnakeTile() : Tile(SYMBOL) {}
};

#endif