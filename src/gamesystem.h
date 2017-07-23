#ifndef __GAMESYSTEM_H__
#define __GAMESYSTEM_H__
#include "map.h"
#include "include/option.h"

using std::string;
using std::ofstream;
class GameSystem {
	Map *mp;
    Option op;

public:
    
        GameSystem(Option option);
		void loadFile(const string file_name); //translates the file to Map
        
		void playGame();

        /*
        // not used now
		void printGame(); // for developer only


		// bonus
		void loadGame(const string saved_name); //load saved game to current game

		ofstream *SaveGame(); // writes the current progress to a save file
		*/
		
};
#endif

