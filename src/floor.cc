#include <stdlib.h>
#include <time.h>
#include "floor.h"
#include "tile.h"
#include "object.h"
//#include "potion.h"
#include "gold.h"
#include <iostream>

using namespace std;

Hero *generateHero(const string herotype) {
    if (herotype=="shade") {
        return new Shade;
    } else if (herotype=="drow") {
        return new Drow;
    } else if (herotype=="troll") {
        return new Troll;
    } else if (herotype=="vampire") {
        return new Vampire;
    } else if (herotype=="goblin") {
        return new Goblin;
    } else {
        cerr<<"Error constructing hero type."<<endl;
    }
}
    

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
        return new Hero;
    } else if (ch=='H') {
        return new Human("human")
    } else if (ch=='W') {
        return new Dwarf("darf");
    } else if (ch=='E') {
        return new Elf("elf");
    } else if (ch=='O') {
        return new Orc("orc");
    } else if (ch=='M') {
        return new Merchant("merchant");
    } else if (ch=='D') {
        return new Dragon("dragon");
    } else if (ch=='L') {
        return new Halfing("halfing");
    } else if (ch=='0') {
        return new Potion("potion_RH");
    } else if (ch=='1') {
        return new Potion("potion_BA");
    } else if (ch=='2') {
        return new Potion("potion_BD");
    } else if (ch=='3') {
        return new Potion("potion_PH");
    } else if (ch=='4') { 
        return new Potion("potion_WA");
    } else if (ch=='5') {       
        return new Potion("potion_WD");
    } else if (ch=='6') {
        return new Gold("normalhoard");
    } else if (ch=='7') { 
        return new Gold("smallhoard");
    } else if (ch=='8') {
        return new Gold("merchanthoard");
    } else if (ch=='9') {
        return new Gold("dragonhoard");
    } else {
        return nullptr;
    }
}

bool Floor::hasHero() {return (theplayer)?true:false;}

Floor::Floor(TextDisplay* tp):td{tp},theplayer{nullptr},thestair{nullptr}{
    
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
               theplayer=ob;
           } else if (ob->getType()=="stair") {
               thestair=ob;
           } else if (ob->getType()=="enemy") {
               enemies.push_back(ob);
           }      // maybe more needs to keep track of      
           
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

int Floor::which_chamber_is_player_in() {
    for (int i=0;i<chambers.size();i++) {
        if (chambers[i]->is_player_in_chamber()) return i;
    }
    return -1;
}

char convert_num_into_char(int num) {
    return '0'+num;
}

void Floor::init(const string herotype) {
        // generate character
    Hero *hero=generateHero(herotype);
    if (!theplayer) { // find a '.' randomly and place it in random chamber
        srand(time(NULL));
        Chamber * random_chamber=chambers[rand() % chambers.size()];
        random_chamber->set_object_randomly(hero);
    } else { // delete Hero * and replace with the right one
        Info cell=theplayer->getInfo();
        Tile * thetile=thefloor[cell.row][cell.col];
        thetile->clearObject();
        thetile->setObject(hero);
    } 
        // generate stair
    if (!thestair) {
        Object *stair=new Object("stair");
        int num1=which_chamber_is_player_in();
        int num2=num1;
        while (num1==num2) {
        srand(time(NULL));
            num2=rand() % chambers.size();
            
        }
        chambers[num2]->set_object_randomly(stair);
    }
        // generate potion
    for (int i=1;i<=20;i++) {
        // random potion
        srand(time(NULL));
        int type_potion=rand() % 6;
        int ch=convert_num_into_char(type_potion);
        Potion *potion=translate(ch);
        // random chamber
        srand(time(NULL));
        int num_cham=rand() % chambers.size();
        chambers[num_cham]->set_object_randomly(potion);
    }
    
        
        // generate gold
    for (int i=1;i<=10;i++) {
        srand(time(NULL));
        int type_gold=rand() %8 +1;
        char ch_gold;
        if (type_gold>=1 && type_gold<=2) {
            ch_gold='7';
        } else if (type_gold>=3 && type_gold<=7) {
            ch_gold='6';
        } else {
            ch_gold='9';
        }
        Gold *gold=translate(ch_gold);
        srand(time(NULL));
        int num_cham=rand() % chambers.size();
        chambers[num_cham]->set_object_randomly(gold);
    }
    
            
        // generate enemies
    for (int i=1;i<=20;i++) {
        srand(time(NULL));
        int type_enemy=rand() % 18+1;
        char ch_enemy;
        if (type_enemy>=1 && type_enemy<=4) {
            ch_enemy='H';
        } else if (type_enemy>=5 && type_enemy<=7) {
            ch_enemy='W';
        } else if (type_enemy>=8 && type_enemy<=9) {
            ch_enemy='E';
        } else if (type_enemy>=9 && type_enemy<=11) {
            ch_enemy='O';
        } else if (type_enemy>=12 && type_enemy<=13) {
            ch_enemy='M';
        } else {
            ch_enemy='L';
        }
        Enemy *enemy=translate(ch_enemy);
        srand(time(NULL));
        int num_cham=rand() % chambers.size();
        chambers[num_cham]->set_object_randomly(enemy);
    }
}

ostream &operator<<(ostream &out, const Floor &fl) {
    out<<*fl.td;
    return out;
}
