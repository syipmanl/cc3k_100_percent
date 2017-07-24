#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <vector>
#include "tile.h"
#include "enemy.h"
#include "hero.h"
#include "chamber.h"
#include "textdisplay.h"
using std::vector;
// using std::ostream;

class Floor {
   // int floor_num; // may not need it
    TextDisplay *td;
	
	vector<vector< Tile *>> thefloor;
	vector<Enemey *> enemies;
	vector<Chamber *> chambers;
    Hero * theplayer;
    Object * thestair;
    int which_chamber_is_player_in();

public:
    bool hasHero();
    Floor(TextDisplay* tp);
    void init(const string herotype);
	Chamber * random_available_chamber();

    friend ostream &operator<<(ostream &out, const Floor &fl);
};


#endif

