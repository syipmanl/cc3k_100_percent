#ifndef __MAP_H__
#define __MAP_H__

#include <fstream>
#include <vector>
#include "tile.h"
#include "floor.h"

using std::vector;
using std::ostream;
using std::ifstream;

class Map {
	vector<Floor *> floors;


public:
	Map(ifstream & map_file); 
    
	~Map(); // maybe not needed
	friend ostream &operator<<(ostream &out, const Map &m); // print the map, haven't used yet
};

#endif
