#include "Common.hpp"

Common::Common():Square(0,1,0){}

Common::~Common() {}

bool Common::battle(vector<Hero*> heroes) {
	vector<Monster*> monsters;
	unsigned int level=0, mnstrs, money, xp, totalDamage, maxDamage, attack;
	unsigned int heroesHP, monstersHP;
	bool battle = rand() % 2; // decides the beggining of battle
	int i,j,c,m,rnd,random;
	if (battle){
		for (i=0; i<heroes.size(); i++){
			level += heroes[i]->getLevel();  // calculating
		}							// the level
		level /= heroes.size();     	// of
		mnstrs = 1 + rand() % level;  // monsters
		for (i=0; i<mnstrs; i++){ // creating monsters
			random = rand() % 100;
			if ( random <= 33) monsters.push_back(new Dragon("Dragon",level));
			else if ( random <= 66 ) monsters.push_back(new Exoskeleton("Exoskeleton",level));
			else monsters.push_back(new Spirit("Spirit",level));
		}
		rnd=0;
		cout << "The battle beggins!" << endl;
		do{ 
			rnd++;
			cout << "Do you want to display stats?" << endl << "1.Yes		2.No" <<endl;
			cin >> c;
			if (c==1){
				for (i=0; i<heroes.size(); i++){
					heroes[i]->displayStats();
					cout << endl;
				}
				for (i=0; i<monsters.size(); i++){
					monsters[i]->displayStats();
					cout << endl;
				}
			}
			if( rnd > 1) {    // recovers the hp of heroes and monsters at the end of the round
				for (i=0; i<heroes.size(); i++){
					if( !heroes[i]->isDead()) heroes[i]->setHealthPower(5);
					if( heroes[i]->getMagicPower()) heroes[i]->setMagicPower(5);
				}
				for (i=0; i<monsters.size(); i++){
					if( !monsters[i]->isDead()) monsters[i]->setHealthPower(5);
				}
			}
			//// round ///////
			heroesHP = 0;
			monstersHP = 0;
			for (i=0; i<heroes.size(); i++){
				if ( !heroes[i]->isDead() ){ // if current hero is alive
					cout << heroes[i]->getName() << ", your turn! What would you like to do?" << endl;
					cout << "1.Attack" << endl << "2.Cast Spell" << endl << "3.Use Potion" << endl << "4.Equip" << endl <<"5.Quit"<<endl;
					cin >> c;
					switch (c){
						case 1:	for (j=0; j<monsters.size(); j++){
										if ( !monsters[j]->isDead() ) {  // if current monster is alive 
											attack = rand() % 100;
											if ( attack <= monsters[j]->getAvoidAttack()) cout << "You missed!" <<endl;
											else heroes[i]->attack(monsters[j]); // attack
											//break;
										}	
								}		
								break;
						case 2: for (j=0; j<monsters.size(); j++){
									if ( !monsters[j]->isDead() ) {  // if current monster is alive
										attack = rand() % 100;
										if ( attack <= monsters[j]->getAvoidAttack()) cout << "You missed!" <<endl;
										else heroes[i]->castSpell(monsters[j]); // cast spell
										break;
									}
								}
								break;
						case 3: heroes[i]->use();
								break;
						case 4: heroes[i]->equip();
								break;
						case 5: return 1;
								break;
						default:break;
					}
				} // end if hero isn't dead
			}
			for (i=0; i<monsters.size(); i++){ // checking if monsters are dead
				monstersHP += monsters[i]->getHealthPower();
			}
			if(monstersHP>0){  // if monsters are alive
				for (i=0; i<monsters.size(); i++){
					if (!monsters[i]->isDead()){ // if current monster is alive
						for(j=0; j<heroes.size(); j++){
							if ( !heroes[j]->isDead() ) { // if current hero is alive
								maxDamage = monsters[i]->getDamage() + 1; // find max damage
								totalDamage = rand() % maxDamage;    // and 
								attack = rand() % 100;
								if( attack <= heroes[j]->getAgility() ) cout << "Monster missed!" << endl;
								else {
									heroes[j]->isAttacked(totalDamage);		// attack
									cout << heroes[j]->getName() << " got " << totalDamage << " damage" << endl;
								}
							//break;
							}
						}
						if ( monsters[i]->isEnchanted() ) monsters[i]->roundsEnchanted(); // if monster is enchanted count down the
					}																	// rounds that is enchanted
				}
				for (i=0; i<heroes.size(); i++){ // checking if heroes are dead 
					heroesHP += heroes[i]->getHealthPower();
				}
			}
		} while(heroesHP !=0 && monstersHP !=0); // end of battle
		if ( monstersHP != 0){
			cout << "You lost!" << endl;
			for (i=0; i<heroes.size(); i++){
				heroes[i]->loseMoney(heroes[i]->getMoney()/2);
			}
		}
		else {
			cout << "You won!" << endl;
			for (i=0; i<heroes.size(); i++){
				money = 5*mnstrs*heroes[i]->getLevel(); 
				heroes[i]->earnMoney(money);
				xp = 10*mnstrs*heroes[i]->getLevel(); 
				heroes[i]->setExperience(xp);
				heroes[i]->levelUp();
			}
		}
		for (i=0; i<heroes.size(); i++){
			if (heroes[i]->isDead()) heroes[i]->setHealthPower(heroes[i]->getMaxHP()/2);
		}
		for (i=0; i<mnstrs; i++){
			delete monsters[i];
		}
	}
	return 0;
}

void Common::menu(Hero &h){}