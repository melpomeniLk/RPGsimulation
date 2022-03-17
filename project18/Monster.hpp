#ifndef Monster_hpp
#define Monster_hpp

#include "Living.hpp"

class Monster: public Living {
protected:
	unsigned int damage, tempDamage;
	unsigned int stamina, tempStamina;
	unsigned int avoidAttack, tempAvoidAttack;
	bool enchanted;
	unsigned int rounds;
public:
	Monster(string, unsigned int, int, unsigned int, unsigned int, unsigned int);
	Monster();
	~Monster();
	unsigned int getDamage();
	unsigned int getStamina();
	unsigned int getAvoidAttack();
	bool isEnchanted();
	void roundsEnchanted();
	virtual void displayStats();
	virtual void isAttacked(unsigned int);
	void attackedBySpell(unsigned int, unsigned int, int);
};

class Dragon : public Monster {
public:
	Dragon(string, unsigned int);
	~Dragon();
};

class Exoskeleton : public Monster {
public:
	Exoskeleton(string, unsigned int);
	~Exoskeleton();
};

class Spirit : public Monster {
public:
	Spirit(string, unsigned int);
	~Spirit();
};

#endif