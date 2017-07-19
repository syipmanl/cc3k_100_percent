#ifndef __GAMESYSTEM_H__
#define __GAMESYSTEM_H__
#include "map.h"

using std::string;
using std::ofstream;
class GameSystem {
	Map *mp;

public:
    
        GameSystem();
		void loadMap(const string map_name); //translates the file to Map
		//void gameInit(); //might not needed
		void playGame();


		void printGame(); // for developer only


		// bonus
		void loadGame(const string saved_name); //load saved game to current game

		ofstream *SaveGame(); // writes the current progress to a save file
		
};
#endif
