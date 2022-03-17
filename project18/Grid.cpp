#include "Grid.hpp"
int i,j;

Grid::Grid(vector<Hero*> heroes) {
	partysPoint.x=0;
	partysPoint.y=0;
	position=0;
	for (i=0; i<heroes.size(); i++){
		Heroes.push_back(heroes[i]);
	}
	map.push_back(new Common());
	map.push_back(new Market());
	map.push_back(new Common());
	map.push_back(new Common());
	map.push_back(new NonAccessible());
	map.push_back(new Common());
	map.push_back(new NonAccessible());
	map.push_back(new Market());
	map.push_back(new Common());
	map.push_back(new Common());
	map.push_back(new Market());
	map.push_back(new Common());
	map.push_back(new Common());
	map.push_back(new NonAccessible());
	map.push_back(new Market());
}

Grid::~Grid() {
	for (i=0; i < Heroes.size(); i++){
		delete Heroes[i];
	}
	for (i=0; i < map.size(); i++){
		delete map[i];
	}
}

void Grid::printHeroes() {
	for (i=0; i < Heroes.size(); i++){
		Heroes[i]->displayStats();
		cout << "$ " << Heroes[i]->getMoney() << " |" << endl;
	}
}

void Grid::move() {
	int c;
	cout << "Do you want to display map?" << endl <<  "1.Yes		2.No" << endl;
	cin >> c;
	if ( c == 1 ) displayMap();
	cout << "Where do you want to move? " << endl << "1.Up			2.Down" << endl << "3.Left			4.Right" << endl;
	cin >> c;
	switch (c){
		case 1: if( partysPoint.x > 0){ //&& map[partysPoint.position]->isAccessible()) {
					if(map[position-5]->isNonAccessible()){
						cout << "Non Accessible Area!" << endl;
						move();
					}else{
						partysPoint.x--;
						position -= 5;
						cout << position << endl;
					}
				}
				else {
					cout << "You can't go upwards!" << endl << "Please select again" << endl;
					move();
				}
				break;
		case 2: if( partysPoint.x < 2 ) {
					if(map[position+5]->isNonAccessible()){
						cout << "Non Accessible Area!" << endl;
						move();
					}else{
						partysPoint.x++;
						position += 5;
					}
				}
				else {
					cout << "You can't go down!" << endl << "Please select again" << endl;
					move();
				}
				break;
		case 3: if( partysPoint.y > 0 ) {
					if(map[position-1]->isNonAccessible()){
						cout << "Non Accessible Area!" << endl;
						move();
					}else{
						partysPoint.y--;
						position --;	
					}
				}
				else {
					cout << "You can't go left!" << endl << "Please select again" << endl;
					move();
				}
				break;
		case 4: if( partysPoint.y < 4 ) {
					if(map[position+1]->isNonAccessible()){
						cout << "Non Accessible Area!" << endl;
						move();
					}else{
						partysPoint.y++;
						position++;
					}
				}
				else {
					cout << "You can't go right!" << endl << "Please select again" << endl;
					move();
				}
				break;
		default: break;
	}
}

void Grid::displayMap() {
	int count=0;
	for (i=0; i<12; i++){ cout << "*"; }
	cout << endl;
	for(i=0; i<3; i++) {
		cout << "*";
		for(j=0; j<5; j++){
			if( position == count ) cout << "H" ;
			else{
				if(map[count]->isNonAccessible()) cout << "X" ;
				else if(map[count]->isCommon()) cout << "C";
				else cout <<"M";
			}
			cout << "|" ;
			count++;
		}
		cout << "*" << endl;
	}
	for(i=0; i<12; i++) {cout << "*";}
	cout << endl;
	cout << "H: You are here" << endl;
	cout << "C: Common Area" << endl;
	cout << "M: Market Area" << endl;
	cout << "X: Non Accessible Area" << endl;
}

bool Grid::quitGame() {
	string answer;
	cout << "Are you sure?" << endl << "Press Y to quit or any other key to continue" << endl;
	cin >> answer;
	if (answer == "y" || answer == "Y") return 1;
	else return 0;
}

void Grid::menu(){
	cout << "What do you want to do?" << endl;
	cout << "1.Check Inventory" << endl;
	cout << "2.Equip" << endl;
	cout << "3.Use Potion" << endl;
	cout << "4.Display Map" << endl;
	cout << "5.Move" << endl;
	cout << "6.Print Heroes" << endl;
	cout << "7.Quit" << endl;
}

bool Grid::game() {
	menu();
	int c,i;
	cin >> c;
	switch (c){
		case 1: for( i=0; i<Heroes.size(); i++){
					Heroes[i]->checkInventory();
				}
				break;
		case 2: for( i=0; i<Heroes.size(); i++){
					Heroes[i]->equip();
				}
				break;
		case 3: for( i=0; i<Heroes.size(); i++){
					Heroes[i]->use();
				}
				break;
		case 4: displayMap();
				break;
		case 5: move();
				if (map[position]->isMarket()){
					for(i=0; i<Heroes.size(); i++){
						map[position]->menu(*Heroes[i]);
					}
				}else {
					map[position]->battle(Heroes);
				}
				break;
		case 6: printHeroes();
				break;
		case 7: if ( quitGame() ) return 1;
				break;
		default: break;
	}
	return 0;
}