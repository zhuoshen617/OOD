#include <iostream>
#include <string>
#include <vector>
#include "Ocean.h"

using namespace std;

class BattleshipGame {
public:
    void play() {
        Ocean ocean;
        ocean.placeAllShipsRandomly();
        ocean.print();

        while (true) {
            int row = 0, col = 0;
            cout << "input: " << endl;
            cin >> row >> col;

            cout << "processing ... " << endl;
            if (!ocean.isValidPos(row, col))
                continue;

            ocean.shootAt(row, col);

            ocean.print();
            if (ocean.allShipSunk()) {
                cout << "You win! " << endl;
                break;
            }
        }
    }
};

int main()
{
    cout << "You are playing BattleShip." << endl;

    BattleshipGame game;
    game.play();

    cout << "Thank you for playing BattleShip." << endl;
    return 0;
}