#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <vector>
#include <string>
#include "tile.h"

using std::vector;
using std::string;
using std::ostream;

class Tile;
class TextDisplay{
	
	vector<string> tdDisplay;
	
public:
	TextDisplay(); // no use for now
	~TextDisplay(); // no use for now
    vector<string> * getDisplay();
    void addrow(const string line);
	void notify(Tile &whoNotified) override;
	
	friend ostream &operator<<(ostream &out, const TextDisplay &td);
  //  friend Floor::Floor(int floor_num, TextDisplay *tp);
};

#endif
