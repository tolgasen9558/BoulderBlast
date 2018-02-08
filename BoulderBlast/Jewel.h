#ifndef JEWEL_H_
#define JEWEL_H_

#include "actor.h"

class Jewel : public Actor{

public:
	Jewel(int startX, int startY, StudentWorld* world)
    : Actor(IID_JEWEL, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_JEWEL;}

};

#endif //JEWEL_H_
