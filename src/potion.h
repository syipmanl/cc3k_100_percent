#ifndef _POTION_H
#define _POTION_H

#include <string>
#include "item.h"

class Potion : public Item {
private:
	std::string effect;
public:
	Potion(std::string effect);
	~Potion();
	std::string getEffect();
};

#endif 
