#ifndef Market_hpp
#define Market_hpp

#include "Item.hpp"
#include "Spell.hpp"
#include "Hero.hpp"
#include "Square.hpp"
#include <vector>

class Market : public Square{
protected:
	vector <Weapon*> listOfWeapons;
	vector <Armor*> listOfArmor;
	vector <Potion*> listOfPotion;
	vector <Spell*> listOfSpells;
public:
	Market();
	~Market();
	void addWeapon(Weapon &);
	void addArmor(Armor &);
	void addPotion(Potion &);
	void addSpell(Spell &);
	void printWeapons();
	void printArmor();
	void printPotion();
	void printSpells();
	virtual void menu(Hero &);
	virtual bool battle(vector<Hero*>);
	void buy(Hero &);
	void sell(Hero &);
};
#endif