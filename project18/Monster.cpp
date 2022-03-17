#include "Monster.hpp"

Monster::Monster(string n, unsigned int l, int h, unsigned int d, unsigned int s, unsigned int a):Living(n,l,h){
	damage = d;
	tempDamage = d;
	stamina = s;
	tempStamina = s;
	avoidAttack = a;
	tempAvoidAttack = a;
	enchanted = 0;
	rounds = 0;
}

Monster::Monster() {
	name = "Monster";
	damage = 50;
	tempDamage =50;
	stamina = 50;
	tempStamina = 50;
	avoidAttack = 20;
	tempAvoidAttack = 20;
	enchanted = 0;
	rounds = 0;
}

Monster::~Monster() {}

unsigned int Monster::getDamage() {
	if (enchanted)
		return tempDamage;
	else 
		return damage;
}

unsigned int Monster::getStamina() {
	if (enchanted)
		return tempStamina;
	else
		return stamina;
}

unsigned int Monster::getAvoidAttack() {
	if (enchanted)
		return tempAvoidAttack;
	else
		return avoidAttack;
}

bool Monster::isEnchanted() {
	return enchanted;
}

void Monster::roundsEnchanted(){
	if(rounds) rounds--;
	else enchanted = 0 ;
}

void Monster::displayStats() {
	Living::displayStats();
	cout << "D " << getDamage() << " | S " << getStamina() << " | A " << getAvoidAttack() << " | " << " isEnchanted " << isEnchanted() << endl;
}

void Monster::isAttacked(unsigned int damage) {
	if ( damage >= getStamina()) damage -= getStamina();
	else damage = 0;
	Living::isAttacked(damage);
}

void Monster::attackedBySpell(unsigned int r, unsigned int amount, int c) {
	enchanted = 1;
	rounds = r;
	switch (c){
	case 1:	tempDamage = damage - amount;
			break;
	case 2: tempStamina = stamina - amount;
			break;
	case 3: tempAvoidAttack = avoidAttack - amount;
			break;
	default: break;
	}
}
///////////////////////////////

//// DRAGON ///////////////////
Dragon::Dragon(string n,unsigned int l) {
	name = n;
	level = l;
	damage = 25;
	stamina = 15;
	avoidAttack = 5;
	tempDamage =25;
	tempStamina = 15;
	tempAvoidAttack = 5;
}

Dragon::~Dragon() {}
//////////////////////////////

//////////// EXOSKELETON ///////////////
Exoskeleton::Exoskeleton(string n,unsigned int l) {
	name = n;
	level = l;
	damage = 15;
	stamina = 25;
	avoidAttack = 5;
	tempDamage = 15;
	tempStamina = 25;
	tempAvoidAttack = 5;
}

Exoskeleton::~Exoskeleton() {}
////////////////////////////////

///////////// SPIRIT/////////////////
Spirit::Spirit(string n,unsigned int l) {
	name = n;
	level = l;
	damage = 15;
	stamina = 15;
	avoidAttack = 20;
	tempDamage = 15;
	tempStamina = 15;
	tempAvoidAttack = 20;
}

Spirit::~Spirit() {}
/////////////////////////////////////