#include <iostream>
#include <fstream>
#include <string>

#include "gamesystem.h"

using namespace std;

string DEFAUL_MAP="layout0.txt";

// prints the usage of executing this file
void usage() {
	cerr << "Usage: cc3k [OPTION] [MAP]\nFor example\n cc3k -h" << endl;
}

void help() {
	cout << ""<<endl;
}

int main(int argc, char *argv[]) {
	typedef int OPTION;
	enum {Default=0, LoadfromGame, LoadMap, Help};

	OPTION option;
	
	if (argc==1) {
		option=Default;
	} else {
		string arg1{argv[1]};
		if (arg1=="--help"||arg1=="-h") {
			option=Help;
		} else if (arg1=="--map"||arg1=="-m") {
			option=LoadMap;
			if (argv!=3) {
				cerr<<"Incorrect number of arguments"<<endl;usage();exit(1);
			}
		} else if (arg1=="--load"||arg1=="-l") {
			option=LoadfromGame;
			if (argv!=3) {
				cerr<<"Incorrect number of arguments"<<endl;usage();exit(1);
			}
		} else {
			usage();
			exit(1);
		}
	}

	GameSystems gs;
	ifstream map_file;
	fstream game_file;
	switch (option) {
		case Default:
			string map{DEFAUL_MAP};
			string file_location{"maps/"+map};
			map_file.open(file_location);
			gs.LoadMap(&map_file);

		case LoadMap:
			string map{argv[2]};
			string file_location{"maps/"+map};
			map_file.open(file_location);
			gs.LoadMap(&map_file);

		case LoadfromGame:
			string loadedgame{argv[2]};
			map_file.open(loadedgame);
			gs.LoadMap(&map_file);
			gs.LoadGame(&game_file);
			// bonus
		case Help:
			help();
		}
}
