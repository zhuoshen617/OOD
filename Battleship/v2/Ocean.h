#ifndef OCEAN_H
#define OCEAN_H

#include <vector>
#include <iostream>
#include <memory.h>
#include "Ship.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "EmptySea.h"
#include "Submarine.h"

class Ocean
{
private:
    vector<vector<Ship *>> m_ships;
    int m_shotsFired = 0;
    int m_hitCount = 0;
    int m_shipsSunk = 0;
public:
    static const int NUM_OF_ROW = 10;
    static const int NUM_OF_COL= 10;
    static const int TOTAL_SHIPS = 10;

    Ocean();
    
    vector<vector<Ship *>> & ships() {
        return m_ships;
    }

    int & shotsFired() {
        return m_shotsFired;
    }

    int & hitCount() {
        return m_hitCount;
    }

    int & shipsSunk() {
        return m_shipsSunk;
    }

    bool allShipSunk() {
        return shipsSunk() == TOTAL_SHIPS;
    }

    void placeAllShipsRandomly();

    void shootAt(int row, int col);
    
    bool isValidPos(int row, int col);
    
    void print();
};

#endif