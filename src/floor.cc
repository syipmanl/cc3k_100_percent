#include <stdlib.h>
#include <time.h>
#include "floor.h"
#include "tile.h"
#include "object.h"
#include "potion.h"
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
    

bool is_valid_neighbour(const char c) {
    if (c==' '||c=='-'||c=='|'||c=='+'||c=='#') {
        return false;
    } else {
        return true;
    }
}

bool is_floor_object(const char c) {
    if (c==' '||c=='.'||c=='+'||c=='/'||c=='#'||c=='-'||c=='|') {
        return true;
    } else {
        return false;
    }
}

bool is_enemy_object(const char c) {
    if (c=='H'||c=='W'||c=='E'||c=='O'||c=='M'||c=='D') {
        return true;
    } else {
        return false;
    }
}

bool is_gold_object(const char c) {
    if (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5') {
        return true;
    } else {
        return false;
    }
}
bool is_potion_object(const char c) {
    if (c=='6'||c=='7'||c=='8'||c=='9') {
        return true;
    } else {
        return false;
    }
}


Object *translate(char ch) {
    if (ch=='H') {
        return new Human;
    } else if (ch=='W') {
        return new Dwarf;
    } else if (ch=='E') {
        return new Elf;
    } else if (ch=='O') {
        return new Orc;
    } else if (ch=='M') {
        return new Merchant;
    } else if (ch=='D') {
        return new Dragon;
    } else if (ch=='L') {
        return new Halfling;
    } else if (ch=='0') {
        return new Potion("RH");
    } else if (ch=='1') {
        return new Potion("BA");
    } else if (ch=='2') {
        return new Potion("BD");
    } else if (ch=='3') {
        return new Potion("PH");
    } else if (ch=='4') { 
        return new Potion("WA");
    } else if (ch=='5') {  
        return new Potion("WD");
    } else if (ch=='6') {
        return new NormalHoard;
    } else if (ch=='7') { 
        return new SmallHoard;
    } else if (ch=='8') {
        return new MerchantHoard;
    } else if (ch=='9') {
        return new DragonHoard;
    } else {
        return nullptr;
    }
}

bool Floor::hasHero() const {return (init_hero_pos)?true:false;}


// Each Tile * will point to a valid Tile (no nullptr)
// neighbours of a Tile will be nullptr if it is ' ' or '|' or '-' or '+' or '#' shown on textdisplay (the map initially load in)
Floor::Floor(TextDisplay* tp):td{tp},thestair{nullptr},init_hero_pos{nullptr},theplayer{nullptr}{
    
    // initalize thefloor using td
    vector<string> *display=td->getDisplay();
    int height=display->size();
    int width=(*display).at(0).size();
    thefloor.resize(height);
    for (int i=0;i<height;i++) {
        thefloor.resize(width);
    }
    for (int i=0;i<height;i++) {
       for (int j=0;j<width;j++) {
           Tile *thetile=&thefloor[i][j]; 
           char ch=(*display).at(i).at(j);
           thetile->set_tile(i,j,ch);
           if (ch=='@') {
               init_hero_pos=thetile;
           } else if (!is_floor_object(ch)) {
            Object *ob=translate(ch);
            thetile->setObject(ob);
            ob->setPosition(thetile);
            if (is_enemy_object(ch)) {
                enemies.push_back(ob);
            } else if (is_gold_object(ch)) {
                thetile->change_td('G');
            } else if (is_potion_object(ch)) {
                thetile->change_td('P');
            }
           }
           Tile *north=(i-1>=0 && is_valid_neighbour((*display).at(i-1).at(j)))? &thefloor[i-1][j]:nullptr;  // if outofrange or Wall then nullptr
           Tile *south=(i+1<height && is_valid_neighbour((*display).at(i+1).at(j)))? &thefloor[i+1][j]:nullptr;
           Tile *east=(j+1<width && is_valid_neighbour((*display).at(i).at(j+1)))? &thefloor[i][j+1]:nullptr;
           Tile *west=(j-1>=0 && is_valid_neighbour((*display).at(i).at(j-1)))? &thefloor[i][j-1]:nullptr;
           Tile *northeast=(i-1>=0 && j+1<width && is_valid_neighbour((*display).at(i-1).at(j+1)))? &thefloor[i-1][j+1]:nullptr;
           Tile *northwest=(i-1>=0 && j-1>=0 && is_valid_neighbour((*display).at(i-1).at(j-1))) ? &thefloor[i-1][j-1] : nullptr;
           Tile *southeast=(i+1<height && j+1<width && is_valid_neighbour((*display).at(i+1).at(j+1)))?&thefloor[i+1][j+1]:nullptr;
           Tile *southwest=(i+1<height && j-1>=0 && is_valid_neighbour((*display).at(i+1).at(j-1)))?&thefloor[i+1][j-1]:nullptr;
           
           
           thetile->attach(north);     // 0
           thetile->attach(east);      // 1
           thetile->attach(south);     // 2
           thetile->attach(west);      // 3
           thetile->attach(northwest); // 4
           thetile->attach(northeast); // 5
           thetile->attach(southwest); // 6
           thetile->attach(southeast); // 7
           thetile->attach_td(td);       
       }
    }
    
    // initalize chambers
    for (int i=0; i<height;i++) {
        for (int j=0; j<width;j++) {
            Tile *thetile=&thefloor[i][j];
            char ch=thetile->getSymbol();
           if (!thetile->inChamber && ch!='-' && ch!='|' && ch!=' ') {
               Chamber *A_chamber=new Chamber;
               A_chamber->addTile(thetile);
               thetile->cascade_the_chamber(A_chamber); 
               chambers.push_back(A_chamber);
           }
        }
    }
}

// return the index of chamber which the player is in initially, return -1 if no chamber has player
int Floor::which_chamber_is_player_in() {
    for (int i=0;i<chambers.size();i++) {
        if (chambers[i]->is_player_in_chamber(init_hero_pos)) return i;
    }
    return -1;
}

char convert_num_into_char(int num) {
    return '0'+num;
}

void Floor::init(const string){}

/*
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
}*/

ostream &operator<<(ostream &out, const Floor &fl) {
    out<<*fl.td;
    return out;
}
