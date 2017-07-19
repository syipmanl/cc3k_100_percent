#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <vector>
#include "tile.h"
#include "enemy.h"
#include "chamber.h"

using std::vector;

class Floor {
	
	vector<vector< Tile *>> thefloor;
	vector<Enemey *> enemies;
	vector<Chamber> chambers;

public:
	Chamber * random_available_chamber();

};


#endif

