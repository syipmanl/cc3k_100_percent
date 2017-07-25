
#include "hero.h"
#include "enemy.h"
#include "tile.h"

#include <math.h>
using namespace std;


Hero::Hero(int maxHP, int ATK, int DEF,int gold, 
		int dif_atk, int dif_def,
<<<<<<< HEAD
		int real_atk, int real_def,
		bool hit, bool 
		char symbol, std::string type, std::string race):

		Character(ATK, DEF, maxHP, dif_atk, dif_def, 
			real_atk, real_def, 
			hit, race, symbol, type), 
		maxHP(maxHP), gold(gold), 
=======
		int read_hp, int real_atk, int real_def,
		char symbol, std::string type, std::string race):

		Character(ATK, DEF, maxHP, dif_atk, dif_def, 
			false, race, symbol, type), 
		maxHP(maxHP), gold(gold) 
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903
		{}


int Hero::getmaxHP() {
    return maxHP;
}


int Hero::getGold() {
    return gold;
}

int Hero::getATK() {
	return ATK;
}

int Hero::getDEF() {
	return DEF;
}


void Hero::addGold(int n){
	gold += n;
}


//	return the Hero
Hero* Hero::getHero() {
    return this;
}



Hero::~Hero() {}



<<<<<<< HEAD
Shade::Shade() : Hero(125, 25, 25, 0, 0, 125, 25, 25, "@", "Hero", 'Shade') {};
=======
Shade::Shade() : Hero(125, 25, 25, 0,0, 0, 125, 25, 25, '@', "Hero", "Shade") {};
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903

Shade::~Shade(){}




<<<<<<< HEAD
Drow::Drow() : Hero(150, 25, 15, 0, 0, 150, 25, 15, "@", "Hero", "Drow") {};
=======
Drow::Drow() : Hero(150, 25, 15, 0,0, 0, 150, 25, 15, '@', "Hero", "Drow") {};
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903

Drow::~Drow(){}


<<<<<<< HEAD
Vampire::Vampire() : Hero(0, 25, 25, 0, 0, 50, 25, 25,  "@", "Hero", "Vampire") {};
=======
Vampire::Vampire() : Hero(0, 25, 25,0, 0, 0, 50, 25, 25,  '@', "Hero", "Vampire") {};
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903

Vampire::~Vampire(){}

void Vampire::regen(int hp){
	real_hp += hp;
}




<<<<<<< HEAD
Troll::Troll() : Hero(120, 25, 15, 0, 0, 120, 25, 15, "@", "Hero", "Troll",) {};
=======
Troll::Troll() : Hero(120, 25, 15, 0,0 ,0, 120, 25, 15, '@', "Hero", "Troll") {};
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903

Troll::~Troll(){}


<<<<<<< HEAD
Goblin::Goblin() : Hero(110, 15, 20, 0, 0, 110, 15, 20, "@", "Hero", "Goblin") {};
=======
Goblin::Goblin() : Hero(110, 15, 20, 0,0, 0, 110, 15, 20, '@', "Hero", "Goblin") {};
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903

Goblin::~Goblin(){}

