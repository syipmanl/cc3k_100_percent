#include "gamesystem.h"
#include <iostream>
#include <fstream>
#include "map.h"
using namespace std;

string ASCII_DIR="../ascii_pictures/";
string BEGIN_ASCII=ASCII_DIR+"begin.txt";
string SELECTHERO_ASCII=ASCII_DIR+"selecthero.txt";
string WIN_ASCII=ASCII_DIR+"win_page.txt";
string LOST_ASCII=ASCII_DIR+"lost_page.txt";

void file_no_exist(string);
void print_file(string);
void print_intro();
void print_selectHero();
void print_win();
void print_lost();


void file_no_exist(string file_location) { cerr<<"Sorry, it seems "<<file_location<<" doesn't exist\n"; }

// print a txt file to standard output; exit when reading fail
void print_file(string file_location) {
    string line;
    ifstream infile{file_location};
    if (infile.fail()) { file_no_exist(file_location);exit(1);} // should throw exception here 
    while (!infile.eof()) { getline(infile,line); cout << line; }
    infile.close();
}

void print_intro() { print_file(BEGIN_ASCII);  }
void print_selectHero() { print_file(SELECTHERO_ASCII); }
void print_win() { print_file(WIN_ASCII); }
void print_lost() { print_file(LOST_ASCII); }
    
GameSystem::GameSystem(const string file_location):mp{nullptr}{
    ifstream infile{file_location};
    if(infile.fail()) file_no_exist(file_location); 
    mp=new Map(infile);
}



void GameSystem::playGame() {
    
    print_intro();
    
    
    print_selectHero();
    
    
    
    
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


