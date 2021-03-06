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
	
	vector<vector< Tile >> thefloor;
	vector<Object *> enemies;
	vector<Chamber *> chambers;
    Tile * thestair;
    Tile * init_hero_pos;
    Hero * theplayer;
    int which_chamber_is_player_in();

public:
    bool hasHero() const;
    Floor(TextDisplay* tp);
    void init(const string herotype);
	Chamber * random_available_chamber();
    void random_generate_object_on_floor(Object *ob);

    friend ostream &operator<<(ostream &out, const Floor &fl);
};


#endif

