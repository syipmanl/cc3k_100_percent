#ifndef __TILE_H__
#define __TILE_H__

#include "info.h"
#include <vector>
#include "textdisplay.h"
#include "object.h"
using std::vector;

class Object;
// A Tile is a Cell+Subject+Observer-Object
class Tile{
	int row, col;
	vector<Tile *> neightbours;
	TextDisplay *td;
    Object *theObject;

public:
    bool inChamber;
    Tile(const int r, const int c);
    void attach(Tile* o);
    void attachTd(TextDisplay *td);
    void notifyTd();
    //virtual void notify(Tile whoNotified);
    void cascade_the_chamber(); //add more parameter
    void setObject(Object *);
    void clearObject();
	Info getInfo();

};



#endif
