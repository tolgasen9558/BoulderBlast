#pragma once
#include <vector>
#include "Goodie.h"
#include "Bot.h"
class KleptoBot : public Bot{

public:
	KleptoBot(int startX, int startY, int totalHealth, bool isAngry, StudentWorld* world, Direction dir)
		:Bot((isAngry ? IID_ANGRY_KLEPTOBOT : IID_KLEPTOBOT), startX, startY, totalHealth, world, dir)
		{m_distanceBeforeTurning = (rand() % 6) + 1; m_collectedGoodie = nullptr; m_isAngry = isAngry; }

	virtual void doSomething();
	virtual int getType(){return (m_isAngry ? IID_ANGRY_KLEPTOBOT : IID_KLEPTOBOT);}
	virtual void patrol();
	void tryToCollectGoodie();
	void die();
	void changeDirectionRandomly();
private:
	int m_distanceBeforeTurning;
	bool m_isAngry;
	Goodie *m_collectedGoodie;
};

