#include "Market.hpp"

Market::Market():Square(0,0,1){
	listOfWeapons.push_back(new Weapon("Wand",1,1,10,0));
	listOfWeapons.push_back(new Weapon("Sword",1,1,25,0));
	listOfWeapons.push_back(new Weapon("EnchantedRod",3,2,50,1));
	listOfArmor.push_back(new Armor("RubyShield",1,1,15));
	listOfArmor.push_back(new Armor("MagicShield",2,2,50));
	listOfPotion.push_back(new Potion("HolyWater",1,1,25,"healthPower"));
	listOfPotion.push_back(new Potion("ManaTonic",2,5,25,"magicPower"));
	listOfPotion.push_back(new Potion("Elixir",1,1,25,"strength"));
	listOfPotion.push_back(new Potion("DreamPowder",1,1,25,"dexterity"));
	listOfPotion.push_back(new Potion("SpeedDistiller",1,1,25,"agility"));
	listOfSpells.push_back(new FireSpell("Fireball",1,1,50,15));
	listOfSpells.push_back(new IceSpell("Freeze",2,1,50,20));
	listOfSpells.push_back(new LightingSpell("Darkness",5,2,50,25));
}

Market::~Market(){
	int i;
	for (i=0; i < listOfWeapons.size(); i++){
		delete listOfWeapons[i];
	}
	for (i=0; i < listOfArmor.size(); i++){
		delete listOfArmor[i];
	}
	for (i=0; i < listOfPotion.size(); i++){
		delete listOfPotion[i];
	}
	for (i=0; i < listOfSpells.size(); i++){
		delete listOfSpells[i];
	}
}

void Market::addWeapon(Weapon &w){
	listOfWeapons.push_back(&w);
}

void Market::addArmor(Armor &a){
	listOfArmor.push_back(&a);
}

void Market::addPotion(Potion &p){
	listOfPotion.push_back(&p);
}

void Market::addSpell(Spell &s){
	listOfSpells.push_back(&s);
}

void Market::printWeapons(){
	int i;
	for (i=0; i < listOfWeapons.size(); i++){
			cout << listOfWeapons[i]->getName()<< " | ";
			cout << listOfWeapons[i]->getMinLevel()<< " | ";
			cout << listOfWeapons[i]->getDamage()<< " | ";
			if ( listOfWeapons[i]->needsTwoHands() ) cout << "Yes";
			else cout << "No";
			cout << " | " << listOfWeapons[i]->getPrice() << "$" << endl;
		}
}

void Market::printArmor() {
	int i;
	for (i=0; i < listOfArmor.size(); i++){
			cout << listOfArmor[i]->getName()<< " | ";
			cout << listOfArmor[i]->getMinLevel()<< " | ";
			cout << listOfArmor[i]->getDefence()<< " | ";
			cout << listOfArmor[i]->getPrice()<< "$" << endl;
		}
}

void Market::printPotion() {
	int i;
	for (i=0; i < listOfPotion.size(); i++){
			cout << listOfPotion[i]->getName()<< " | ";
			cout << listOfPotion[i]->getMinLevel()<< " | ";
			cout << listOfPotion[i]->getAmount()<< " | ";
			cout << listOfPotion[i]->getPrice()<< "$" << endl;
		}
}

void Market::printSpells() {
	int i;
	for (i=0; i < listOfSpells.size(); i++){
			cout << listOfSpells[i]->getName()<< " | ";
			cout << listOfSpells[i]->getMinLevel()<< " | ";
			cout << listOfSpells[i]->getDamage()<< " | ";
			cout << listOfSpells[i]->getMagicEnergy()<< " | ";
			cout << listOfSpells[i]->getPrice()<< "$" << endl;
		}
}

void Market::menu(Hero &h) {
	int c;
	cout << h.getName() << ", welcome to our market! What do you want to do?" << endl << "1.Buy" << endl << "2.Sell" << endl << "3.Return" << endl;
	cin >> c;
	switch (c) {
		case 1: cout << "What do you want to buy?" << endl << "1.Weapon" << endl << "2.Armor" << endl << "3.Potion" << endl << "4.Spell" << endl << "5.Nothing" << endl; 
				buy(h);
				break;
		case 2: cout << "What would you like to sell?" << endl << "1.Weapon" << endl << "2.Armor" << endl << "3.Potion" << endl << "4.Spell" << endl << "5.Nothing" << endl;
				sell(h);
				break;
		default: cout<< "Goodbye!" << endl; break;
	}
}

void Market::buy(Hero &h) {
	int i,b;
	string name;
	cin >> b;
	if ( b > 0 && b <= 4) {
		switch (b) {
		case 1:	printWeapons();
				cout << "Which weapon do you want to buy?" << endl;
				cin >> name;
				for (i=0; i < listOfWeapons.size(); i++){
					if ( name == listOfWeapons[i]->getName() ){
						if ( h.getMoney() >= listOfWeapons[i]->getPrice() ){
							h.inventory.addInvWeapon(*listOfWeapons[i]);
							//h.inventory.weapons.push_back(listOfWeapons[i]);
							h.loseMoney(listOfWeapons[i]->getPrice());
							break;
						} else cout << "You don't have enough money!" << endl;
					}
				}
				break;
		case 2:	printArmor();
				cout << "Which armor do you want to buy?" << endl;
				cin >> name;
				for (i=0; i < listOfArmor.size(); i++){
					if ( name == listOfArmor[i]->getName() ){
						if ( h.getMoney() >= listOfArmor[i]->getPrice() ){
							h.inventory.addInvArmor(*listOfArmor[i]);
							//h.inventory.armors.push_back(listOfArmor[i]);
							h.loseMoney(listOfArmor[i]->getPrice());
							break;
						}else cout << "You don't have enough money!" << endl;
					}
				}
				break;
		case 3:	printPotion();
				cout << "Which potion do you want to buy?" << endl;
				cin >> name;
				for (i=0; i < listOfPotion.size(); i++){
					if ( name == listOfPotion[i]->getName() ){
						if ( h.getMoney() >= listOfPotion[i]->getPrice() ){
							h.inventory.addInvPotion(*listOfPotion[i]);
							//h.inventory.potions.push_back(listOfPotion[i]);
							h.loseMoney(listOfPotion[i]->getPrice());
							break;
						}else cout << "You don't have enough money!" << endl;
					}
				}
				break;
		case 4:	printSpells();
				cout << "Which spell do you want to buy?" << endl;
				cin >> name;
				for (i=0; i < listOfSpells.size(); i++){
					if ( name == listOfSpells[i]->getName() ){
						if ( h.getMoney() >= listOfSpells[i]->getPrice() ){
							//h.inventory.spells.push_back(listOfSpells[i]);
							h.inventory.addInvSpell(*listOfSpells[i]);
							h.loseMoney(listOfSpells[i]->getPrice());
							break;
						}else cout << "You don't have enough money!" << endl;
					}
				}
				break;
		default: break;
		}
	cout << "Thank you! Would you like to do anything else?" << endl << "1.Yes		2.No, thank you" << endl;
	cin >> b;
	if ( b==1 ) menu(h);
	else cout << "Goodbye!" << endl;
	}else menu(h);
}

void Market::sell(Hero &h) {
	int i,b,found;
	string name;
	cin >> b;
	if ( b > 0 && b <= 4) {
		switch (b) {
		case 1:	cout << "Which weapon do you want to sell?" << endl;
				h.inventory.printInvWeapons();
				cin >> name;
				found = h.inventory.findWeapon(name);
				if(found > -1) {
					Weapon *w;
					w = h.inventory.getWeapon(found);
					h.earnMoney(w->getPrice()/2);
					h.inventory.deleteWeapon(found);
				}
				else cout << "Weapon not found!" << endl;
				break;
		case 2:	cout << "Which armor do you want to sell?" << endl;
				h.inventory.printInvArmor();
				cin >> name;
				found = h.inventory.findArmor(name);
				if(found > -1) {
					Armor *w;
					w = h.inventory.getArmor(found);
					h.earnMoney(w->getPrice()/2);
					h.inventory.deleteArmor(found);
				}
				break;
		case 3:	cout << "Which potion do you want to sell?" << endl;
				h.inventory.printInvPotions();
				cin >> name;
				found = h.inventory.findPotion(name);
				if(found > -1) {
					Potion w;
					w = h.inventory.getPotion(found);
					h.earnMoney(w.getPrice()/2);
					h.inventory.deletePotion(found);
				}
				break;
		case 4:	cout << "Which spell do you want to sell?" << endl;
				h.inventory.printInvSpells();
				cin >> name;
				found = h.inventory.findSpell(name);
				if(found > -1) {
					Spell w;
					w = h.inventory.getSpell(found);
					h.earnMoney(w.getPrice()/2);
					h.inventory.deleteSpell(found);
				}
				break;
		default: break;
		}
	cout << "Thank you! Would you like to do anything else?" << endl << "1.Yes		2.No, thank you" << endl;
	cin >> b;
	if ( b==1 ) menu(h);
	else cout << "Goodbye!" << endl;
	}else menu(h);
}

bool Market::battle(vector<Hero*> h){}
