#ifndef GOLD_H
#define GOLD_H

#include "item.h"

class Dragon;

class Gold : public Item {
private:	
	const std::string size;
	const int amt;
public:
	Gold(char symbol, std::string type, int amt, std::string size);
	virtual ~Gold() = 0;

	int getAmt();
	std::string getSize();
	virtual Dragon* DragonExist();
	virtual void deleteDragon();
};

class NormalHoard : public Gold {
public:
	NormalHoard();
	~NormalHoard();
};

class SmallHoard : public Gold {
public:
	SmallHoard();
	~SmallHoard();
};

class MerchantHoard : public Gold{
public:
	MerchantHoard();
	~MerchantHoard();
};

class DragonHoard : public Gold{
private:
	Dragon* dragon;
public:
	DragonHoard();
	DragonHoard(Dragon* dragon);
	~DragonHoard();
	Dragon* getDragon();
	void deleteDragon();
	void setDragon(Dragon* drag);
};

#endif

