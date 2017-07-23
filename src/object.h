#ifndef __OBJECT_H__
#define __OBJECT_H__


#include "tile.h"
class Tile;

class Object {
	Tile * position;
    string name; 
    string type; // "hero", "enemy", "floorobject"
    char symbol;
    
public:
    char getSymbol();
    string getType();
    bool isFloorObject() const;
    Object(const string name);
	void setPosition(Tile * pos);
};
#endif
