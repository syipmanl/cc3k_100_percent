#include <iostream>
#include <string>

#include "gamesystem.h"

using namespace std;

string DEFAUL_MAP="layout_empty.txt";

void usage() {
	cerr << "Usage: cc3k [OPTION] [MAP]\nSee Help\n cc3k -h" << endl;
}

void help() {
	cout << "Valid arguments:\n"
		"\tcc3k\tload the Default map(layout0.txt)\n"
		"\tcc3k -m [File_name]\nOr"
		"\tcc3k --map [File_name]\tload the map of number, For example, layout0.txt\n"
		"\tcc3k -l [File_name]\nOr"
		"\tcc3k --load [File_name]\tload previous session, For example, saved0.txt\n"
		"\tcc3k -h\nOr"
		"\tcc3k --help\tto see this help info\n"<<endl;
}

int main(int argc, char *argv[]) {
	typedef int OPTION;
	enum {Default=0, LoadMap, LoadfromGame, Help};

	OPTION option;
	
	if (argc==1) {
		option=Default;
	} else {
		string arg1{argv[1]};
		if (arg1=="--help"||arg1=="-h") {
			option=Help; 
		} else if (arg1=="--map"||arg1=="-m") {
			option=LoadMap;
			if (argc!=3) {
				cerr<<"Incorrect number of arguments"<<endl;usage();exit(1);
			}
		} else if (arg1=="--load"||arg1=="-l") {
			option=LoadfromGame;
			if (argc!=3) {
				cerr<<"Incorrect number of arguments"<<endl;usage();exit(1);
			}
		} else {
			usage();
			exit(1);
		}
	}

	if (option==Help) {help();return 0;}

	GameSystem gs;
	switch (option) {
		case Default:
			gs.loadMap(DEFAUL_MAP);

		case LoadMap:
			string map_name{argv[2]};
			gs.loadMap(map_name);

			// bonus
		case LoadfromGame:
			string saved_name{argv[2]};
			gs.loadGame(saved_name);
	}
}
