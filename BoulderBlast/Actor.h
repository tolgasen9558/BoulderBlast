#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"

class StudentWorld;
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject
{
public:
	Actor(int imageID, int startX, int startY, StudentWorld* world, Direction dir = none)
		: GraphObject(imageID, startX, startY, dir), m_world(world){}
	
	virtual void doSomething() = 0;
	virtual int getType() = 0;
	StudentWorld* getWorld();
private:
	StudentWorld *m_world;
};


#endif // ACTOR_H_
