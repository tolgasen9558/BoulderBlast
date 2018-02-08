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
		: GraphObject(imageID, startX, startY, dir), m_world(world), m_isActive(true){}
	
	virtual void doSomething() = 0;
	virtual int getType() = 0;
	StudentWorld* getWorld();

	void getDestinationCoordinates(Direction dir, int& xOut, int& yOut);
	bool tryToMove(Direction dir);
	bool isActive();
	void setActive(bool isActive);
	void inverseDirection();

private:
	StudentWorld *m_world;
	bool m_isActive;
};


#endif // ACTOR_H_
