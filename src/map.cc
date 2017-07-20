#include "map.h"
#include <cassert>
#include "textdisplay.h"


using std::string;
using std::ifstream;

// check if the line is like
// "|-----------------------------|"
bool isboundary(const string line) {
    int i=0;
    assert(line[i]=='|');
    ++i;
    for (;i<line.size()-1;i++) {
        if (line[i]!='-') return false;
    }
    assert(line[i]=='|');
    return true;
}

// toggle parameter a
void toggle(bool & a) {
    a=a? false:true;
}


// load this file into floors
Map::Map(ifstream & map_file) {
    bool in_a_floor=false;
    int floor_num=1;
	string line;
    TextDisplay **tpp;
	while (getline(map_file, line)) {
        bool flag=isboundary(line);
		if (flag) toggle(in_a_floor);
        if (in_a_floor && flag) {
            TextDisplay *tp= new TextDisplay;
            tpp=&tp;
        }
        if (in_a_floor) {
            (*tpp)->addrow(line);
        } else {
            (*tpp)->addrow(line);
            Floor * A_floor = new Floor(floor_num,*tpp);
            tpp=nullptr;
            floors.push_back(A_floor);
            floor_num++;
        }
	}
}

// for testing now
ostream &operator<<(ostream &out,const Map &m) {
    
}

