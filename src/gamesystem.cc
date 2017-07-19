#include "gamesystem.h"
#include <fstream>

using std::string;
using std::ofstream;

GameSystem::GameSystem():mp{nullptr}{}

void GameSystem::loadMap(const string map_name) {
	ifstream map_file{"maps/"+map_name};
	// read into textdisplay
	// read into map 
	// read into chambers

	// initialize everything here before the character is spawned
}

void GameSystem::playGame() {
	// most interface here
	// 0. intro, help, doc, saved game
	//
	// 1. choose character
	// 2. Set up first floor
	// On each floor
	// Generates character in random chamber 
	// Generates stairway location
	// Generates Potions
	// Generates Gold
	// Generates Enemies
	// 3. Accepts command to move
	// 4. Lost or Win or Next Floor
	// 5. Playagain or quit


}



// print the map to feel better
void GameSystem::printGame() {}


// bonus
void GameSystem::loadGame(const string saved_name) {}
ofstream *GameSystem::SaveGame() {}
