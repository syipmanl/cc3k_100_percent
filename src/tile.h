#ifndef __TILE_H__
#define __TILE_H__


#include <vector>
#include "textdisplay.h"
#include "object.h"
// #include "chamber.h"
using std::vector;

class Chamber;
class Object;
class Tile{
    char symbol;    // 7 cases, '.' '/' '+' '#' '|' '-' ' '
    int row, col;
    vector<Tile *> neighbours;
    TextDisplay *td;
    Object *theObject;

public:
    Tile();
    bool inChamber; //
    char getSymbol();
    Object* getObject();
    Tile * getNeighbour(int index);
    void set_tile(int new_row,int new_col, char new_symbol); //
    void attach(Tile *new_neighbours); 
    void attach_td(TextDisplay *td);
    void change_td(char ch);
    //virtual void notify(Tile whoNotified);
    // void cascade_the_chamber(Chamber *); //add more parameter
    void cascade_the_chamber(Chamber *thechamber); //add more parameter
    void setObject(Object *ob); //
    void clearObject(); 
    // Info getInfo();

};



#endif
