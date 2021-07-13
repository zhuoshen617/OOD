#include "EmptySea.h"


bool EmptySea::shootAt(int row, int col) {
    isSunk() = true;
    hits()[0] = 1;
    return false;
}
