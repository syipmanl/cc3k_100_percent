#ifndef _HERO_H
#define _HERO_H

#include "character.h"
#include <string>


class Hero: public Character {
protected: 
	const int maxHP;
	// const int ATK;
	// const int DEF;
	// int dif_atk;
	// int dif_def;
<<<<<<< HEAD
	// int real_atk; 
	// int real_def; 
=======
     int real_hp;
	 int real_atk; 
	 int real_def; 
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903
	int gold;

public: 
	
	// Hero constructor


	Hero(int maxHP, int ATK, int DEF, int gold, 
		int dif_atk, int dif_def, 
		int real_hp, int real_atk, int real_def, 
		char symbol, std::string type, std::string race);

	// pure virtual to make abstract
	virtual ~Hero() = 0;
	
<<<<<<< HEAD
=======
    void HeroMove(string direction);
    
>>>>>>> 8822aae6eb73b02e660eb9b51763cc62be58b903
	virtual int getmaxHP();
    
    virtual int getATK();
    
    virtual int getDEF();

	virtual int getGold();

	virtual void addGold(int g);

    virtual Hero* getHero();
};

class Shade : public Hero{
	public:
		Shade();
		~Shade();
};

class Drow : public Hero{
	public:
		Drow();
		~Drow();
};

class Vampire : public Hero{
	public:
		Vampire();
		~Vampire();
		void regen(int hp) ;
};

class Troll : public Hero{
	public:
		Troll();
		~Troll();
};

class Goblin : public Hero{
	public:
		Goblin();
		~Goblin();
};


#endif //_HERO_H

