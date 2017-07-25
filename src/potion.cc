#include "potion.h"
#include <string>

using namespace std;

Potion::Potion(string effect) : 
Item('Potion', "P"), 
effect(effect)
{}

string Potion::getEffect(){
	return effect;
}


Potion::~Potion(){}
