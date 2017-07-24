#include "chamber.h"
#include <stdlib.h>
#include <time.h>

int Chamber::size() {return tiles.size();}

void Chamber::addTile(Tile *t) {tiles.push_back(t);}

void Chamber::set_object_randomly(Object *ob) {
    bool success=false;
    while (!success) {
        srand(time(NULL));
        Tile * thetile=tiles[rand() % tiles.size() -1];
        Info info=thetile->getInfo();
        if (info.type=="air") {
            thetile->clearObject();
            thetile->setObject(ob);
            success=true;
        }
    }
}

bool Chamber::is_player_in_chamber() {
    for (auto each: tiles) {
      Info info=each->getInfo();
      if (info.type=="hero") return true;
    }
    return false;
}
    
