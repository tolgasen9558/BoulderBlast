#pragma once
#include "livingentity.h"
#include "Bullet.h"
class SnarlBot : public LivingEntity{

public:
	SnarlBot(int startX, int startY, int totalHealth, bool isHorizontal,
		StudentWorld* world, Direction dir)
    :LivingEntity(IID_SNARLBOT, startX, startY, totalHealth, world, dir), m_tickCounter(0){ setVisible(true);}

	void doSomething();
	virtual int getType(){return IID_SNARLBOT;}
	void patrol();
private:
	int m_tickCounter;
};

