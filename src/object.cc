#include "object.h"


Object::Object(const string name) {
 if (name == "air"||name=="stair"||name=="door"||name=="passway"||name=="wall_vert"||name=="wall_hori") {
	 type="floorobject";
 } else if (name=="shade"){ //To_DO
     type="Hero";
 }
}

char Object::getSymbol(){return symbol;}
void Object::setPosition(Tile * pos) {
    position=pos;
}

bool Object::isFloorObject() const {
    return type=="floorobject";
}

string Object::getType(){return type;}
