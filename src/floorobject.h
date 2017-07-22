#ifndef __FLOOROBJECT_H__
#define __FLOOROBJECT_H__

#include "tile.h"
#include "info.h"
#include "floorobjects/wall.h"
#include "floorobjects/stair.h"
#include "floorobjects/air.h"
#include "floorobjects/passway.h"
#include "floorobjects/door.h"

class FloorObject: public Tile {
    
	char sysmbol; // 'G' '\' '.' 'H' '|'
	string name;  // "wall_vert" "wall_hori" "stair" "air" "human" "shade" "vampire"
	string type;  // "stair" "air" "enemy" "player" "wall"

public: 
    FloorObject();
	Info getInfo();

};
#endif
