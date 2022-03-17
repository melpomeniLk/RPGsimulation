#ifndef Living_hpp
#define Living_hpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

using namespace std;

class Living {
protected:
	string name;
	unsigned int level;
	int healthPower;
	int maxHP;
public:
	Living(string, unsigned int, int);
	Living();
	~Living();
	string getName();
	unsigned int getLevel();
	int getHealthPower();
	int getMaxHP();
	void setHealthPower(unsigned int);
	bool isDead();
	virtual void displayStats();
	virtual void isAttacked(unsigned int);
};

#endif