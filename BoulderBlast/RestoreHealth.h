#ifndef RESTORE_HEALTH_
#define RESTORE_HEALTH_
#include "actor.h"

class RestoreHealth : public Actor{

public:
	RestoreHealth(int startX, int startY, StudentWorld* world)
		: Actor(IID_RESTORE_HEALTH, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_RESTORE_HEALTH;}

};

#endif //EXTRALIFE_H_