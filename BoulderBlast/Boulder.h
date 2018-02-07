#pragma once
#include "actor.h"
class Boulder : public Actor{
public:
	Boulder(int startX, int startY, StudentWorld* world)
    :Actor(IID_BOULDER, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_BOULDER;}

};

