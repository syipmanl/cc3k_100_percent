#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "tile.h"
#include <string>

class Tile;

class Object {

protected:
    // string name; 
    const std::string type; // "enemy", "hero"
    const char symbol; // @, H, C
    Tile * position;
    
public:
    Object(std::string type, char symbol);
    virtual ~Object() = 0;
    virtual std::string getRace() = 0;
    virtual char getSymbol();
    virtual string getType();
    virtual Tile* getPosition();
	void setPosition(Tile * newpos);
    // Info getInfo();
};
#endif
