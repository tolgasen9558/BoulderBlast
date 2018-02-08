#ifndef EXTRALIFE_H_
#define EXTRALIFE_H_
#include "actor.h"
class ExtraLife : public Actor{

public:
	ExtraLife(int startX, int startY, StudentWorld* world)
		: Actor(IID_EXTRA_LIFE, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_EXTRA_LIFE;}

};

#endif //EXTRALIFE_H_