#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <vector>
#include "oberver.h"

using std::vector;
using std::ostream;

class TextDisplay: public Observer {
	
	vector<vector<char *> theDisplay;
	
public:
	TextDisplay();
	~TextDisplay();

	void notify(Subject &whoNotified) override;
	SubscriptionType subType() const override;
	
	friend ostream &operator<<(ostream &out, const TextDisplay &td);
};

#endif
