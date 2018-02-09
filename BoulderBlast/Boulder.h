#ifndef BOULDER_H_
#define BOULDER_H_

#include "actor.h"
#include "StudentWorld.h"
class Boulder : public LivingEntity{
public:
	Boulder(int startX, int startY, int totalHealth, StudentWorld* world)
    :LivingEntity(IID_BOULDER, startX, startY, totalHealth, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_BOULDER;}

	bool tryToMove(Direction dir);
	
};

#endif //BOULDER_H_
