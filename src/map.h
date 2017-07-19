#ifndef __MAP_H__
#define __MAP_H__

#include <fstream>
#include <vector>
#include "tile.h"
#include "textdisplay.h"
#include "floor.h"

using std::vector;
using std::ostream;
using std::ifstream;

class Map {
	vector<Floor> floors;

	TextDisplay *td;

public:

	Map(const ifstream * map_file);
	~Map();

	
	friend ostream &operator<<(ostream &out, const Map &m);
};

#endif
