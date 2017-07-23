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
	string name;
	string type;
	vector<Tile *> neightbours;
	TextDisplay *td;
    Object *ob;

public:
    Tile(const int r, const int c, const string name);
    void attach(Tile* o);
    void attachTd();
    void notifyTd();
    virtual void notify(Tile whoNotified);
    void notifynighbours(); //add more parameter
    void setObject(Object *);
	Info getInfo();

};



#endif
