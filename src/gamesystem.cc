#include "gamesystem.h"
#include <iostream>
#include <fstream>
#include "map.h"
using namespace std;

string ASCII_DIR="../ascii_pictures/";
string BEGIN_ASCII=ASCII_DIR+"begin.txt";
string SELECTHERO_ASCII=ASCII_DIR+"selectHero.txt";
string WIN_ASCII=ASCII_DIR+"win_page.txt";
string LOST_ASCII=ASCII_DIR+"lost_page.txt";
string DROW_ASCII=ASCII_DIR+"drow.txt";
string TROLL_ASCII=ASCII_DIR+"troll.txt";
string GOBLIN_ASCII=ASCII_DIR+"goblin.txt";
string SHADE_ASCII=ASCII_DIR+"shade.txt";
string VAMPIRE_ASCII=ASCII_DIR+"vampire.txt";
void file_no_exist(string);
void print_file(string);
void print_intro() { print_file(BEGIN_ASCII);  }
void print_win() { print_file(WIN_ASCII); }
void print_lost() { print_file(LOST_ASCII); }

bool is_input_yes() {
    cout << "(y)es or (n)o"<<endl;
    string yes_or_no;
    cin>>yes_or_no;
    if (yes_or_no.substr(0,1)=="y") return true;
    return false;
}

/*
bool is_input_enter() {
    cout << "Press Enter to continue."<<endl;
    if (cin.get()=='\n') return true;
    return false;
}*/


void file_no_exist(string file_location) { cerr<<"Sorry, it seems "<<file_location<<" doesn't exist\n"; }

// print a txt file to standard output; exit when reading fail
void print_file(string file_location) {
    string line;
    ifstream infile{file_location};
    if (infile.fail()) { file_no_exist(file_location);exit(1);} // should throw exception here 
    while (!infile.eof()) { getline(infile,line); cout << line<<endl; }
    infile.close();
}

void chooseToPrintMap(Map * mp) {
    if (mp->isEmpty()) {
        cout <<"It seems you load an empty map. Would you like to print the map?"<<endl;
    } else {
        cout <<"It seems you load a non-empty map. Assume you are testing. Would you like to print the map?"<<endl;
    }
    if (is_input_yes()) {
        cout << *mp;
    }
}

bool GameSystem::isWon() {
    return true;
}
bool GameSystem::isLost() {
    return true;
}
    
    
void selectHero(string & hero) {
    print_file(SELECTHERO_ASCII); 
    string choice=" ";
    while (cin >> choice) {
        if (choice=="q"||choice=="quit") exit(0);
        if (choice=="s"||choice=="shade") {
            hero="shade";
            print_file(SHADE_ASCII);
            if (is_input_yes()) break;
        } else if (choice=="d"||choice=="drow") {
            hero="drow";
            print_file(DROW_ASCII);
            if (is_input_yes()) break;
        } else if (choice=="v"||choice=="vampire") {
            hero="vampire";
            print_file(VAMPIRE_ASCII);
            if (is_input_yes()) break;
        } else if (choice=="t"||choice=="troll") {
            hero="troll";
            print_file(TROLL_ASCII);
            if (is_input_yes()) break;
        } else if (choice=="g"||choice=="goblin") {
            hero="goblin";
            print_file(GOBLIN_ASCII);
            if (is_input_yes()) break;
        } else {
            cout<<"Invalid input. Please input e.g. \"s\" or \"shade\" and press enter."<<endl;
        }
        print_file(SELECTHERO_ASCII); 
    }
    cout << "You have selected "<<hero<<"."<<endl;
}



GameSystem::GameSystem(const string file_location):mp{nullptr}{
    ifstream infile{file_location};
    if(infile.fail()) file_no_exist(file_location); 
    mp=new Map(infile);
}



void GameSystem::playGame() {
    print_intro();
    cout << "Welcome to the dungeon." <<endl;
    chooseToPrintMap(mp);
    selectHero(mp->herotype);
    /*
    int turn=0;
    while (true) {
        
        
    }*/
    
    
    // after I load the map usr can print the whole map, I can tell whether or not a character is loaded (test map).
    // when a character is loaded, usr choose hero type and play the game
    // when a character is not loaded, usr choose hero type and prompt
    // "You go to next floor. It seems you don't have the skeleton on the floor in the map you bring. You are spawned randomly on this floor." 
    
    
    // "It seems you brought a empty map with you. The dungeon will bring some presents to you."
    // "It seems you brought a non-empty map with you."
    // after 20 turns, "You couldn't find a stair. You think the map suck."
    // "There are no skeleton '@' on this floor. You are spawned randomly in random chamber."
    // "You find a skeleton '@' of someone. You are spawned using the skeleton."
    // "Huf, that was not a sane thing to do."
    
    
    
    
	// most interface here
	// 0. intro, help, doc, saved game
	//
	// 1. choose character
	// 2. Set up first floor
	// On each floor // Generates character in random chamber 
	// Generates stairway location
	// Generates Potions
	// Generates Gold
	// Generates Enemies
	// 3. Accepts command to move
	// 4. Lost or Win or Next Floor
	// 5. Playagain or quit


}


