#ifndef __GAMESYSTEM_H__
#define __GAMESYSTEM_H__
#include "map.h"

using std::string;
using std::ofstream;
class GameSystem {
	Map *mp; // a pointer to a Map
	bool isWon();
    bool isLost();

public:
        GameSystem(const string file_location); // store the option usr makes
		void playGame(); // starts from choosing hero
};
#endif

