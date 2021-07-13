#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Ship
{
public:
    int m_bowRow;
    int m_bowCol;
    int m_length;
    bool m_isHorizontal;
    bool m_isSunk = false;
    char m_symbol;
    vector<int> m_hits;

    Ship(int len, char symbol, int bowRow, int bowCol, int isHorizontal)
        : m_symbol(symbol)
        , m_length(len)
        , m_bowRow(bowRow)
        , m_bowCol(bowCol)
        , m_isHorizontal(isHorizontal) {
        m_hits.resize(len, 0);
    }

    virtual ~Ship() {}

    int & length() {
        return m_length;
    }

    char & symbol() {
        return m_symbol;
    }

    vector<int> & hits() {
        return m_hits;
    }

    int & bowRow() {
        return m_bowRow;
    }

    int & bowCol() {
        return m_bowCol;
    }

    bool & isHorizontal() {
        return m_isHorizontal;
    }

    bool & isSunk() { 
        return m_isSunk;
    }

    virtual bool shootAt(int row, int col);

    int mapToHitIndex(int row, int col);

    bool isHit(int row, int col);
};

#endif