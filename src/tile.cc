#include "object.h"
#include "tile.h"

using namespace std;

char Tile::getSymbol() {
    return symbol;
}

Object* Tile::getObject() {
    return theObject;
}

Tile* Tile::getNeighbour(int index) {
    return neighbours[index];
}
void Tile::set_tile(int new_row, int new_col, char new_symbol) {
    symbol = new_symbol;
    row = new_row;
    col = new_col;
    //neighbours = nullptr;
    td = nullptr;
    theObject = nullptr;
    inChamber = false;
}

// attach Tile * o to neightbours
void Tile::attach(Tile *new_neighbours) {
    neighbours.push_back(new_neighbours);
}

void Tile::attach_td(TextDisplay *new_td) {
    td = new_td;
}

void Tile::change_td(int row, int col, char ch) {
    td->change(row, col, ch);
}


void Tile::cascade_the_chamber(){
    for (auto each : neighbours) {
        if (each) {
            each->inChamber=true;
            each->cascade_the_chamber();
        } 
    }
}

void Tile::setObject(Object *ob) {
   theObject = ob;
   if (!theObject) {
        td->change(row,col,theObject->getSymbol()); // td[row][column] = symbol
   }
   else if(theObject) {
        td->change(row, col, symbol);
   }
}

void Tile::clearObject(){
    delete theObject;
    theObject = nullptr;
}



// Info Tile::getInfo(){
    
//     Info info;
//     info.row=row;
//     info.col=col;
//     info.type=theObject->getType();
//     return info;
// }
