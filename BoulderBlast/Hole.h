#ifndef HOLE_H_
#define HOLE_H_
#include "actor.h"
class Hole : public Actor{

public:
	Hole(int startX, int startY, StudentWorld* world)
    : Actor(IID_HOLE, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_HOLE;}

};

#endif //HOLE_H_