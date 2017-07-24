#include "enemy.h"
#include "gold.h"
#include "tile.h"

using namespace std;


Enemy::Enemy(int ATK, int DEF, int HP, string race, char symbol, string type, bool hostile)
			: Character(ATK, DEF, HP, 0, 0, false, race, symbol, type), hostile(hostile) {}


// default drop gold
void Enemy::dropGold(){
	int drop_rate = rand() % 2;
	Gold* pile = NULL;
	if(drop_rate != 0){
		t = new Normal();
	}
	else{
		t = new SmallHoard();
	}
	pile->setPosition(position);
	position->setObject(pile);
}

Human::Human() : Enemy(20, 20, 140, "Human", 'H', "Enemy", true){}

Human::~Human(){}

void Human::dropGold(){
	Gold *p1 = new NormalHoard();
	Gold *p2 = new NormalHoard();
	p1->setPosition(position);
	position->setObject(p1);

	for(int i = 0; i < 8; i++){ // see which one is free to drop the gold
		Tile* current = position->getNeighbour(i);
		if(current && current->getCh() == '.' && !current->getObject()){
			p2->setPosition(current);
			current->setObject(p2);
		}
	}
}


Dwarf::Dwarf() : Enemy(20, 30, 100, "Dwarf", 'W', 'Enemy', true){}

Dwarf::~Dwarf(){}


Elf::Elf() : Enemy(30, 10, 140, "Elf", 'E', "Enemy", true){}

Elf::~Elf(){}


Orc::Orc() : Enemy(30, 25, 180, "Orc", 'O', "Enemy", true){}

Orc::~Orc(){}

Merchant::Merchant() : Enemy(70, 5, 30, "Merchant", 'M', "Enemy",false){}

Merchant::~Merchant(){}

void Merchant::dropGold(){
	MerchantHoard* pile = new MerchantHoard();
	pile->setPosition(position);
	position->setObject(pile);
}

Halfling::Halfling() : Enemy(15, 20, 100, "Halfling", 'L', "Enemy", true){}

Halfling::~Halfling(){}

// constructor with no hoard
Dragon::Dragon() : Enemy(20, 20, 150, 'Dragon', 'D', "Enemy", true), hoard(NULL){}

// constructor with hoard
Dragon::Dragon(DragonHoard* hoard) : Enemy(20, 20, 150, "Dragon", 'D', "enemy", true), hoard(hoard) {}

Dragon::~Dragon(){}

DragonHoard* Dragon::getHoard(){
	return hoard;
}

void Dragon::setHoard(DragonHoard* newhoard){
	hoard = newhoard;
}

Enemy::~Enemy() {}
