#ifndef __OBJECT_H__
#define __OBJECT_H__


#include "tile.h"
class Tile;

class Object {
	Tile * position;
    string name;
    string type;

public:
    Object(const string name);
	// setPosition
};
#endif
