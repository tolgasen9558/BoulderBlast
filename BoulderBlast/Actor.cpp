#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
StudentWorld* Actor::getWorld(){
	return m_world;
}

bool Actor::tryToMove(Direction dir){
	int destinationX = getX();
	int destinationY = getY();
	switch (dir)
	{
	case GraphObject::up:
		destinationY++;
		break;
	case GraphObject::down:
		destinationY--;
		break;
	case GraphObject::left:
		destinationX--;
		break;
	case GraphObject::right:
		destinationX++;
		break;
	}

	Actor* actorAtDestination = getWorld()->getActorAt(destinationX, destinationY);
	if(actorAtDestination != nullptr){
		switch (actorAtDestination->getType())
		{
		case IID_WALL:
		case IID_BOULDER:
			return false;
		}
	}
	setDirection(dir);
	moveTo(destinationX, destinationY);
	return true;
}
