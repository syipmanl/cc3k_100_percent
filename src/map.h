#ifndef __MAP_H__
#define __MAP_H__

#include <fstream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"

using std::vector;
using std::ostream;

class Map {
	vector<vector<Cell*>> theMap; //The Actual Map
	TextDisplay *td;

	void reset();

public:

	Map(const ifstream * map_file);
	~Map();

	
	friend ostream &operator<<(ostream &out, const Map &m);
}

#endif
