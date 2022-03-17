#include "Hero.hpp"

Hero::Hero(string n, unsigned int l, int h, unsigned int mp, unsigned int s, unsigned int d, unsigned int a):Living(n,l,h) {
	magicPower = mp;
	maxMP = mp;
	strength = s;
	dexterity = d;
	agility = a;
	money = 0;
	experience = 0;
}

Hero::Hero() {
	name = "Hero";
	magicPower = 100;
	maxMP = 100;
	strength = 50;
	dexterity = 50;
	agility = 50;
	money = 0;
	experience = 0;
}

Hero::~Hero() {
	/*if( equipment.weaponLeftHand != NULL) delete equipment.weaponLeftHand;
	if( equipment.weaponRightHand != NULL) delete equipment.weaponRightHand;
	if ( equipment.armor != NULL) delete equipment.armor;*/
}

int Hero::getMagicPower(){
	return magicPower;
}

unsigned int Hero::getStrength(){
	return strength;
}

unsigned int Hero::getDexterity(){
	return dexterity;
}

unsigned int Hero::getAgility() {
	return agility;
}

unsigned int Hero::getMoney() {
	return money;
}

unsigned int Hero::getExperience(){
	return experience;
}

unsigned int Hero::getMaxMP(){
	return maxMP;
}
void Hero::setMagicPower(unsigned int mp){
	magicPower += mp;
	if (magicPower > maxMP ) magicPower = maxMP;
}

void Hero::setExperience(unsigned int xp){
	experience += xp;
}

void Hero::setMaxHP(unsigned int amount) {
	maxHP += amount;
}
			
void Hero::setMaxMP(unsigned int amount) {
	maxMP += amount;
}

void Hero::displayStats() {
	Living::displayStats();
	cout << "MP " << getMagicPower() << " | S " << getStrength() << " | D " << getDexterity() << " | A " << getAgility() << " | XP " << getExperience() << " | ";
}

void Hero::isAttacked(unsigned int damage){
	if ( equipment.armor != NULL)
		damage -= equipment.armor->getDefence();
	Living::isAttacked(damage);
}

void Hero::levelUp() {
	//switch(level) {
		//if ( experience >= 100 ) {
	level++;
	experience = 0;
	setMaxHP(25);
	setMaxMP(25);
	healthPower = getMaxHP();
	magicPower = getMaxMP();
		//}
	//}
}

void Hero::checkInventory() {
	int i;
	cout << getName() << "'s Inventory" << endl;
	inventory.printInvWeapons();
	inventory.printInvArmor();
	inventory.printInvPotions();
	inventory.printInvSpells();
}

bool Hero::equip() {
	int i,c,found;
	string item;
	cout << getName() << ", do you want to see your current equipment?" << endl << "1.Yes		2.No" << endl <<"3.Return" << endl;
	cin >> c;
	if ( c == 1){ // prints the current equipment
		if ( equipment.weaponLeftHand != NULL ) cout << "Left Hand: " << equipment.weaponLeftHand->getName() << endl;
		else cout << "Left Hand: -" << endl;
		if ( equipment.weaponRightHand != NULL ) cout << "Right Hand: " << equipment.weaponRightHand->getName() << endl;
		else cout << "Right Hand: -" << endl;
		if (equipment.armor != NULL ) cout << "Armor: " << equipment.armor->getName() << endl;
		else cout << "Armor: -" << endl;
	}else if( c == 3 ) return 1;
	cout << "What item do you want to equip?" << endl << "1.Weapon" << endl << "2.Armor" << endl <<"3.Return"<<endl;
	cin >> c;
	if ( c == 1){
		cout << "Which weapon do you want to equip?" << endl;
		inventory.printInvWeapons();
		cin >> item;
		found = inventory.findWeapon(item);
		if (found > -1){
			Weapon *w;
			w = inventory.getWeapon(found);
			if ( level >= w->getMinLevel() ) { // if the hero can equip it
				if ( w->needsTwoHands() ){ // if it needs two hands
					equipment.weaponLeftHand = w; // equip both left
					equipment.weaponRightHand = w; // and both right hand
				}
				else{ 
					if (equipment.weaponLeftHand == NULL)	equipment.weaponLeftHand = w;
					else if ( equipment.weaponRightHand == NULL) equipment.weaponRightHand = w;
					else{
						equipment.weaponLeftHand = w;
					}
				}
			} else cout << "You can't equip this weapon yet!" << endl;
		} else cout << "Weapon not found!" << endl;
	} else if (c == 2){
		cout << "Which armor do you want to equip?" << endl;
		inventory.printInvArmor();
		cin >> item;
		found = inventory.findArmor(item);
		if (found > -1){
			Armor *a;
			a = inventory.getArmor(found);
			if ( level >= a->getMinLevel() )
				equipment.armor = a;
			else cout << "You can't equip this armor yet!" << endl;
		} else cout << "Armor not found" << endl;
	} else return 1;
	return 0;
}

void Hero::attack(Monster *m) {
	unsigned int maxDamage,totalDamage;
	maxDamage = strength;
	if(equipment.weaponLeftHand != NULL)
		maxDamage += equipment.weaponLeftHand->getDamage();
	if(equipment.weaponRightHand != NULL){
		maxDamage += equipment.weaponRightHand->getDamage();
		if ( equipment.weaponLeftHand->needsTwoHands() )
			maxDamage = equipment.weaponLeftHand->getDamage();
	}
	totalDamage = rand() % maxDamage;
	m->isAttacked(totalDamage);
}

void Hero::castSpell(Monster *m) {
	int i,found,sp;
	unsigned int maxDamage, totalDamage;
	string namespell;
	Spell s;
	cout << "Which spell do you want to use?" << endl;
	inventory.printInvSpells();
	cin >> namespell;
	found = inventory.findSpell(namespell);
	if (found > -1) {
		s = inventory.getSpell(found);
		cout << s.getName() << endl;
		sp = s.getKindOfSpell();
		/*if ( sp == 1) {
			IceSpell ice;
			ice = s;
		} else if (sp == 2) {
			FireSpell s;
			s = spell;
		} else {
			LightingSpell s;
			s = spell;
		}*/
		if ( level >= s.getMinLevel() ){
				if ( magicPower >= s.getMagicEnergy() ) {
					magicPower -= s.getMagicEnergy();
					maxDamage = dexterity +1;
					totalDamage = rand() % maxDamage;
					m->isAttacked(totalDamage);
					s.useSpell(*m,sp);
				}
				else cout << "You don't have enough magic power to use that spell!" << endl;
			}
			else cout << "You can't use that spell yet!" << endl;
	} else cout << "Spell not found!" << endl;
}

void Hero::use() {
	int i,c,found;
	string potion, statistic;
	Potion p;
	cout << "Which potion do you want to choose?" << endl;
	inventory.printInvPotions();
	cin >> potion;
	found = inventory.findPotion(potion);
	if (found > -1) {
		p = inventory.getPotion(found);
		cout << p.getName() << endl;
		if ( !p.hasBeenUsed() ) {
			statistic = p.getStatistic();
			if ( statistic == "strength") strength += p.getAmount();
			else if ( statistic == "healthPower") setHealthPower(p.getAmount());
			else if ( statistic == "magicPower") setMagicPower(p.getAmount());
			else if ( statistic == "dexterity" ) dexterity += p.getAmount();
			else agility += p.getAmount();
			inventory.usePotion(found);
		}else {
			cout << "You have already used that potion! Delete it?" << endl <<"1.Yes		2.No" << endl;
			cin >> c;
			if (c == 1 ) inventory.deletePotion(found);
		}
	}
	else cout << "Potion not found!" << endl;
}


void Hero::loseMoney(unsigned int m) {
	if ( money >= m) money -= m;
	else money = 0;
}

void Hero::earnMoney(unsigned int m) {
	money += m;
}
///////////////////////////////////

////////// WARRIOR ////////////////
Warrior::Warrior(string n) {
	name = n;
	strength = 50;
	dexterity = 25;
	agility = 20;
}

Warrior::~Warrior() {}

void Warrior::levelUp() {
	if ( getExperience() >= 100){
		strength += 50;
		dexterity += 25;
		agility += 50;
		Hero::levelUp();
	}
}
//////////////////////////////////


////////// SORCERER //////////////
Sorcerer::Sorcerer(string n) {
	name = n;
	strength = 25;
	dexterity = 50;
	agility = 20;
}

Sorcerer::~Sorcerer() {}

void Sorcerer::levelUp(){
	if ( getExperience() >= 100){
		strength += 25;
		dexterity += 50;
		agility += 50;
		Hero::levelUp();
	}
}
//////////////////////////////////


///////////// PALADIN ////////////
Paladin::Paladin(string n) {
	name = n;
	strength = 50;
	dexterity = 50;
	agility = 10;
}

Paladin::~Paladin() {}

void Paladin::levelUp() {
	if ( getExperience() >= 100){	
		strength += 50;
		dexterity += 50;
		agility += 25;
		Hero::levelUp();
	}
}
////////////////////////////////