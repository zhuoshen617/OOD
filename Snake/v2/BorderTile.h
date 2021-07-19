#ifndef BORDERTILE_H
#define BORDERTILE_H

#include "Tile.h"

class BorderTile : public Tile {
private:
    static const int SYMBOL = '#'; 
public:   
	BorderTile() : Tile(SYMBOL) {}
};

#endif
