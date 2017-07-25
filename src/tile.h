#ifndef __TILE_H__
#define __TILE_H__


#include <vector>
#include "textdisplay.h"
#include "object.h"
using std::vector;

class Object;
class Tile{
    char symbol;    // 7 cases, '.' '/' '+' '#' '|' '-' ' '
    int row, col;
    vector<Tile *> neighbours;
    TextDisplay *td;
    Object *theObject;

public:
    bool inChamber; //
    char getSymbol();
    Object* getObject();
    void set_tile(int new_row,int new_col, char new_symbol); //
    void attach(Tile *new_neighbours); 
    void attach_td(TextDisplay *td);
    void change_td(int row, int col, char ch);
    //virtual void notify(Tile whoNotified);
    void cascade_the_chamber(); //add more parameter
    void setObject(Object *); //
    void clearObject(); 
    // Info getInfo();

};



#endif
