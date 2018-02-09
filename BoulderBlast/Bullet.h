#pragma once
#include "Actor.h"
#include "StudentWorld.h"
class Bullet : public Actor{

public:
	Bullet(int startX, int startY, Direction dir, StudentWorld* world)
    : Actor(IID_BULLET, startX, startY, world)
	{ setVisible(true); setDirection(dir);}
    
	virtual int getType(){ return IID_BULLET;}
	void doSomething();
	void handleCollision();
};
