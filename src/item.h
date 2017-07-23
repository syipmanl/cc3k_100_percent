#ifndef _ITEM_H
#define _ITEM_H

#include "object.h"
#include <string>


class Item: public Object {
public: 
	
	Item(char symbol, std::string type);
	
	~Item();
};

#endif //_ITEM_H
