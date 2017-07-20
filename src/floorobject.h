#ifndef __FLOOROBJECT_H__
#define __FLOOROBJECT_H__

#include "tile.h"
#include "info.h"
class FloorObject: public Tile {
	char sysmbol; // 'G' '\' '.' 'H' '|'
	string name;  // "wall_vert" "wall_hori" "stair" "air" "human" "shade" "vampire"
	string type;  // "stair" "air" "enemy" "player" "wall"

public: 
	Info getInfo();

};
#endif
