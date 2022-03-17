#include "Square.hpp"

Square::Square(bool a, bool c, bool m){
	nonAccessible = a;
	common = c;
	market = m;
}

Square::~Square() {}

bool Square::isNonAccessible() {
	return nonAccessible;
}

bool Square::isCommon() {
	return common;
}

bool Square::isMarket() {
	return market;
}

void Square::menu(Hero &h){}

bool Square::battle(vector<Hero*> h){}

NonAccessible::NonAccessible():Square(1,0,0) {}

NonAccessible::~NonAccessible() {}

void NonAccessible::menu(Hero &h){}

bool NonAccessible::battle(vector<Hero*> h){}
