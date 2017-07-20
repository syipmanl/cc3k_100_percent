#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <vector>
#include "tile.h"
#include "enemy.h"
#include "chamber.h"
#include "textdisplay.h"
using std::vector;
using std::ostream;

class Floor {
    int floor_num;
    TextDisplay *td;
	
	vector<vector< Tile *>> thefloor;
	vector<Enemey *> enemies;
	vector<Chamber *> chambers;

public:
    Floor(int floor_num,TextDisplay *tp);
	Chamber * random_available_chamber();

    friend ostream &operator<<(ostream &out, const Floor &fl);
};


#endif

