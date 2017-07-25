#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "tile.h"
#include <string>

class Tile;

class Object {

protected:
    // string name; 
    const char symbol; // @, H, C. 
    const std::string type; // "Enemy", "Hero", "Gold", "Potion"
    Tile * position;
    
public:
    Object(char symbol,std::string type);
    virtual ~Object() = 0;
    virtual char getSymbol();
    virtual string getType();
    virtual Tile* getPosition();
	void setPosition(Tile * newpos);
    // Info getInfo();
};
#endif
