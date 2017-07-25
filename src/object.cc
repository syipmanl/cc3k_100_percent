#include "object.h"

using namespace std;

Object::Object(string type, char symbol): type(type), symbol(symbol), position(NULL)
{}
 // if (name == "air"||name=="stair"||name=="door"||name=="passway"||name=="wall_vert"||name=="wall_hori") {
	//  type="floorobject";
 // } else if (name=="shade"){ //To_DO
 //     type="Hero";
 // }

char Object::getSymbol(){
	return symbol;
}

string Object::getType(){
	return type;
}

void Object::setPosition(Tile * newpos) {
    position = newpos;
}

Tile * Object::getPosition() {
	return position;
}


// Info Object::getInfo(){
//     Info info=position->getInfo();
// }

Object::~Object() {}

// public:
//     Object(std::string type, char symbol);
//     virtual ~Object() = 0;
//     virtual std::string getRace() = 0;
//     virtual char getSymbol();
//     virtual string getType();
//     virtual Tile* getPosition();
// 	void setPosition(Tile * newpos);
//     // Info getInfo();
// };