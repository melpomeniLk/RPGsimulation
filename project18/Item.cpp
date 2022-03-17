#include "Item.hpp"

Item::Item(string n , float p , unsigned int l) {
	name = n;
	price = p;
	minLevel = l;
}

Item::Item() {}

Item::~Item() {}

string Item::getName(){
	return name;
}

float Item::getPrice(){
	return price;
}

unsigned int Item::getMinLevel(){
	return minLevel;
}

//////////// WEAPON ////////////////
Weapon::Weapon(string n , float p , unsigned int l, unsigned int d, bool h):Item(n,p,l){
	damage = d;
	twoHands = h;
}

Weapon::Weapon() {}

Weapon::~Weapon() {}

unsigned int Weapon::getDamage(){
	return damage;
}

bool Weapon::needsTwoHands(){
	return twoHands;
}
///////////////////////////////////

///////////// ARMOR ///////////////
Armor::Armor(string n , float p , unsigned int l, unsigned int d):Item(n,p,l){
	defence = d;
}

Armor::Armor() {
}

Armor::~Armor() {}

unsigned int Armor::getDefence(){
	return defence;
}
//////////////////////////////////////

///////////// POTION//////////////////
Potion::Potion(string n , float p , unsigned int l, unsigned int a, string s):Item(n,p,l){
	amount = a;
	statistic = s;
	isUsed = 0;
}

Potion::Potion() {
}

Potion::~Potion() {}

unsigned int Potion::getAmount(){
	return amount;
}

string Potion::getStatistic() {
	return statistic;
}

void Potion::usePotion() {
	isUsed = 1;
}

bool Potion::hasBeenUsed(){
	return isUsed;
}
//////////////////////////////////////