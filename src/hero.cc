
#include "hero.h"
#include "enemy.h"
#include "tile.h"

#include <math.h>
using namespace std;


Hero::Hero(int maxHP, int ATK, int DEF,int gold, 
		int dif_atk, int dif_def,
		int real_atk, int real_def,
		char symbol, std::string type, std::string race):

		// Character(ATK, DEF, maxHP, dif_atk, dif_def, 
		// 	real_atk, real_def, 
		// 	hit, race, symbol, type), 
		// maxHP(maxHP), gold(gold),
		// int read_hp, int real_atk, int real_def,
		// char symbol, std::string type, std::string race):

		Character(ATK, DEF, maxHP, dif_atk, dif_def, 
			false, race, symbol, type), 
		maxHP(maxHP), gold(gold)
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






Shade::Shade() : Hero(125, 25, 25, 0, 0, 125, 25, 25, '@', "Hero", "Shade") {};
Shade::~Shade(){}




Drow::Drow() : Hero(150, 25, 15, 0, 0, 150, 25, 15, '@', "Hero", "Drow") {};
Drow::~Drow(){}




Vampire::Vampire() : Hero(0, 25, 25, 0, 0, 50, 25, 25,  '@', "Hero", "Vampire") {};
Vampire::~Vampire(){}

void Vampire::regen(int hp){
	HP += hp;
}


Troll::Troll() : Hero(120, 25, 15, 0 ,0, 120, 25, 15, '@', "Hero", "Troll") {};
Troll::~Troll(){}

Goblin::Goblin() : Hero(110, 15, 20, 0, 0, 110, 15, 20, '@', "Hero", "Goblin") {};

Goblin::~Goblin(){}

