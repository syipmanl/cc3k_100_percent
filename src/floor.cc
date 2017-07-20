#include "floor.h"
#include "tile.h"
#include "floorobjects/wall.h"
#include "floorobjects/stair.h"
#include "floorobjects/air.h"

Tile *translate(int r, int c, char ch) {
    
    if (ch=='.') {
        return Air(r,c"air");
    } else if (ch==' ') {
        return nullptr;
    } else if (ch=='|') {
        return Wall(r,c,"wall_vert");
    } else if (ch=='-') {
        return Wall(r,c,"wall_hori");
    } 
}

Floor::Floor(int floor_num, TextDisplay* tp):floor_num{floor_num},td{tp}{
    
    // initalize thefloor using td
    vector<string> *display=td->getDisplay();
    for (int i=0;i<display->size();i++) {
       for (int j=0;j<(*display).at(i).size();j++) {
           thefloor[i][j]=translate(i,j,(*display).at(i).at(j));
       }
    }
    
    // initalize chambers
    
    
}

ostream &operator<<(ostream &out, const Floor &fl) {
    out<<*fl.td;
    return out;
}
