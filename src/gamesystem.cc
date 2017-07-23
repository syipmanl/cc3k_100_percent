#include "gamesystem.h"
#include <fstream>

#include "map.h"
using std::string;
using std::ofstream;

GameSystem::GameSystem(Option option):mp{nullptr},op{option}{}

void GameSystem::loadFile(const string file_name) {
    if (op==Option::LoadEmptyMap) {
        ifstream empty_map_file{"../maps/"+file_name};
        mp = new Map(empty_map_file); 
        
        // read into textdisplay
        // read into map 
        // read into chambers

        // initialize everything here before the character is spawned
    } else if (op==Option::LoadTestMap) {
        ifstream test_map_file{"../tests/"+file_name};
        mp = new Map(test_map_file); 
    } else if (op==Option::LoadfromGame) {
    }
}

void GameSystem::playGame() {
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


/*
// print the map to feel better
void GameSystem::printGame() {}


// bonus
void GameSystem::loadGame(const string saved_name) {}
ofstream *GameSystem::SaveGame() {}*/
