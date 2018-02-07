#include "Boulder.h"

bool Boulder::tryToMove(Direction dir){
	int destinationX, destinationY;
	getDestinationCoordinates(dir, destinationX, destinationY);

	setDirection(dir);

	Actor* actorAtDestination = getWorld()->getActorAt(destinationX, destinationY);
	bool canMove = false;

	if(actorAtDestination != nullptr){
		switch (actorAtDestination->getType())
		{
		case IID_WALL:
			canMove = false;
			break;
		case IID_HOLE:
			canMove = true;
			setActive(false);
			actorAtDestination->setActive(false);
			break;
		case IID_BOULDER:
			bool boulderMoved = actorAtDestination->tryToMove(dir);
			canMove = boulderMoved;
			break;
		}
	}
	if(canMove || actorAtDestination == nullptr){
		moveTo(destinationX, destinationY);
		return true;
	}
	return false;
}