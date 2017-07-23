#include "gold.h"
#include "enemy.h"
#include "tile.h"
#include <string>

using namespace std;

Treasure::Treasure(char symbol, string type, int value, string size) : Item(symbol, type), size(size), value(value){}

Treasure::~Treasure(){}

int Treasure::getValue(){
	return value;
}

string Treasure::getSize(){
	return size;
}

Dragon* Treasure::getDragon(){
	return NULL;
}

void Treasure::deleteDragon(){
	return;
}


NormalHoard::NormalHoard() : Treasure('G', "treasure", 2, "Normal"){}

NormalHoard::~NormalHoard(){}



SmallHoard::SmallHoard() : Treasure('G', "treasure", 1, "Small"){}

SmallHoard::~SmallHoard(){}



MerchantHoard::MerchantHoard() : Treasure('G', "treasure", 4, "Merchant"){}

MerchantHoard::~MerchantHoard(){}



DragonHoard::DragonHoard() : Treasure('G', "treasure", 6, "Dragon"){
	dragon = new Dragon(this);
}

DragonHoard::DragonHoard(Dragon* dragon) : Treasure('G', "treasure", 6, "Dragon"), dragon(dragon){}


DragonHoard::~DragonHoard(){
	if(dragon && dragon->getPosition()){
		dragon->getPosition()->setObject(NULL);
	}
	delete dragon;
}

Dragon* DragonHoard::getDragon(){
	return dragon;
}

void DragonHoard::deleteDragon(){
	dragon->getPosition()->setObject(NULL);
	delete dragon;
	dragon = NULL;
}

void DragonHoard::setDragon(Dragon* drag){
	dragon = drag;
}
