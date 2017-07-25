#include "map.h"
#include <cassert>
#include "textdisplay.h"
#include <iostream>

using namespace std;
bool isboundary(const string);

// check if the line is like
// "|-----------------------------|"
bool isboundary(const string line) {
    unsigned int i=0;
    assert(line[i]=='|');
    ++i;
    for (;i<line.size()-1;i++) {
        if (line[i]!='-') return false;
    }
    assert(line[i]=='|');
    return true;
}


// return true is the line has any character other than 
bool is_not_floor_object(const string line) {
    for (unsigned int i=0;i<line.size();i++) {
        char c=line[i];
        if (c!='|'||c!='-'||c!=' '||c!='.'||c!='+'||c!='#') {
            return true;
        }
    }
    return false;
}
    

// check if the line starts with SESSION
bool isSavedGame(const string line) {
    return "SESSION"==line.substr(0,7);
}

// toggle boolean parameter a
void toggle(bool & b) {
    b=b? false:true;
}


int Map::get_num_Of_floor() {return floors.size();}

bool Map::isEmpty() {
    return (isEmptyMap)? true:false;
}


// load a Map or translate saved game into map 
Map::Map(ifstream & map_file) {
    isEmptyMap=true;
    bool in_a_floor=false;
    int floor_num=1;
	string line;
    TextDisplay **tpp;
	while (getline(map_file, line)) {
        if (is_not_floor_object(line)) isEmptyMap=false;
        if (isSavedGame(line)) { // load from saved game
            
            //TO-DO
            //
            
        }
        bool flag=isboundary(line);
		if (flag) toggle(in_a_floor); // whenver hit a boundary, toggle in_a_floor
        if (in_a_floor && flag) {
            TextDisplay *tp= new TextDisplay;
            tpp=&tp;
        }
        if (in_a_floor) {
            (*tpp)->addrow(line);
        } else { // cause I hit a boundary again
            (*tpp)->addrow(line); // add the bottom boundary
            Floor * A_floor = new Floor(*tpp); // constructor for a floor, as well as set neighbours and calculate chambers
            tpp=nullptr;
            floors.push_back(A_floor);
            floor_num++;
        }
        flag=false;
	}
}

void Map::play_floor(int floor_num) {
    
    Floor * theFloor=floors[floor_num-1];
    theFloor->init(herotype);
    cout << *theFloor;
    // To-DO
    
}

// print out each floor
ostream &operator<<(ostream &out,const Map &m) {
    for (auto each: m.floors) {
        out << *each;
    }
    return out;
}

