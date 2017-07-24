#include "tile.h"



Tile::Tile(const int r, const int c):row{r},col{c},td{nullptr},ob{nullptr},inChamber{false}{
}


void Tile::cascade_the_chamber(){
    for (auto each : neightbours) {
        if (each) {
            each->inChamber=true;
            each->cascade_the_chamber();
        } 
    }
}

void Tile::clearObject(){delete theObject;}

void Tile::setObject(Object *ob) {
   theObject = ob;
    if (!ob->isFloorObject()) {
        td->set(row,col,theObject->getSymbol()); // td[row][column] = symbol
   }
}

// attach Tile * o to neightbours
void Tile::attach(Tile *o) {neightbours.push_back(o);}

Info Tile::getInfo(){
    
    Info info;
    info.row=row;
    info.col=col;
    info.type=theObject->getType();
    return info;
}
