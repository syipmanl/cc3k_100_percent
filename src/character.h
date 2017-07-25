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
	int dif_atk;
	int dif_def;
	bool hit;
	bool hostile;
	const std::string race;

public: 
	
	Character(int ATK, int DEF, int HP, int dif_atk, int dif_def, bool hit, bool hostile,
		std::string race, char symbol, std::string type);
	
	virtual ~Character() = 0;
	
	virtual bool getHostile();

	virtual bool getHit();

	virtual int getAtk();
	
	virtual int getDef();
	
	virtual int getHP();
	
	virtual std::string getRace();

	virtual std::string getType();

	virtual void usePotion(string effect, int maxHP);

	virtual bool Damaged(int n);
	
	virtual bool Attack(Character* defender);

	virtual void CharacterMove(string direction);

	virtual bool move(int index);

	// virtual void regen(int n) = 0;
};

#endif 
