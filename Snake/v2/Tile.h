#ifndef TILE_H
#define TILE_H

class Tile {
private:
    char m_symbol;
public:   
    Tile(char symbol) : m_symbol(symbol) {}
    char getSymbol() {
        return m_symbol;
    }
};

#endif