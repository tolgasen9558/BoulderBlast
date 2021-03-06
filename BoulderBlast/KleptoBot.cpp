#include "KleptoBot.h"
#include "StudentWorld.h"

void KleptoBot::doSomething(){
	//Do not do anything if shot dead already
	if(isDead() || !isAllowedToAct()){return;}

	if(m_isAngry && isPlayerInSight(getDirection())){
		fire(this);
		return;
	}
	patrol();
}


void KleptoBot::patrol(){
	tryToCollectGoodie();

	int destinationX, destinationY;
	getDestinationCoordinates(getDirection(), destinationX, destinationY);
	Actor *foundActor = getWorld()->getActorAt(destinationX, destinationY);

	bool isGoodie = ((Goodie*) foundActor) != nullptr;

	//If its time to turn or faced with an obstacle
	if(m_distanceBeforeTurning <= 0 || foundActor != nullptr && 
		(foundActor->getType() == IID_WALL
		|| foundActor->getType() == IID_BOULDER
		|| foundActor->getType() == IID_HOLE
		|| foundActor->getType() == IID_KLEPTOBOT
		|| foundActor->getType() == IID_SNARLBOT
		|| foundActor->getType() == IID_ANGRY_KLEPTOBOT
		|| foundActor->getType() == IID_ROBOT_FACTORY
		|| (isGoodie && m_collectedGoodie != nullptr))){

			m_distanceBeforeTurning = (rand() % 6) + 1;
			changeDirectionRandomly();
	}
	else{
		moveTo(destinationX, destinationY);
		m_distanceBeforeTurning--;
	}
}

void KleptoBot::changeDirectionRandomly(){
	std::vector<Direction> directionsToTry;
	directionsToTry.push_back(up);
	directionsToTry.push_back(down);
	directionsToTry.push_back(left);
	directionsToTry.push_back(right);

	int destinationX, destinationY;
	Direction firstTrial = directionsToTry[rand() % directionsToTry.size()];
	
	while(!directionsToTry.empty()){
		int random = rand() % directionsToTry.size();

		getDestinationCoordinates(directionsToTry[random], destinationX, destinationY);
		Actor *foundActor = getWorld()->getActorAt(destinationX, destinationY);

		if(foundActor != nullptr && (foundActor->getType() == IID_WALL
		|| foundActor->getType() == IID_BOULDER
		|| foundActor->getType() == IID_HOLE
		|| foundActor->getType() == IID_KLEPTOBOT
		|| foundActor->getType() == IID_SNARLBOT
		|| foundActor->getType() == IID_ANGRY_KLEPTOBOT
		|| foundActor->getType() == IID_ROBOT_FACTORY)){
			directionsToTry.erase(directionsToTry.begin() + random);
		}
		else{
			setDirection(directionsToTry[random]);
			moveTo(destinationX, destinationY);
			return;
		}
	}
	setDirection(firstTrial);
}


void KleptoBot::tryToCollectGoodie(){
	//If standing on a goodie
	Goodie *goodie =  dynamic_cast<Goodie*>(getWorld()->getActorAt(getX(), getY()));
	if(m_collectedGoodie == nullptr && goodie != nullptr && goodie->isCollectable()){
		////Has %10 chance to collect goodie
		if(rand() % 100 + 1 > 10){
			return;
		}
		m_collectedGoodie = goodie;
		goodie->setCollectable(false);
		goodie->setVisible(false);
		getWorld()->playSound(SOUND_ROBOT_MUNCH);
	}
}

void KleptoBot::die(){
	if(m_isAngry){ getWorld()->increaseScore(BONUS_POINTS_ANGRY_KLEPTOBOT); }
	else { getWorld()->increaseScore(BONUS_POINTS_KLEPTOBOT); }

	if(m_collectedGoodie != nullptr){
		m_collectedGoodie->setPosition(getX(), getY());
		m_collectedGoodie->setCollectable(true);
		m_collectedGoodie->setVisible(true);
	}
	
	Bot::die();
}


