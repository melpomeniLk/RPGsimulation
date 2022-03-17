#ifndef Hero_hpp
#define Hero_hpp

#include "Living.hpp"
#include "Spell.hpp"
#include "Item.hpp"
#include "Inventory.hpp"
#include <vector>

struct Equipment
{
	Weapon* weaponLeftHand;
	Weapon* weaponRightHand;
	Armor* armor;
};

class Hero : public Living {
protected:
	int magicPower, maxMP;
	unsigned int strength;
	unsigned int dexterity;
	unsigned int agility;
	unsigned int money;
	unsigned int experience;
	Equipment equipment;
	//Inventory inventory;
public:
	Hero(string, unsigned int, int , unsigned int, unsigned int, unsigned int, unsigned int);
	Hero();
	~Hero();
	Inventory inventory;
	int getMagicPower();
	unsigned int getStrength();
	unsigned int getDexterity();
	unsigned int getAgility();
	unsigned int getMoney();
	unsigned int getExperience();
	unsigned int getMaxMP();
	void setMagicPower(unsigned int);
	void setExperience(unsigned int);
	void setMaxHP(unsigned int);
	void setMaxMP(unsigned int);
	virtual void displayStats();
	virtual void isAttacked(unsigned int);
	virtual void levelUp();
	void checkInventory();
	bool equip();
	void attack(Monster* );
	void castSpell(Monster* );
	void use();
	void loseMoney(unsigned  int);//Weapon *);
	void earnMoney(unsigned int);
};

class Warrior : public Hero {
public:
	Warrior(string);
	~Warrior();
	virtual void levelUp();
};

class Sorcerer : public Hero {
public:
	Sorcerer(string);
	~Sorcerer();
	virtual void levelUp();
};

class Paladin : public Hero {
public:
	Paladin(string);
	~Paladin();
	virtual void levelUp();
};

#endif