#ifndef __GAMESYSTEM_H__
#define __GAMESYSTEM_H__


class GameSystem {
	GameSystem();
	public:
		void LoadMap(const ifstream *);
		void LoadGame(const ifstream *);
		ofstream *SaveGame();

}
#endif

