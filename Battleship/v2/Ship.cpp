#include "Ship.h"

int Ship::mapToHitIndex(int row, int col) {
    int r = bowRow(), c = bowCol();
    for (int i = 0; i < hits().size(); i++) {
        if (row == r && col == c) {
            return i;
        }

        if (isHorizontal()) {
            c++;
        } else {
            r++;
        }
    }

    // should never reach here
    return -1; 
}

bool Ship::shootAt(int row, int col) {
    if (isSunk())
        return false;

    if (isHit(row, col))
        return false;
    
    int hitIndex = mapToHitIndex(row, col);
    hits()[hitIndex] = 1;

    int cnt = 0;
    for (int hit : hits())
        cnt += hit;

    if (cnt == length())
        m_isSunk = true;

    return true;
}

bool Ship::isHit(int row, int col) {
    int hitIndex = mapToHitIndex(row, col);
    if (hitIndex == -1 || !hits()[hitIndex]) {
        return false;
    }

    return true;
}