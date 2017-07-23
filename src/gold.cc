#include "gold.h"
#include "enemy.h"
#include "tile.h"
#include <string>

using namespace std;

Gold::Gold(char symbol, string type, int value, string size) : Item(symbol, type), size(size), value(value){}

Gold::~Gold(){}

int Gold::getValue(){
	return value;
}

string Gold::getSize(){
	return size;
}

Dragon* Gold::getDragon(){
	return NULL;
}

void Gold::deleteDragon(){
	return;
}


NormalHoard::NormalHoard() : Gold('G', "Gold", 2, "Normal"){}

NormalHoard::~NormalHoard(){}



SmallHoard::SmallHoard() : Gold('G', "Gold", 1, "Small"){}

SmallHoard::~SmallHoard(){}



MerchantHoard::MerchantHoard() : Gold('G', "Gold", 4, "Merchant"){}

MerchantHoard::~MerchantHoard(){}



DragonHoard::DragonHoard() : Gold('G', "Gold", 6, "Dragon"){
	dragon = new Dragon(this);
}

DragonHoard::DragonHoard(Dragon* dragon) : Gold('G', "Gold", 6, "Dragon"), dragon(dragon){}


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

