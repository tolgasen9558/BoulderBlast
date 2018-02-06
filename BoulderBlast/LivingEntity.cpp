#include "LivingEntity.h"
#include "StudentWorld.h"

bool LivingEntity::isDead(){
	return m_isdead;
}

void LivingEntity:: die(){
	m_current_health = 0;
	m_isdead = true;
}

void LivingEntity::tryToMove(Direction dir){
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
	setDirection(dir);

	Actor* actorAtDestination = getWorld()->getActorAt(destinationX, destinationY);
	if(actorAtDestination != nullptr){
		switch (actorAtDestination->getType())
		{
		case IID_WALL:
			return;
		}
	}
	moveTo(destinationX, destinationY);
}