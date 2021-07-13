#include "EmptySea.h"

bool EmptySea::shootAt(int row, int col) {
    if (isSunk())
        return false;

    isSunk() = true;
    hits()[0] = 1;
    return false;
}
