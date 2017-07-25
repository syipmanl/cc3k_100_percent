#include "enemy.h"
#include "gold.h"
#include "tile.h"

using namespace std;


Enemy::Enemy(int ATK, int DEF, int HP, char symbol, string race, string type)
			: Character(ATK, DEF, HP, 0, 0, false, race, symbol, type) {}

// default drop gold
void Enemy::drop_gold(){
	int drop_rate = rand() % 2;
	Gold* pile = NULL;
	if(drop_rate != 0){
		pile = new NormalHoard();
	}
	else{
		pile = new SmallHoard();
	}
	pile->setPosition(position);
	position->setObject(pile);
}

<<<<<<< HEAD
Human::Human() : Enemy(20, 20, 140, 'H', "Human", "Enemy", false, true){}
=======
Human::Human() : Enemy(20, 20, 140, 'H', "Human", "Enemy"){}
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903

Human::~Human(){}

void Human::drop_gold(){
	Gold *p1 = new NormalHoard();
	Gold *p2 = new NormalHoard();
	p1->setPosition(position);
	position->setObject(p1);

	for(int i = 0; i < 8; i++){ // see which one is free to drop the gold
		Tile* current = position->getNeighbour(i);
		if(current && current->getSymbol() == '.' && !current->getObject()){
			p2->setPosition(current);
			current->setObject(p2);
		}
	}
}


<<<<<<< HEAD
Dwarf::Dwarf() : Enemy(20, 30, 100, 'W', "Dwarf", 'Enemy', false, true){}
Dwarf::~Dwarf(){}


Elf::Elf() : Enemy(30, 10, 140, 'E', "Elf", "Enemy", false, true){}
Elf::~Elf(){}


Orc::Orc() : Enemy(30, 25, 180, 'O', "Orc" "Enemy", false, true){}
Orc::~Orc(){}

bool Merchant::hostile = false;
Merchant::Merchant() : Enemy(70, 5, 30, 'M', "Merchant", "Enemy",false, false){}
=======
Dwarf::Dwarf() : Enemy(20, 30, 100, 'W', "Dwarf", "Enemy"){}
Dwarf::~Dwarf(){}


Elf::Elf() : Enemy(30, 10, 140, 'E', "Elf", "Enemy"){}
Elf::~Elf(){}


Orc::Orc() : Enemy(30, 25, 180, 'O', "Orc", "Enemy"){}
Orc::~Orc(){}

bool Merchant::hostile = false;
Merchant::Merchant() : Enemy(70, 5, 30, 'M', "Merchant", "Enemy"){}
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903
Merchant::~Merchant(){}
Merchant::getHostile

void Merchant::drop_gold(){
	MerchantHoard* pile = new MerchantHoard();
	pile->setPosition(position);
	position->setObject(pile);
}

<<<<<<< HEAD
Halfling::Halfling() : Enemy(15, 20, 100, 'L', "Halfling", "Enemy", false, true){}
Halfling::~Halfling(){}

// constructor with no hoard
Dragon::Dragon() : Enemy(20, 20, 150, 'D', "Dragon", "Enemy", false, true), drag_hoard(NULL){}
// constructor with hoard
Dragon::Dragon(DragonHoard* hoard) : Enemy(20, 20, 150, 'D', "Dragon", "Enemy", false, true), drag_hoard(hoard) {}
=======
Halfling::Halfling() : Enemy(15, 20, 100, 'L', "Halfling", "Enemy"){}
Halfling::~Halfling(){}

// constructor with no hoard
Dragon::Dragon() : Enemy(20, 20, 150, 'D', "Dragon", "Enemy"), hoard(NULL){}
// constructor with hoard
Dragon::Dragon(DragonHoard* hoard) : Enemy(20, 20, 150, 'D', "Dragon", "Enemy"), hoard(hoard) {}
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903
Dragon::~Dragon(){}

DragonHoard* Dragon::getHoard(){
	return hoard;
}

void Dragon::setHoard(DragonHoard* newhoard){
	hoard = newhoard;
}

Enemy::~Enemy() {}

