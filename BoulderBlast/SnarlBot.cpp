#include "SnarlBot.h"
#include "StudentWorld.h"

void SnarlBot::doSomething(){
	//Do not do anything if shot dead already
	if(isDead() || !isAllowedToAct()){return;}

	//Act
	if(isPlayerInSight(getDirection())){
		fire(this);
	}
	else{
		patrol();
	}
}

void SnarlBot::patrol(){
	int destinationX, destinationY;
	getDestinationCoordinates(getDirection(), destinationX, destinationY);
	Actor *foundActor = getWorld()->getActorAt(destinationX, destinationY);

	//If have an obstacle in front, turn back
	if(foundActor != nullptr && (foundActor->getType() == IID_WALL 
		|| foundActor->getType() == IID_HOLE
		|| foundActor->getType() == IID_KLEPTOBOT
		|| foundActor->getType() == IID_SNARLBOT
		|| foundActor->getType() == IID_BOULDER
		|| foundActor->getType() == IID_ANGRY_KLEPTOBOT
		|| foundActor->getType() == IID_ROBOT_FACTORY)){
			inverseDirection();
	}
	else{
		moveTo(destinationX, destinationY);
	}
}

void SnarlBot::die(){
	getWorld()->increaseScore(BONUS_POINTS_SNARLBOT);
	Bot::die();
}