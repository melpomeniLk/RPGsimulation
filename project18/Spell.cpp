#include "Spell.hpp"

Spell::Spell(string n , float p , unsigned int l, unsigned int d, unsigned int m) {
	name = n;
	price = p;
	minLevel = l;
	damage = d;
	magicEnergy = m;
	kindOfSpell = 0;
}

Spell::Spell() {}

Spell::~Spell() {}

string Spell::getName(){
	return name;
}

float Spell::getPrice(){
	return price;
}

unsigned int Spell::getMinLevel(){
	return minLevel;
}

unsigned int Spell::getDamage(){
	return damage;
}

unsigned int Spell::getMagicEnergy(){
	return magicEnergy;
}

int Spell::getKindOfSpell(){
	return kindOfSpell;
}

void Spell::useSpell(Monster &m, int s){
	unsigned int rounds = rand()% 10 +1; // finds rounds that the monster will be enchanted
	unsigned int maxDamage = getDamage()+1;  // finds the amount of damage
	unsigned int totalDamage = rand() % maxDamage; // that the monster will be affected by spell
	/*if ( getKindOfSpell() == 1)	m.attackedBySpell(rounds,totalDamage,1);
	else if( getKindOfSpell() == 2) m.attackedBySpell(rounds,totalDamage,2);
	else m.attackedBySpell(rounds,totalDamage,3);*/
	m.attackedBySpell(rounds,totalDamage,s);
}

///////// ICE SPELL ///////////////////
IceSpell::IceSpell(string n , float p , unsigned int l, unsigned int d, unsigned int m):Spell(n,p,l,d,m) {
	kindOfSpell = 1;
}

IceSpell::IceSpell() {}

IceSpell::~IceSpell() {}

void IceSpell::useSpell(Monster& m, int s){
	/*cout << "ice" << endl;
	unsigned int rounds = rand()% 10 +1; // finds rounds that the monster will be enchanted
	unsigned int maxDamage = getDamage()+1;  // finds the amount of damage
	unsigned int totalDamage = rand() % maxDamage; // that the monster will be affected by spell
	m.attackedBySpell(rounds,totalDamage,1);
	cout << "I used spell" << endl;*/
	Spell::useSpell(m,s);
}

//////////// FIRE SPELL //////////////////////
FireSpell::FireSpell(string n , float p , unsigned int l, unsigned int d, unsigned int m):Spell(n,p,l,d,m) {
	kindOfSpell = 2;
}

FireSpell::FireSpell() {}

FireSpell::~FireSpell() {}

void FireSpell::useSpell(Monster& m, int s){
	/*unsigned int rounds = rand()% 10 +1;
	unsigned int maxDamage = getDamage()+1;
	unsigned int totalDamage = rand() % maxDamage;
	//Spell::useSpell(m);
	m.attackedBySpell(rounds,totalDamage,2);*/
	Spell::useSpell(m,s);
}

///////// LIGHTING SPELL //////////////////////
LightingSpell::LightingSpell(string n , float p , unsigned int l, unsigned int d, unsigned int m):Spell(n,p,l,d,m) {
	kindOfSpell = 3;
}

LightingSpell::LightingSpell() {}

LightingSpell::~LightingSpell() {}

void LightingSpell::useSpell(Monster& m, int s){
	/*unsigned int rounds = rand()% 10 +1;
	unsigned int maxDamage = getDamage()+1;
	unsigned int totalDamage = rand() % maxDamage;
	//Spell::useSpell(m);
	m.attackedBySpell(rounds,totalDamage,3);*/
	Spell::useSpell(m,s);
}