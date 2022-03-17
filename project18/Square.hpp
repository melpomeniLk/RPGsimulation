#ifndef Square_hpp
#define Square_hpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdbool.h>
#include "Hero.hpp"

using namespace std;

class Square {
protected:
	bool nonAccessible;
	bool common;
	bool market;
public:
	Square(bool, bool, bool);
	~Square();
	bool isNonAccessible();
	bool isCommon();
	bool isMarket();
	virtual void menu(Hero &);
	virtual bool battle(vector<Hero*>);
};

class NonAccessible : public Square{
public:
	NonAccessible();
	~NonAccessible();
	virtual void menu(Hero &);
	virtual bool battle(vector<Hero*>);
};
#endif