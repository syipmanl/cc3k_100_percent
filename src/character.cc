#include "character.h"
#include "tile.h"
#include "enemy.h"
#include "hero.h"
#include "gold.h"
#include <math.h>

using namespace std;

Character::Character(int ATK, int DEF, int HP, 
    int dif_atk, int dif_def, bool hit,
    string race, char symbol, string type):

Object( symbol,type),

ATK(ATK), DEF(DEF), HP(HP), dif_atk(dif_atk),
dif_def(dif_def), hit(hit), race(race) {}

bool Character::getHostile() {
    return hostile;
}
bool Character::getHit() {
    return hit;
}


int Character::getAtk() {
    return ATK;
}

int Character::getDef() {
    return DEF;
}

int Character::getHP() {
    return HP;
}

string Character::getRace() {
    return race;
}
string Character::getType() {
    return type;
}


// takes effect, modifies: dif_def/dif_atk -> DEF/ATK
// remind to set zero when new floor
void Character::usePotion(string effect, int maxHP) {
    if(effect == "RH") {
//        HP = min(HP + 10, maxHP);
    }
    else if(effect == "BA") {
        dif_atk += 5;
    }
    else if(effect == "BD") {
        dif_def += 5;
    }
    else if(effect == "PH") {
//        HP = max(HP + 10, 0);
    }
    else if(effect == "WA") {
        dif_atk -= 5;
    }
    else if(effect == "WD") {
        dif_def -= 5;
    }
    ATK += dif_atk;
    DEF -= dif_def;
}

// coverts direction into array index
void Character::CharacterMove(string direction){
    int index = 0;
    if     (direction == "no") index = 0;
    else if(direction == "ea") index = 1;
    else if(direction == "so") index = 2;
    else if(direction == "we") index = 3;
    else if(direction == "nw") index = 4;
    else if(direction == "ne") index = 5;
    else if(direction == "sw") index = 6;
    else if(direction == "se") index = 7;
    move(index);
}

// true if moved, false if not
bool Character::move(int index) {
    Tile* goal = position->getNeighbour(index); // set goal
    Object* goalObj = goal->getObject(); // goalObj: goal's object

    char goalCh = goal->getSymbol(); // goalCh: goal's symbol
    string goalType = goalObj->getType(); // goalType: goal's type

    bool moved; // true is moved, false is not moved

 //   Tile* current = position;

    if (type == "Hero") { // player is moving
        if (goalCh == '.') { // free slot
            moved = true;
        } 
        // else if(goalCh == '\\') {
        //     // cover this case in gamesystem.cc
        // }
        else if(goalType == "Gold") { 
            if(static_cast<Gold*>(goalObj)->DragonExist()) { // convert into gold*, not a dragon hoard
                moved = false;
            }
            else { // pick up gold, not a dragon hoard
                Hero* hero = static_cast<Hero *>(this); // set the hero
                int drop = static_cast<Gold*>(goalObj)->getAmt(); // set the money
                hero->addGold(drop); // add the money!
                delete goalObj; // delete the gold, had it's use
                moved = true;
            }
        }
        // if ((goalCh != '.' || goalType == "potion")
        else  { // blocked by obstacles
            moved = false;
        }
    }

    if (type == "enemy") {
        if(goalCh == '.') { // free tile
            moved = true;
        }
        // ((goalCh != '.' || goalType == "potion")

        else { // blocked by obstacles
            moved = false;
        }
    }
    if (moved) {
        setPosition(goal); // new position is at goal
        position->setObject(NULL); // old space points at null now
        goal->setObject(this);
    }  
    return moved;
}



//change HP field, but still alive? 
bool Character::Damaged(int n){
    HP = min (HP - n, 0);
    return (HP == 0);
}

// return true if defender is dead
 bool Character::Attack(Character* defender) {
    // get Attacker and Defender type and race;
    string atk_Type = getType(); 
    string def_Type = defender->getType();
    string atk_Race = getRace();
    string def_Race = defender->getRace();

    // stats for calculation
    int attack_stat = getAtk(); // attacker
    int defence_stat = defender->getDef(); // defender
    int dmg = ceil((100 / (100 + defence_stat)) * attack_stat); // dmg if applied
    bool dead; // true if dead
    int hit_miss = rand() % 2;

    if(def_Race == "Merchant"){
        bool hostile = true; //defender->getHostile();
        if (Merchant::hostile) {
            hit = true;
            dead = defender->Damaged(dmg);
        }
        else {
            Merchant::hostile = true;
        }
    }

    // 
    if(atk_Race == "Orc" && def_Race == "Goblin") { // (hero)orc attacks goblin
        hit = true;
        dead = defender->Damaged(ceil(dmg * 1.5));
    }

    // hero attacks halfling: 50/50 miss
    if(atk_Type == "Hero" && def_Race == "Halfling") { // hero attacks halfling
            if(hit_miss != 0) {
                hit = false;
                
                // geneate hit attack message
            }
            else{
                hit = true;
                dead = defender->Damaged(dmg);
                // generate miss damage message
            }
        }

    // vampire attacks dwarf: lose 5 hp
    // vampire attacks anyone else: get 5 hp
    if(atk_Race == "Vampire"){
        if(def_Race != "Dwarf"){
            HP += 5; // alex has to check if vampire hp = 0
        }
        else{
            Damaged(5); 
        }
        hit = true;
        dead = defender->Damaged(dmg);
    }

    // any other situation
    if(atk_Type == "Enemy" && def_Type == "Hero") {
            if(hit_miss != 0) {
                hit = false;
                hit = true;
                dead = defender->Damaged(dmg);
                // geneate hit attack message
            }
            else{
                hit = true;
                dead = defender->Damaged(dmg);
                // generate miss damage message
            }
    }

    if(atk_Type == "Hero" && def_Type == "Enemy") {
        hit = true;
        dead = defender->Damaged(dmg);
    }
    return dead;
}

    
Character::~Character() {}

