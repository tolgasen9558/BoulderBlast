#include "Boulder.h"

bool Boulder::tryToMove(Direction dir){
	int destinationX, destinationY;
	getDestinationCoordinates(dir, destinationX, destinationY);

	setDirection(dir);

	Actor* actorAtDestination = getWorld()->getActorAt(destinationX, destinationY);

	if(actorAtDestination == nullptr){
		moveTo(destinationX, destinationY);
		return true;
	}
	else if(actorAtDestination->getType() == IID_HOLE){
		setActive(false);
		actorAtDestination->setActive(false);
		moveTo(destinationX, destinationY);
		return true;
	}
	else{
		return false;
	}
}