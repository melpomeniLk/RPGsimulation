#ifndef Inventory_hpp
#define Inventory_hpp

#include "Item.hpp"
#include "Spell.hpp"
#include <vector>

class Inventory
{
protected:
	vector <Weapon*> weapons;
	vector <Armor*> armors;
	vector <Potion*> potions;
	vector <Spell*> spells;
public:
	Inventory();
	~Inventory();
	void addInvWeapon(Weapon &);
	void addInvArmor(Armor &);
	void addInvPotion(Potion &);
	void addInvSpell(Spell &);
	int findWeapon(string);
	int findArmor(string);
	int findPotion(string);
	int findSpell(string);
	void printInvWeapons();
	void printInvArmor();
	void printInvPotions();
	void printInvSpells();
	Weapon* getWeapon(int);
	Armor* getArmor(int);
	Potion getPotion(int);
	Spell getSpell(int);
	void usePotion(int);
	void deleteWeapon(int);
	void deleteArmor(int);
	void deleteSpell(int);
	void deletePotion(int);
};

#endif