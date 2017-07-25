
#include "hero.h"
#include "enemy.h"
#include "tile.h"
#include "utilities.cc"

using namespace std;


Hero::Hero(int maxHP, int ATK, int DEF,int gold, 
		int dif_hp, int dif_atk, int dif_def,
		int real_hp, int real_atk, int real_def, 
		char symbol, std::string type, std::string race):

		Character(ATK, DEF,HP, symbol, type, race), 
		maxHP(maxHP), ATK(ATK), DEF(DEF), 
		dif_hp(dif_hp), dif_atk(dif_atk), dif_def(dif_def),
		real_hp(real_hp), real_hp(real_atk), real_def(real_def),
		gold(gold)
			{}

// return Hero MAX_HP
int Hero::getmaxHP() {
    return maxHP;
}

// return Hero gold
int Hero::getGold() {
    return gold;
}

int Hero::getATK() {
	return ATK;
}

int Hero::getDEF() {
	return DEF;
}

// add n gold to Hero gold
void Hero::addGold(int n){
	gold += n;
}


//	return the Hero
Hero* Hero::getHero() {
    return this;
}


// pure virtual destractor to make class abstract
Hero::~Hero() {}

/**
 *	heal Hero n amount of HP
 *	HP can't exceed maxHP
 */
void Hero::heal(int n) {
	dif_hp += n;
	real_hp += dif_hp 
	if (real_hp > maxHP)
		real_hp = maxHP;
    return;
}

// move method for Hero. 
// convert d to int and call Character::move(int d)
/**
 * move mthod
 * for d:int
 * 0: nw, 1: no, 2: ne, 3: we
 * 4: ea, 5: sw, 6: so, 7: se
 */
void Hero::HeroMove(string direction){
	if 	   (direction == "nw") move(0);
	else if(direction == "no") move(1);
	else if(direction == "ne") move(2);
	else if(direction == "we") move(3);
	else if(direction == "ea") move(4);
	else if(direction == "sw") move(5);
	else if(direction == "so") move(6);
	else if(direction == "se") move(7);

}


// Hero::Hero(int maxHP, int ATK, int DEF,int gold, 
// 		int dif_hp, int dif_atk, int dif_def
// 		int real_hp, int real_atk, int real_def, 
// 		char symbol, std::string type, std::string race):

// 		Character(ATK, DEF, 
// 			dif_hp, dif_atk, dif_def,
// 			real_hp, real_atk, real_def
// 			symbol, type, race), 

// 		maxHP(maxHP), ATK(ATK), DEF(DEF), gold(gold)
// 			{}

// implementation for Shade
Shade::Shade() : Hero(125, 25, 25, 0, 0, 0, 125, 25, 25, "@", "Hero", 'Shade') {};

Shade::~Shade(){}



// implementation for Drow
Drow::Drow() : Hero(150, 25, 15, 0, 0, 0, 150, 25, 15, "@", "Hero", "Drow") {};

Drow::~Drow(){}


// implementation for Vampire, no max, hence why it is zero
Vampire::Vampire() : Hero(0, 25, 25, 0, 0, 0, 50, 25, 25,  "@", "Hero", "Vampire") {};

Vampire::~Vampire(){}

// override Heal method since Vampire has no maximum HP
void Vampire::regen(int hp){
	real_hp += hp;
}




// implmentation for Troll
Troll::Troll() : Hero(120, 25, 15, 0, 0, 0, 120, 25, 15, "@", "Hero", "Troll",) {};

Troll::~Troll(){}


// implementation for Goblin
Goblin::Goblin() : Hero(110, 15, 20, 0, 0, 0, 110, 15, 20, "@", "Hero", "Goblin") {};

Goblin::~Goblin(){}

