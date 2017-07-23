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
	const std::string race;

public: 
	
	Character(int Atk, int Def, int HP, std::string race, char symbol, std::string type);
	
	virtual ~Character() = 0;
	
	virtual void setAtk(int n);
	
	virtual void setDef(int n);

	virtual void setHP(int n);
	
	virtual int getAtk();
	
	virtual int getDef();
	
	virtual int getHP();
	
	virtual std::string getRace();

	virtual std::string move(int d);

	virtual void takeDamage(int n);
	
	virtual std::string Damage(Character* defender);

	virtual void heal(int n);
};

#endif //_CHARACTER_H
