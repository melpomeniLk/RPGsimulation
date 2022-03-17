#include "Living.hpp"

Living::Living(string n, unsigned int l, int h){
	name = n;
	level = l;
	healthPower = h;
	maxHP = h;
}

Living::Living() {
	name = "Creature";
	level = 1;
	healthPower = 100;
	maxHP = 100;
}

Living::~Living() {}

string Living::getName() {
	return name;
}

unsigned int Living::getLevel() {
	return level;
}

int Living::getHealthPower() {
	return healthPower;
}

int Living::getMaxHP() {
	return maxHP;
}

void Living::setHealthPower(unsigned int hp){
	healthPower += hp;
	if ( getHealthPower() > getMaxHP() ) healthPower = maxHP;
}

bool Living::isDead() {
	if ( healthPower <= 0) return 1;
	else return 0;
}

void Living::displayStats() {
	cout << getName() << " | L" << getLevel() << " | HP " << getHealthPower() << " | "; 
}

void Living::isAttacked(unsigned int damage) {
	healthPower -= damage;
	if (healthPower <= 0) healthPower =0;
}