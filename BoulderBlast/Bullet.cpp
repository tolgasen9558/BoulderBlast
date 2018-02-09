#include "Bullet.h"


void Bullet::doSomething(){
	handleCollision();
	int coordX, coordY;
	getDestinationCoordinates(getDirection(), coordX, coordY);
	moveTo(coordX, coordY);
	handleCollision();
}

void Bullet::handleCollision(){
	if(isActive() == false){ return;}

	Actor *target = getWorld()->getActorAt(getX(), getY());
	switch (target->getType())
	{
	case IID_PLAYER:
	case IID_BOULDER:
	case IID_SNARLBOT:
		((LivingEntity*) target)->takeHit(2);
		setActive(false);
		break;
	case IID_WALL:
	case IID_ROBOT_FACTORY:
		setActive(false);
	}
}