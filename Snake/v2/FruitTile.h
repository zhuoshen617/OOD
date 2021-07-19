#ifndef FRUITTILE_H
#define FRUITTILE_H

#include "Tile.h"

class FruitTile : public Tile {
private:
    static const int SYMBOL = 'F'; 
public:   
	FruitTile() : Tile(SYMBOL) {}
};

#endif