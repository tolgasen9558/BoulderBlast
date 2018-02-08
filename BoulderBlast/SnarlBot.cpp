#include "SnarlBot.h"
#include "StudentWorld.h"

void SnarlBot::doSomething(){
	//Do not do anything if shot dead already
	if(isDead()){return;}

	int currentLevelNum = getWorld()->getCurrentLevelNum();
	int movementPeriod = (28 - currentLevelNum) / 4;
	if(movementPeriod < 3){movementPeriod = 3;}

	//Rest
	if(m_tickCounter < movementPeriod){
		m_tickCounter++;
		return;
	}

	//Act
	m_tickCounter = 0;
	if(isPlayerInSight(getDirection())){
		fire();
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