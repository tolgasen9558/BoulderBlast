#ifndef BOULDER_H_
#define BOULDER_H_

#include "actor.h"
#include "StudentWorld.h"
class Boulder : public Actor{
public:
	Boulder(int startX, int startY, StudentWorld* world)
    :Actor(IID_BOULDER, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_BOULDER;}

	bool tryToMove(Direction dir);
};

#endif //BOULDER_H_
