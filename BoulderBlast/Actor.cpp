#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
StudentWorld* Actor::getWorld(){
	return m_world;
}

bool Actor::isActive(){
	return m_isActive;
}

void Actor::setActive(bool isActive){
	m_isActive = isActive;
}

void Actor::getDestinationCoordinates(Direction dir, int& xOut, int& yOut){
	xOut = getX();
	yOut = getY();
	switch (dir)
	{
	case GraphObject::up:
		yOut++;
		break;
	case GraphObject::down:
		yOut--;
		break;
	case GraphObject::left:
		xOut--;
		break;
	case GraphObject::right:
		xOut++;
		break;
	}
}


bool Actor::tryToMove(Direction dir){
	int destinationX, destinationY;
	getDestinationCoordinates(dir, destinationX, destinationY);
	
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
