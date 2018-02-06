#ifndef WALL_H_
#define WALL_H_
#include "actor.h"

class Wall : public Actor {
public:
    Wall(int startX, int startY, StudentWorld* world)
    :Actor(IID_WALL, startX, startY, world){ setVisible(true);}
    
	void doSomething(){};
	virtual int getType(){ return IID_WALL;}
};

#endif //WALL_H_
