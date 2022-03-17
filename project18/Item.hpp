#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

class Item {
protected:
	string name;
	float price;
	unsigned int minLevel;
public:
	Item(string, float, unsigned int);
	Item();
	~Item();
	string getName();
	float getPrice();
	unsigned int getMinLevel();
};

class Weapon : public Item {
protected:
	unsigned int damage;
	bool twoHands;
public:
	Weapon (string, float, unsigned int, unsigned int, bool);
	Weapon();
	~Weapon();
	unsigned int getDamage();
	bool needsTwoHands();
};

class Armor : public Item {
protected:
	unsigned int defence;
public:
	Armor(string, float, unsigned int, unsigned int);
	Armor();
	~Armor();
	unsigned int getDefence();
};

class Potion : public Item {
protected:
	unsigned int amount;
	string statistic;
	bool isUsed;
public:
	Potion(string, float, unsigned int, unsigned int, string);
	Potion();
	~Potion();
	unsigned int getAmount();
	string getStatistic();
	void usePotion();
	bool hasBeenUsed();
};

#endif