#ifndef Spell_hpp
#define Spell_hpp

#include "Monster.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

using namespace std;

class Spell {//: public Item {
protected:
	string name;
	float price;
	unsigned int minLevel;
	unsigned int damage;
	unsigned int magicEnergy;
	int kindOfSpell;
public:
	Spell(string, float, unsigned int, unsigned int, unsigned int);
	Spell();
	~Spell();
	string getName();
	float getPrice();
	unsigned int getMinLevel();
	unsigned int getDamage();
	unsigned int getMagicEnergy();
	int getKindOfSpell();
	virtual void useSpell(Monster&, int);//, unsigned int);
};

class IceSpell: public Spell {
public:
	IceSpell(string, float, unsigned int, unsigned int, unsigned int);
	IceSpell();
	~IceSpell();
	virtual void useSpell(Monster&, int);
};

class FireSpell: public Spell {
public:
	FireSpell(string, float, unsigned int, unsigned int, unsigned int);
	FireSpell();
	~FireSpell();
	virtual void useSpell(Monster&, int);
};

class LightingSpell: public Spell {
public:
	LightingSpell(string, float, unsigned int, unsigned int, unsigned int);
	LightingSpell();
	~LightingSpell();
	virtual void useSpell(Monster&, int);
};

#endif
