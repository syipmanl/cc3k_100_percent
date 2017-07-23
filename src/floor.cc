#include "floor.h"
#include "tile.h"
#include "floorobject.h"


bool isWall(const char c) {
    return c=='|'||c=='-';
}

Object *translate(int r, int c, char ch) {
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


Floor::Floor(TextDisplay* tp):td{tp}{
    
    // initalize thefloor using td
    
    vector<string> *display=td->getDisplay();
    int height=display->size();
    int width=(*display).at(0).size();
    for (int i=0;i<height;i++) {
       for (int j=0;j<width;j++) {
           Tile *thetile=thefloor[i][j]; 
           Tile *north=(i-1>=0 && !isWall((*display).at(i-1).at(j)))? thefloor[i-1][j]:nullptr;  // if outofrange or Wall then nullptr
           Tile *south=(i+1<height && !isWall((*display).at(i+1).at(j)))? thefloor[i+1][j]:nullptr;
           Tile *east=(j+1<width && !isWall((*display).at(i).at(j+1)))? thefloor[i][j+1]:nullptr;
           Tile *west=(j-1>=0 && !isWall((*display).at(i).at(j-1)))? thefloor[i][j-1]:nullptr;
           Tile *northeast=(i-1>=0 && j+1<width && !isWall((*display).at(i-1).at(j+1)))? thefloor[i-1][j+1]:nullptr;
           Tile *northwest=(i-1>=0 && j-1>=0 && isWall((*display).at(i-1).at(j-1))) ? thefloor[i-1][j-1] : nullptr;
           Tile *southeast=(i+1<height && j+1<width && !isWall((*display).at(i+1).at(j+1)))?thefloor[i+1][j+1]:nullptr;
           Tile *southwest=(i+1<height && j-1>=0 && !isWall((*display).at(i+1).at(j-1)))?thefloor[i+1][j-1]:nullptr;
           thetile->setObject(translate(i,j,(*display).at(i).at(j))); 
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
