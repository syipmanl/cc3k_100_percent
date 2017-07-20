#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <vector>
#include <string>
#include "observer.h"

using std::vector;
using std::string;
using std::ostream;

class TextDisplay: public Observer {
	
	vector<string> tdDisplay;
	
public:
	TextDisplay(); // no use for now
	~TextDisplay(); // no use for now
    vector<string> * getDisplay();
    void addrow(const string line);
	void notify(Subject &  whoNotified) override;
	SubscriptionType subType() const override;
	
	friend ostream &operator<<(ostream &out, const TextDisplay &td);
  //  friend Floor::Floor(int floor_num, TextDisplay *tp);
};

#endif
