#include "floor.h"
#include "tile.h"
#include "object.h"
#include "potion.h"
#include "gold.h"



bool isWall_Or_Nothing(const char c) {
    return c=='|'||c=='-'||c==' ';
}

Object *translate(char ch) {
    if (ch=='.') {
        return new Object("air");
    } else if (ch=='|') {
        return new Object("wall_vert");
    } else if (ch=='-') {
        return new Object("wall_hori");
    } else if (ch=='#') {
        return new Object("passway");
    } else if (ch=='+') {
        return new Object("door");
    } else if (ch=='@') {
        return new Hero
    }    
        
        
        
        return nullptr;
    }
}

bool Floor::hasHero() {return (player)?true:false;}

Floor::Floor(TextDisplay* tp):td{tp},player{nullptr}{
    
    // initalize thefloor using td
    vector<string> *display=td->getDisplay();
    int height=display->size();
    int width=(*display).at(0).size();
    for (int i=0;i<height;i++) {
       for (int j=0;j<width;j++) {
           Tile *thetile=thefloor[i][j]; 
           Tile *north=(i-1>=0 && !isWall_Or_Nothing((*display).at(i-1).at(j)))? thefloor[i-1][j]:nullptr;  // if outofrange or Wall then nullptr
           Tile *south=(i+1<height && !isWall_Or_Nothing((*display).at(i+1).at(j)))? thefloor[i+1][j]:nullptr;
           Tile *east=(j+1<width && !isWall_Or_Nothing((*display).at(i).at(j+1)))? thefloor[i][j+1]:nullptr;
           Tile *west=(j-1>=0 && !isWall_Or_Nothing((*display).at(i).at(j-1)))? thefloor[i][j-1]:nullptr;
           Tile *northeast=(i-1>=0 && j+1<width && !isWall_Or_Nothing((*display).at(i-1).at(j+1)))? thefloor[i-1][j+1]:nullptr;
           Tile *northwest=(i-1>=0 && j-1>=0 && isWall_Or_Nothing((*display).at(i-1).at(j-1))) ? thefloor[i-1][j-1] : nullptr;
           Tile *southeast=(i+1<height && j+1<width && !isWall_Or_Nothing((*display).at(i+1).at(j+1)))?thefloor[i+1][j+1]:nullptr;
           Tile *southwest=(i+1<height && j-1>=0 && !isWall_Or_Nothing((*display).at(i+1).at(j-1)))?thefloor[i+1][j-1]:nullptr;
           char ch=(*display).at(i).at(j);
           Object *ob=translate(ch);
           thetile->setObject(ob); 
           ob->setPosition(thetile);
           if (ob->getType()=="hero") {
               player=ob;
           } else if (ob->getType()=="enemy") {
               enemies.push_back(ob);
           }            
           
           thetile->attach(northwest); // 0
           thetile->attach(north);     // 1
           thetile->attach(northeast); // 2
           thetile->attach(east);      // 3
           thetile->attach(southeast); // 4
           thetile->attach(south);     // 5
           thetile->attach(southwest); // 6
           thetile->attach(west);      // 7
           thetile->attachTd(td);       
       }
    }
    
    // initalize chambers
    for (int i=0; i<height;i++) {
        for (int j=0; j<width;j++) {
            Tile *thetile=thefloor[i][j];
           if (!thetile->inChamber && thetile) {
               Chamber *A_chamber=new Chamber;
               A_chamber->addTile(thetile);
               thetile->cascade_the_chamber(); 
               chambers.push_back(A_chamber);
           }
        }
    }
}

ostream &operator<<(ostream &out, const Floor &fl) {
    out<<*fl.td;
    return out;
}
