#include "KleptoBot.h"
#include "StudentWorld.h"

void KleptoBot::doSomething(){
	//Do not do anything if shot dead already
	if(isDead() || !isAllowedToAct()){return;}

	patrol();
}

void KleptoBot::patrol(){
	tryToCollectGoodie();

	int destinationX, destinationY;
	getDestinationCoordinates(getDirection(), destinationX, destinationY);
	Actor *foundActor = getWorld()->getActorAt(destinationX, destinationY);

	//If have an obstacle in front, turn back
	if(foundActor != nullptr && (foundActor->getType() == IID_WALL
		|| foundActor->getType() == IID_BOULDER
		|| foundActor->getType() == IID_HOLE
		|| foundActor->getType() == IID_KLEPTOBOT
		|| foundActor->getType() == IID_SNARLBOT
		|| foundActor->getType() == IID_ANGRY_KLEPTOBOT
		|| foundActor->getType() == IID_ROBOT_FACTORY)){
			inverseDirection();
	}
	else{
		moveTo(destinationX, destinationY);
	}
}

void KleptoBot::tryToCollectGoodie(){
	//If standing on a goodie
	Goodie *goodie =  dynamic_cast<Goodie*>(getWorld()->getActorAt(getX(), getY()));
	if(m_collectedGoodie == nullptr && goodie != nullptr && goodie->isCollectable()){
		//Has %10 chance to collect goodie
		if(rand() % 100 + 1 > 10){
			return;
		}
		m_collectedGoodie = goodie;
		goodie->setCollectable(false);
		goodie->setVisible(false);
	}
}

void KleptoBot::die(){
	m_collectedGoodie->setPosition(getX(), getY());
	LivingEntity::die();
	m_collectedGoodie->setCollectable(true);
	m_collectedGoodie->setVisible(true);
}


