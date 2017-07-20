#ifndef __CELL_H__
#define __CELL_H__ 

#include "info.h"
#include "subject.h"
#include "observer.h"

class Tile: public Subject, public Observer{
	int col, row;
	

public:
    Tile(const int c, const int r, const string name);


};



#endif
