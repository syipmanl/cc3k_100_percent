#ifndef _HERO_H
#define _HERO_H

#include "character.h"
#include <string>


class Hero: public Character {
protected: 
	const int maxHP;
	const int ATK;
	const int DEF;
	int dif_hp;
	int dif_atk;
	int dif_def;
	int real_hp; 
	int real_atk; 
	int real_def; 
	int gold;

public: 
	
	// Hero constructor
	Hero(int maxHP, int ATK, int DEF, int gold, 
		int dif_hp, int dif_atk, int dif_def, 
		int real_hp, int real_atk, int real_def, 
		char symbol, std::string type, std::string race);
	
	// pure virtual to make abstract
	virtual ~Hero() = 0;
	
	// return maxHP
	virtual int getmaxHP();

	// return gold
	virtual int getGold();

	// add n gold
	virtual void addGold(int g);
	
	/**
	 *	heal Hero n amount of HP
	 *	HP can't exceed MAX_HP
	 */
	virtual void regen(int hp);


    virtual Hero* getHero();
};
// Shade: 120 HP, 25 Atk, 25 Def
class Shade : public Hero{
	public:
		Shade();
		~Shade();
};

// Drow: 150 HP, 25 Atk, 15 Def, magnified potion effect by 1.5
class Drow : public Hero{
	public:
		Drow();
		~Drow();
};

// Vamprie: 50 HP, 25 Atk, 25 Def, heal 5 HP every successful attack and no MAX_HP
class Vampire : public Hero{
	public:
		Vampire();
		~Vampire();
		void heal(int n) override;
};

// Troll: 120 HP, 25 Atk, 15 Def, regain 5 HP every turn
class Troll : public Hero{
	public:
		Troll();
		~Troll();
};

// Goblin: 110 HP, 15 Atk, 20 Def, get 5 gold every kill
class Goblin : public Hero{
	public:
		Goblin();
		~Goblin();
};


#endif //_HERO_H

