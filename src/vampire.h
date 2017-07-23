#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

class Vampire: public Hero {
	void attack(Enemy& enemy) override;
};

#endif