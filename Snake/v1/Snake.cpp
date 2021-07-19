#include <iostream>
#include <memory>
#include <deque>
#include <string>
#include <queue>
using namespace std;

class Tile{
public:
	enum TileType
	{
		SNAKE,
		FRUIT,
		EMPTY,
	};
	virtual TileType getType() = 0;
	virtual void draw() = 0;

};

class SnakeTile : public Tile
{
public:
	TileType getType() { return TileType::SNAKE;}
	void draw() { cout << "o"; }
};

class FruitTile : public Tile
{
public:
	TileType getType() { return TileType::FRUIT;}
	void draw() { cout << "x"; }
};

class EmptyTile : public Tile
{
public:
	TileType getType() { return TileType::EMPTY;}
	void draw() { cout << "-"; }
};

typedef pair<int, int> Point;

class Directions
{
public:
	enum Direction
	{
		N,
		S,
		E,
		W,
	};
	queue<Direction> m_directions;
	Directions() {}
	void init() { m_directions.push(E); }
	void addDirection(Direction dir) { m_directions.push(dir); }
};


class Board
{
public:
	static const int MAX_ROW = 25;
	static const int MAX_COL = 25;
	shared_ptr<Tile> m_tiles[MAX_ROW][MAX_COL];
	deque<Point> m_snake;
	Directions m_directions;
	bool m_hasCollison;
	Board(): m_hasCollison(false) {}

	void init()
	{
		initBoard();
		initSnake();
		initDirection();
		placeAFruit();
	}

	void initDirection()
	{
		m_directions.init();
	}
	void initBoard()
	{
		for (int i = 0; i < MAX_ROW; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				m_tiles[i][j] = make_shared<EmptyTile>();
			}
		}
	}
	void placeAFruit()
	{
		//should use rand and make sure this is an empty cell
		int x = 0;
		int y = 0;

		m_tiles[x][y] = make_shared<FruitTile>();
	}
	void initSnake()
	{
		int x = MAX_ROW/2;
		int y = MAX_COL/2;
		m_snake.push_back(Point(x, y));
		m_tiles[x][y] = make_shared<SnakeTile>();
	}
	void display()
	{
		for (int i = 0; i < MAX_ROW; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				m_tiles[i][j].get()->draw();
			}
			cout << endl;
		}
	}

	void update()
	{
		Tile::TileType type = updateSnake();

		if (type == Tile::TileType::SNAKE)
			m_hasCollison = true;
		else if (type == Tile::TileType::FRUIT)
			placeAFruit();
		else /* Epmty*/
			;
	}

	Tile::TileType updateSnake()
	{
		//logic to handle snake update

		//1 hit board edges
		//2 hit body
		//3 hit fruit tile
		//4 hit empty tile


		//return TileType;
	}
};


class SnakeGame
{
public:
    Board m_board;

    SnakeGame() {}
    void gameOver()
    {
        //print game status
    }
    void StartGame()
    {	
	m_board.init();

	wile (true)
	{
	    m_board.display();
	    m_board.update();

            if (m_board.m_hasCollison)
	    {
		gameOver();
		break;
	    }
	}
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
