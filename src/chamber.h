#ifndef __CHAMBER_H__
#define __CHAMBER_H__ 

class Chamber {
	vector<Tile *> tiles;
	
public:
    bool attachUniqueTile(Tile *);
	Info random_available_tile();
    void addTile(Tile *);
};

#endif
