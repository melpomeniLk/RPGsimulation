#ifndef Grid_hpp
#define Grid_hpp

#include "Item.hpp"
#include "Spell.hpp"
#include "Monster.hpp"
#include "Hero.hpp"
#include "Market.hpp"
#include "Common.hpp"

struct point
{
	int x,y;
};

class Grid {
protected:
	vector<Square*> map;
	vector<Hero*> Heroes;
	point partysPoint;
	int position;
public:
	Grid(vector<Hero*>);
	~Grid();
	void printHeroes();
	void move();
	void displayMap();
	bool quitGame();
	void menu();
	bool game();
};
#endif