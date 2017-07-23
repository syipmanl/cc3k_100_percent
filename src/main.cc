#include <iostream>
#include <string>
#include "include/option.h"

#include "gamesystem.h"

using namespace std;

string DEFAUL_MAP="layout_empty.txt";


void help() {
	cout << "Valid arguments:\n"
		"\tcc3k\tload the Default empty map(layout_empty.txt) and generate player, stair, potions, gold, enemies.\n"
        "\tcc3k [File_name]\tOr\n"
        "\tcc3k -t [File_name]\tOr\n"
        "\tcc3k --test [File_name]\tload a test map.\n"
		"\tcc3k -m [File_name]\nOr"
		"\tcc3k --map [File_name]\tload an empty map. For example, layout_empty.txt.\n"
		"\tcc3k -l [File_name]\nOr"
		"\tcc3k --load [File_name]\tload previous session, For example, saved0.txt.\n"
		"\tcc3k -h\nOr"
		"\tcc3k --help\tto see this help info\n"<<endl;
}

int main(int argc, char *argv[]) {
    Option option; 
    
    string file_name;
	
	if (argc==1) {
        file_name=DEFAUL_MAP;
		option=Option::LoadEmptyMap;
	} else if (argc==2) {
        string arg1{argv[1]};
        if (arg1=="--help"||arg1=="-h") {
            help();exit(1);
		} else {
            file_name=arg1;
            option=Option::LoadTestMap;
        }
    } else if (argc==3) {
        string op{argv[1]};
        if (op=="--test"||op=="-t") {
            option=Option::LoadTestMap;
        } else if (op=="--map"||op=="-m") {
            option=Option::LoadEmptyMap;
        } else if (op=="--load"||op=="-l") {
            option=Option::LoadfromGame;
        }
        file_name=argv[2];
    } else {
        cerr<<"Incorrect number of arguments"<<endl;help();exit(1);
	}

	
	
	GameSystem gs(Option option);
    gs.loadFile(file_name);
    gs.playGame();
}
