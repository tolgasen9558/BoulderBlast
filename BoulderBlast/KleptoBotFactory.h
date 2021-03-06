#pragma once
#include "actor.h"
class KleptoBotFactory : public Actor{
public:
	KleptoBotFactory(int startX, int startY, bool isProducingAngryBots, StudentWorld *world)
		: Actor(IID_ROBOT_FACTORY, startX, startY, world) { setVisible(true);
	m_isProducingAngryBots = isProducingAngryBots; }
	//~KleptoBotFactory(void);

	int getType(){ return IID_ROBOT_FACTORY; }
	void doSomething();
	void produceKleptoBot();

private:
	bool m_isProducingAngryBots;
};

