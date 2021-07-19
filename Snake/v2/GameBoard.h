#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Tile.h"
#include "BorderTile.h"
#include "SnakeTile.h"
#include "FruitTile.h"
#include "EmptyTile.h"
#include "UIEngine.h"
#include "KeyboardCapturer.h"
#include <time.h>     
#include <vector>
#include <deque>
#include <typeinfo>
#include <windows.h>

using namespace std;

typedef pair<int, int> Point;

class GameBoard {
private:
    enum DIRECTION {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

	static const int MAX_ROW = 40;
	static const int MAX_COL = 20;
	vector<vector<Tile *>> m_board;
    deque<Point> m_snakeBody;
	// Point m_snakeHead;
    // Point m_snakeTail;
    Point m_fruit;
    DIRECTION m_direction;
	
	bool m_hasCollison;

public:
	GameBoard(): m_hasCollison(false) {
        m_board = vector<vector<Tile *>>(MAX_ROW, vector<Tile *>(MAX_COL, NULL));
        m_direction = DIRECTION::NONE;
        srand (time(NULL));
        initBoard();
    }

    void run() {
        while (true) {
            update();
            Sleep(125);
        }
    }

    void update() {
        char key = ' ';
        if (KeyboardCapturer::getInstance().capture(key)) {
            if (key == 'w') {
                m_direction = DIRECTION::UP;
            } else if (key == 's') {
                m_direction = DIRECTION::DOWN;
            } else if (key == 'a') {
                m_direction = DIRECTION::LEFT;
            } else if (key == 'd') {
                m_direction = DIRECTION::RIGHT;
            } 
        } 
        
        if (m_direction == DIRECTION::NONE)
            return;

        Point snakeHead = m_snakeBody.front();
        if (m_direction == DIRECTION::UP) {
            snakeHead.second--;
        } else if (m_direction == DIRECTION::DOWN) {
            snakeHead.second++;
        } else if (m_direction == DIRECTION::LEFT) {
            snakeHead.first--;
        } else if (m_direction == DIRECTION::RIGHT) {
            snakeHead.first++;
        }
        m_snakeBody.push_front(snakeHead);
        m_board[snakeHead.first][snakeHead.second] = new SnakeTile();
        UIEngine::getInstance().update(snakeHead.first, snakeHead.second, m_board[snakeHead.first][snakeHead.second]->getSymbol());

        if (snakeHead == m_fruit) {    
            placeFruit();
            return;
        } 

        Point snakeTail = m_snakeBody.back();
        m_board[snakeTail.first][snakeTail.second] = new EmptyTile();
        m_snakeBody.pop_back();
        UIEngine::getInstance().update(snakeTail.first, snakeTail.second, m_board[snakeTail.first][snakeTail.second]->getSymbol());
    }

	void initBoard()
	{
        system("cls");

        placeBorder();
        placeSnake();
        placeEmpty();
        placeFruit();
    }

    void placeBorder() {
		for (int i = 0; i < MAX_ROW; i++) {
			m_board[i][0] = new BorderTile();
            UIEngine::getInstance().update(i, 0, m_board[i][0]->getSymbol());
            m_board[i][MAX_COL - 1] = new BorderTile();
            UIEngine::getInstance().update(i, MAX_COL - 1, m_board[i][MAX_COL - 1]->getSymbol());
		}

        for (int j = 1; j < MAX_COL - 1; j++) {
			m_board[0][j] = new BorderTile();
            UIEngine::getInstance().update(0, j, m_board[0][j]->getSymbol());
            m_board[MAX_ROW - 1][j] = new BorderTile();
            UIEngine::getInstance().update(MAX_ROW - 1, j, m_board[MAX_ROW - 1][j]->getSymbol());
		}
    }

    void placeSnake() {
        int x = MAX_ROW/2;
        int y = MAX_COL/2;
        m_snakeBody.push_back({x, y});
        m_board[x][y] = new SnakeTile();
        UIEngine::getInstance().update(x, y, m_board[x][y]->getSymbol());
    }
    
    void placeFruit() {
        while (true) {
            int x = rand() % MAX_ROW;
            int y = rand() % MAX_COL;
            if (m_board[x][y]->getSymbol() != ' ') {
                continue;
            }

            m_fruit = {x, y};
            m_board[x][y] = new FruitTile();
            UIEngine::getInstance().update(x, y, m_board[x][y]->getSymbol());
            break;
        }      
    }

    void placeEmpty() {
        for (int i = 0; i < MAX_ROW; i++) {
			for (int j = 0; j < MAX_COL; j++) {
                if (m_board[i][j] == NULL) {
                    m_board[i][j] = new EmptyTile();
                }
            }
		}
	}
};

#endif