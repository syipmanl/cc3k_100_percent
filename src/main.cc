#include <iostream>
#include <string>

#include "gamesystem.h"

using namespace std;

string DEFAUL_MAP="maps/layout_empty.txt";


// help information
void help() {
	cout << "Valid arguments:\n"
		"  cc3k                      Load the Default empty map($ROOTDIR/maps/layout_empty.txt)\n"
        "                            will randomly generate player, stair, potions, gold, enemies after you choose character.\n"
		"  cc3k [Location of File]   file can be empty map, map with character, map without character, a previous saved session.\n"
        "Note: provided maps are in $ROOT_DIR/maps/, saved game will be default in $ROOT_DIR/saved/\n"
		"  cc3k -h                   \n"
		"  cc3k --help               Print this help info\n";
}

// take care of arguments and pass option and file name to GameSystem
int main(int argc, char *argv[]) {
    string file_location;
    if (argc==1) {
        file_location=DEFAUL_MAP;
    } else if (argc==2) {
        string arg1{argv[1]};
        if (arg1=="-h"||arg1=="--help") {
            help();
            return 0;
        } else {
            file_location=arg1;
        }
    } else {
        cerr << "Invalid command.\n";
        help();
        exit(1);
    }
            
	
	GameSystem gs(file_location); // constructor
    gs.playGame(); // game starts and ends here
}
