#pragma once
#include "LivingEntity.h"

class Bot : public LivingEntity{

public:
	Bot(int imageID, int startX, int startY, int totalHealth, StudentWorld* world, Direction dir)
    :LivingEntity(imageID, startX, startY, totalHealth, world, dir), m_tickCounter(0){ setVisible(true);};
	//~Bot();

	virtual void doSomething() = 0;
	virtual void patrol() = 0;
	void takeHit(int damage);
	void die();
	bool isAllowedToAct();

private:
	int m_tickCounter;
};

