#include <iostream>
#include <string>

using namespace std;


// prints the usage of executing this file
void usage() {
	cerr << "........." << endl;
}


int main(int argc, char *argv[]) {
	typedef int OPTION;
	// for sure to change it
	//
	enum {Default=0, LoadfromSavedfile, LoadMap, Bonus, Test1, Test2/*,Test3... etc., extra feature*/};

	OPTION option;
	
	if (argc==1) {
		option=Default;
	} else if (argc==2) {
		char *argument=argv[1];
		// 	
	} else if (argc==3) {
	} else {
		cerr << "Incorrect number of arguments"<<endl;
		usage();
	}

	switch (option) {
		case Default:
			//
			//
		case LoadfromSavedfile:
			//
			//
		case LoadMap:
			//
			//
		case Bonus:
			//
			//
		case Test1:
			//
			//
		default:
			//
			//
		}
}
