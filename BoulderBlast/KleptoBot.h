#pragma once
#include <vector>
#include "Goodie.h"
#include "Bot.h"
class KleptoBot : public Bot{

public:
	KleptoBot(int startX, int startY, int totalHealth, StudentWorld* world, Direction dir)
		:Bot(IID_KLEPTOBOT, startX, startY, totalHealth, world, dir)
		{m_distanceBeforeTurning = (rand() % 6) + 1; m_collectedGoodie = nullptr;}

	virtual void doSomething();
	virtual int getType(){return IID_KLEPTOBOT;}
	virtual void patrol();
	void tryToCollectGoodie();
	void die();
private:
	int m_distanceBeforeTurning;
	Goodie *m_collectedGoodie;
};

