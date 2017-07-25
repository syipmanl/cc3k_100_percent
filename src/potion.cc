#include "potion.h"
#include <string>

using namespace std;

Potion::Potion(string effect) : Item('P',"Potion"), 
effect(effect)
{}

string Potion::getEffect(){
	return effect;
}


Potion::~Potion(){}
