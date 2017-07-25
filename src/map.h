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

    bool isEmptyMap;
   

public:
	Map(ifstream & map_file); 
    void play_floor(int floor_num);
    int get_num_Of_floor();
    bool isEmpty();
    string herotype;
	~Map(); // maybe not needed
	friend ostream &operator<<(ostream &out, const Map &m); // print the map, haven't used yet
};

#endif
