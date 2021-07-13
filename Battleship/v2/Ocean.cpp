#include "Ocean.h"
#include "Ship.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "EmptySea.h"
#include "Submarine.h"

Ocean::Ocean() {
    ships().resize(NUM_OF_ROW);
    for (int i = 0; i < NUM_OF_ROW; i++){
        ships()[i].resize(NUM_OF_COL);
        for (int j = 0; j < NUM_OF_COL; j++) {
            int bowRow = i;
            int bowCol = j;
            bool isHorizonal = false;
            Ship * e = new EmptySea(bowRow, bowCol, isHorizonal); // this is no good, memory leak
            ships()[i][j] = e;
        }
    }

    placeAllShipsRandomly();
}

void Ocean::placeAllShipsRandomly() {
    //Place larger ships before smaller ones
    //Otherwise, you may end up with no legal place to put a large ship

    //We are placing a fixed board
    // ----------
    // -xxx--x---
    // ------x--x
    // x-xxx----x
    // ----------
    // -x--x--x--
    // -x-------x
    // ---------x
    // ---------x
    // x--------x

    typedef pair<int, int> P;
    //say we put battleship at 0,0 horizontally, should use rand()
    vector<vector<P>> b = {{{6,9},{7,9},{8,9},{9,9}}};
    for (auto & v : b) {
        int bowRow = v[0].first;
        int bowCol = v[0].second;
        bool isHorizonal = false;
        Ship * battleship = new Battleship(bowRow, bowCol, isHorizonal);
        for (auto & p : v) {
            ships()[p.first][p.second] = battleship;
        }        
    } 

    vector<vector<P>> c = {{{1,1},{1,2},{1,3}}, {{3,2},{3,3},{3,4}}};
    for (auto & v : c) {
        int bowRow = v[0].first;
        int bowCol = v[0].second;
        bool isHorizonal = true;
        Ship * cruiser = new Cruiser(bowRow, bowCol, isHorizonal);
        for (auto & p : v) {
            ships()[p.first][p.second] = cruiser;
        }        
    } 
    
    vector<vector<P>> d = {{{1,6},{2,6}}, {{2,9},{3,9}}, {{5,1},{6,1}}};
    for (auto & v : d) {
        int bowRow = v[0].first;
        int bowCol = v[0].second;
        bool isHorizonal = false;
        Ship * destroyer = new Destroyer(bowRow, bowCol, isHorizonal);
        for (auto & p : v) {
            ships()[p.first][p.second] = destroyer;
        }        
    } 

    vector<vector<P>> s = {{{3,0}}, {{5,4}}, {{5,7}}, {{9,0}}};
    for (auto & v : s) {
        int bowRow = v[0].first;
        int bowCol = v[0].second;
        bool isHorizonal = false;
        Ship * submarine = new Submarine(bowRow, bowCol, isHorizonal);
        for (auto & p : v) {
            ships()[p.first][p.second] = submarine;
        }        
    } 
}

void Ocean::shootAt(int row, int col) {
    shotsFired()++;
    if (ships()[row][col]->shootAt(row, col)) {
        hitCount()++;
        if (ships()[row][col]->isSunk()) {
            shipsSunk()++;
        }
    }
}

bool Ocean::isValidPos(int row, int col) {
    if (row < 0 || row >= NUM_OF_ROW || col < 0 || col >= NUM_OF_COL)
        return false;

    return true;
}

void Ocean::print() {
    for (int i = 0; i < NUM_OF_ROW; i++) {
        for (int j = 0; j < NUM_OF_COL; j++) {
            if (ships()[i][j]->isHit(i, j)) {
                cout << ships()[i][j]->symbol();
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << "ShipsSunk: " << shipsSunk() << "/10 ShotsFired: " << shotsFired() << " HitCount: " << hitCount() << endl;
}