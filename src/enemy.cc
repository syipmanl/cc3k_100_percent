#include "enemy.h"
#include "gold.h"
#include "tile.h"

using namespace std;


Enemy::Enemy(int ATK, int DEF, int HP, string race, char symbol, string type, bool hostile)
			: Character(Atk, Def, HP, race, symbol, type), hostile(hostile)
	{}

Enemy::~Enemy() {}


void Enemy::dropGold(){
	int chance = rand() % 2;
	Treasure* t = NULL;
	if(chance == 0){
		t = new SmallHoard();
	}
	else{
		t = new NormalHoard();
	}
	t->setPosition(position);
	position->setObject(t);
}

Human::Human() : Enemy(20, 20, 140, "H", 'Enemy', "Human", true){}

Human::~Human(){}

void Human::dropGold(){
	Piles *p1 = new NormalHoard();
	Piles *p2 = new NormalHoard();

	p1->setPosition(position);
	position->setObject(p1);

	for(int i = 0; i < 8; i++){
		Tile* current = position->getNeighbour(i);
		if(current && current->getCh() == '.' && !current->getObject()){
			p2->setPosition(current);
			current->setObject(p2);
			return;
		}
	}
	delete p2;
}


Dwarf::Dwarf() : Enemy(20, 30, 100, "W", 'Enemy', "Dwarf", true){}

Dwarf::~Dwarf(){}


Elf::Elf() : Enemy(30, 10, 140, 'E', "enemy", 'Elf', true){}

Elf::~Elf(){}


Orc::Orc() : Enemy(30, 25, 180, 'O', "enemy", "Orc", true){}

Orc::~Orc(){}




Merchant::Merchant() : Enemy(70, 5, 30, 'M', "enemy","Merchant",false){}

Merchant::~Merchant(){}

void Merchant::dropGold(){
	MerchantHoard* p = new MerchantHoard();
	p->setPosition(position);
	position->setObject(p);
	return;
}

Halfling::Halfling() : Enemy(15, 20, 100, 'L', "enemy", "Halfling", true){}

Halfling::~Halfling(){}


Dragon::Dragon() : Enemy(20, 20, 150, 'D', "enemy", "Dragon", true), hoard(NULL){}

Dragon::Dragon(DragonHoard* hoard) : Enemy(20, 20, 150, "Dragon", 'D', "enemy"), hoard(hoard) {}

Dragon::~Dragon(){}

void Dragon::dropGold(){
	return;
}

DragonHoard* Dragon::getHoard(){
	return hoard;
}

void Dragon::setHoard(DragonHoard* hd){
	hoard = hd;
}

