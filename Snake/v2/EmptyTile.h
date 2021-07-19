#ifndef EMPTYTILE_H
#define EMPTYTILE_H

#include "Tile.h"

class EmptyTile : public Tile {
private:
    static const int SYMBOL = ' '; 
public:   
	EmptyTile() : Tile(SYMBOL) {}
};

#endif