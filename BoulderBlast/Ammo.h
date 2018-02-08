#ifndef AMMO_H_
#define AMMO_H_


#include "actor.h"
class Ammo : public Actor{

public:
	Ammo(int startX, int startY, StudentWorld* world)
    : Actor(IID_AMMO, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_AMMO;}
};

#endif //AMMO_H_