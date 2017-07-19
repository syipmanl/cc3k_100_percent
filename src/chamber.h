#ifndef __CHAMBER_H__
#define __CHAMBER_H__ 

class Chamber {
	vector<Tile *> tiles;
	
public:
	Info random_available_tile();
};

#endif
