#pragma once
#include "Bullet.h"
#include "Bot.h"

class SnarlBot : public Bot{

public:
	SnarlBot(int startX, int startY, int totalHealth, StudentWorld* world, Direction dir)
    :Bot(IID_SNARLBOT, startX, startY, totalHealth, world, dir){}

	virtual void doSomething();
	virtual void patrol();
	virtual int getType(){return IID_SNARLBOT;}
private:
};

