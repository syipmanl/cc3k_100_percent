#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "object.h"
#include <string>
#include <cstdlib>


class Character: public Object {

protected: 
	int ATK;
	int DEF;
	int HP;
    int dif_hp;
	int dif_atk;
	int dif_def
	bool hit;
	const std::string race;

public: 
	
	Character(int ATK, int DEF, int HP, int dif_hp, int dif_atk, int dif_def, 
		std::string race, char symbol, std::string type);
	
	virtual ~Character() = 0;
	
	virtual void getHit();

	virtual int getAtk();
	
	virtual int getDef();
	
	virtual int getHP();
	
	virtual std::string getRace();

	virtual std::string getType();

	virtual Character::usePotion(string effect);

	virtual bool Damaged(int n);
	
	virtual bool Attack(Character* defender);

	virtual bool move(int index);

	virtual void regen(int n) = 0;
};

#endif 
