#ifndef __CHAMBER_H__
#define __CHAMBER_H__ 
#include "tile.h"

class Object;
class Chamber {
	vector<Tile *> tiles;
	
public:
    //bool attachUniqueTile(Tile *);
    bool is_player_in_chamber(Tile *);
    int size();
    void set_object_randomly(Object *ob);
    void addTile(Tile *t);
};

#endif
