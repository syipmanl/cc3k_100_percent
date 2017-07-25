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
        if (thetile->getObject()->getSymbol()=='.') {
            thetile->clearObject();
            thetile->setObject(ob);
            success=true;
        }
    }
}

bool Chamber::is_player_in_chamber(Tile * hero) {
    for (auto each: tiles) {
        if (each==hero) return true;
    }
    return false;
}
    
