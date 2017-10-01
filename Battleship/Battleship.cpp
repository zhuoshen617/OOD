#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

//this is a single player battleship game, coming from
//http://www.cis.upenn.edu/~matuszek/cit591-2013/Assignments/10-battleship.html

class Ship
{
public:
    int m_bowRow;
    int m_bowCol;
    int m_length;
    bool m_isHorizontal;
    bool m_isSunk;
    vector<int> m_hits;

    Ship(int len): m_length(len){
        m_hits.resize(len, 0);
    }

    virtual ~Ship() {}

    int getLength() {return m_length;}

    virtual string getShipType() = 0;

    virtual bool shootAt(int row, int column){

        if (m_isSunk)
            return false;

        //some logic here to check and mark hits array
        //...

        int cnt = 0;
        for (int hit : m_hits)
            cnt += hit;

        if (cnt == getLength())
            m_isSunk = true;

        return true;
    }

    virtual bool isSunk() { return m_isSunk;}
};

class Battleship : public Ship {
public:
    Battleship():Ship(4) {}
    string getShipType() {return "Battleship";}
};

class Cruiser : public Ship {
public:
    Cruiser():Ship(3) {}
    string getShipType() {return "Cruiser";}
};

class Destroyer : public Ship {
public:
    Destroyer():Ship(2) {}
    string getShipType() {return "Destroyer";}
};

class Submarine : public Ship {
public:
    Submarine():Ship(1) {}
    string getShipType() {return "Submarine";}

};

class EmptySea : public Ship {
public:
    EmptySea():Ship(0) {}
    string getShipType() {return "EmptySea";}
    virtual bool shootAt(int row, int column){ return false; }
    virtual bool isSunk() { return false;}
};

class Ocean
{
public:
    static const int TOTAL_SHIPS = 10;
    vector<vector<shared_ptr<Ship>>> m_ships;
    int m_shotsFired;
    int m_hitCount;
    int m_shipsSunk;
    Ocean() {
        m_ships.resize(10);
        shared_ptr<Ship> e = make_shared<EmptySea>();
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++)
                m_ships[i].push_back(e);
        }
        m_shotsFired = m_hitCount = m_shipsSunk = 0;
        placeAllShipsRandomly();
    }

    void placeAllShipsRandomly(){
        //Place larger ships before smaller ones
        //Otherwise, you may end up with no legal place to put a large ship

        shared_ptr<Ship> b = make_shared<Battleship>();
        shared_ptr<Ship> c = make_shared<Submarine>();
        shared_ptr<Ship> d = make_shared<Destroyer>();
        shared_ptr<Ship> s = make_shared<Submarine>();

        //say we put battleship at 0,0 horizontally, should use rand()
        b.get()->m_bowRow = b.get()->m_bowCol = 0;
        b.get()->m_isHorizontal = true;
        m_ships[0][0] = m_ships[0][1] = m_ships[0][2] = m_ships[0][3] = b;

        //continue for the rest
    }

    void shootAt(int row, int col)
    {
        m_shotsFired++;
        if (m_ships[row][col].get()->shootAt(row, col))
        {
            m_hitCount++;
            if (m_ships[row][col].get()->isSunk())
            {
                m_shipsSunk++;

            }
        }
    }

    bool isGameOver(){
        return m_shipsSunk == TOTAL_SHIPS;
    }

    void print()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (m_ships[i][j].get()->isSunk())
                    cout << "X" << " ";
                else
                    cout << "-" << " ";
            }
            cout << endl;
        }
    }
};

class BattleshipGame
{
public:
    void play()
    {
        while (true)
        {
            Ocean ocean;
            ocean.placeAllShipsRandomly();
            ocean.print();

            while (true)
            {
                int row = 0, col = 0;
                cin >> row >> col;

                ocean.shootAt(row, col);

                if (ocean.isGameOver())
                {
                    ocean.print();
                    //print more status
                    break;
                }
            }

            bool newGame = false;
            cin >> newGame;

            if (!newGame)
                return;
        }

    }
};

int main()
{
    cout << "Hello world!" << endl;
    BattleshipGame game;
    game.play();
    return 0;
}
