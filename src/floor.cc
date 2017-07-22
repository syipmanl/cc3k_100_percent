#include "floor.h"
#include "tile.h"
#include "floorobject.h"

Tile *translate(int r, int c, char ch) {
    
    if (ch=='.') {
        return new Air(r,c"air");
    } else if (ch=='|') {
        return new Wall(r,c,"wall_vert");
    } else if (ch=='-') {
        return new Wall(r,c,"wall_hori");
    } else if (ch=='#') {
        return new Passway(r,c,"passway");
    } else if (ch=='+') {
        return new Door(r,c,"door");
    } else {
        return nullptr;
    }
}

/*
void Floor::simple_initialize_chamber() {
    Chamber *chamb_1 = new Chamber;
    for (int i=3;i==6;i++) {
        for (int j=3;j==28;j++) {
            chamb_1->attachTile(thefloor[i][j]);
        }
    }
    chambers.push_back(chamb_1);
    Chamber *chamb_2 = new Chamber;
    for (int i=
    
}
*/


Floor::Floor(int floor_num, TextDisplay* tp):floor_num{floor_num},td{tp}{
    
    // initalize thefloor using td
    vector<string> *display=td->getDisplay();
    for (int i=0;i<display->size();i++) {
       for (int j=0;j<(*display).at(i).size();j++) {
           Tile *thetile=thefloor[i][j];
           Tile *north=((*display).at(i-1).at(j)=='.')?thefloor[i-1][j]:nullptr;
           Tile *south=((*display).at(i+1).at(j)=='.')?thefloor[i+1][j]:nullptr;
           Tile *east=((*display).at(i).at(j+1)=='.')?thefloor[i][j+1]:nullptr;
           Tile *west=((*display).at(i).at(j-1)=='.')?thefloor[i][j-1]:nullptr;
           Tile *northeast=((*display).at(i-1).at(j+1)=='.')?thefloor[i-1][j+1]:nullptr;
           Tile *northwest=((*display).at(i-1).at(j-1)=='.')?thefloor[i-1][j-1]:nullptr;
           Tile *southeast=((*display).at(i+1).at(j+1)=='.')?thefloor[i+1][j+1]:nullptr;
           Tile *southwest=((*display).at(i+1).at(j-1)=='.')?thefloor[i+1][j-1]:nullptr;
           thetile=translate(i,j,(*display).at(i).at(j));
           if (north) thetile->attach(north);
           if (south) thetile->attach(south);
           if (east) thetile->attach(east);
           if (west) thetile->attach(west);
           if (northeast) thetile->attach(northeast);
           if (northwest) thetile->attach(northwest);
           if (southeast) thetile->attach(southeast);
           if (southwest) thetile->attach(southwest);
           thetile->attach(td);
       }
    }
    
    // initalize chambers
    // I have an idea how to hard code it but we assume we know the map now
 //   simple_initialize_chamber(*this);
    
}

ostream &operator<<(ostream &out, const Floor &fl) {
    out<<*fl.td;
    return out;
}
