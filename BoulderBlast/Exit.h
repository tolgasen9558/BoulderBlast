#pragma once
#include "actor.h"
class Exit : public Actor{

public:
	Exit(int startX, int startY, StudentWorld *world)
		: Actor(IID_EXIT, startX, startY, world) { setVisible(false); }
	//~Exit(void);

	int getType(){ return IID_EXIT; }
	void doSomething(){};
};

