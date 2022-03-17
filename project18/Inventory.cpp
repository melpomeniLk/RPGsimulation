#include "Inventory.hpp"

Inventory::Inventory() {}

Inventory::~Inventory() {
	int i;
	for (i=0; i < weapons.size(); i++){
		delete weapons[i];
	}
	for (i=0; i < armors.size(); i++){
		delete armors[i];
	}
	for (i=0; i < potions.size(); i++){
		delete potions[i];
	}
	for (i=0; i < spells.size(); i++){
		delete spells[i];
	}
}

void Inventory::addInvWeapon(Weapon &w){
	weapons.push_back(&w);
}

void Inventory::addInvArmor(Armor &a){
	armors.push_back(&a);
}

void Inventory::addInvPotion(Potion &p){
	potions.push_back(&p);
}

void Inventory::addInvSpell(Spell &s){
	spells.push_back(&s);
}

int Inventory::findWeapon(string name){
	int i;
	for (i=0; i < weapons.size(); i++){
		if ( name == weapons[i]->getName() ) return i;
	}
	return -1;
}

int Inventory::findArmor(string name){
		int i;
	for (i=0; i < armors.size(); i++){
		if ( name == armors[i]->getName() ) return i;
	}
	return -1;
}

int Inventory::findPotion(string name){
		int i;
	for (i=0; i < potions.size(); i++){
		if ( name == potions[i]->getName() ) return i;
	}
	return -1;
}

int Inventory::findSpell(string name){
		int i;
	for (i=0; i < spells.size(); i++){
		if ( name == spells[i]->getName() ) return i;
	}
	return -1;
}

void Inventory::printInvWeapons() {
	int i;
	cout << "Weapons:" << endl;
	for (i=0; i < weapons.size(); i++){
			cout << weapons[i]->getName()<< endl;
	}
}

void Inventory::printInvArmor() {
	int i;
	cout << "Armor:" << endl;
	for (i=0; i < armors.size(); i++){
			cout << armors[i]->getName()<< endl;
	}
}

void Inventory::printInvPotions() {
	int i;
	cout << "Potions:" << endl;
	for (i=0; i < potions.size(); i++){
			cout << potions[i]->getName()<< endl;
	}
}

void Inventory::printInvSpells() {
	int i;
	cout << "Spells:" << endl;
	for (i=0; i < spells.size(); i++){
			cout << spells[i]->getName()<< endl;
	}
}

Weapon* Inventory::getWeapon(int i){
	return weapons[i];
}

Armor* Inventory::getArmor(int i){
	return armors[i];
}

Potion Inventory::getPotion(int i){
	return *potions[i];
}

Spell Inventory::getSpell(int i){
	return *spells[i];
}

void Inventory::usePotion(int i){
	potions[i]->usePotion();
}

void Inventory::deleteWeapon(int i){
	weapons.erase(weapons.begin()+i);
}

void Inventory::deleteArmor(int i){
	armors.erase(armors.begin()+i);
}

void Inventory::deleteSpell(int i){
	spells.erase(spells.begin()+i);
}

void Inventory::deletePotion(int i){
	potions.erase(potions.begin()+i);
}
