#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include <string>

class DragonHoard;

class Enemy: public Character {
private:

public: 
	Enemy(int Atk, int Def, int HP, std::string race, char symbol, std::string type);
	virtual ~Enemy() = 0;
	virtual void dropGold();
};


class Human : public Enemy{
	public:
		Human();
		~Human();
		void dropGold();
};

class Dwarf : public Enemy{
	public:
		Dwarf();
		~Dwarf();
};

class Elf : public Enemy{
	public:
		Elf();
		~Elf();

};

class Orc : public Enemy{
	public:
		Orc();
		~Orc();
};

class Merchant : public Enemy{
	public:
		static bool hostile;
		Merchant();
		~Merchant();
		void dropGold();
};

class Halfling : public Enemy{
	public:
		Halfling();
		~Halfling();
};

class Dragon : public Enemy{
	private:
		DragonHoard* hoard;
	public:
		Dragon();
		Dragon(DragonHoard* hoard);
		~Dragon();
		DragonHoard* getHoard();
		void setHoard(DragonHoard* hd);
};

#endif 
