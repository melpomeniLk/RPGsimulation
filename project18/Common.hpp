#ifndef Common_hpp
#define Common_hpp

#include "Item.hpp"
#include "Spell.hpp"
#include "Hero.hpp"
#include "Monster.hpp"
#include "Square.hpp"
#include <vector>

class Common : public Square {
public:
	Common();
	~Common();
	virtual bool battle(vector<Hero*>);
	virtual void menu(Hero &);
};

#endif