#include "Grid.hpp"
#include "Market.hpp"
#include <vector>

using namespace std;

int main(){
	int numOfheroes,i,c;
	string name;
	vector<Hero*> v;
	srand(time(NULL));
	//for(i=0; i<50; i++){ cout << endl; }
	cout << "Welcome to the game!" << endl << "How many heroes yould you like to have in your party?" << endl;
	cin >> numOfheroes;
	for (i=0; i<numOfheroes; i++){
		cout << "What kind of hero do you want?" << endl << "1.Warrior" << endl << "2.Sorcerer" << endl << "3.Paladin" << endl;
		cin >> c;
		cout << "Give a name" << endl;
		cin >> name;
		switch (c){
			case 1: v.push_back(new Warrior(name));
					break;
			case 2: v.push_back(new Sorcerer(name));
					break;
			case 3: v.push_back(new Paladin(name));
					break;
			default: break;
		}
	}
	Grid grid(v);
	bool quit=0;
	while (!quit){
		quit = grid.game();
	}
	return 0;
}