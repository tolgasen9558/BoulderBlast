#include "KleptoBotFactory.h"
#include "StudentWorld.h"

void KleptoBotFactory::doSomething(){
	produceKleptoBot();
}

void KleptoBotFactory::produceKleptoBot(){
	Actor *actorAtThisSquare = getWorld()->getActorAt(getX(), getY());
	if(getWorld()->isThereKleptoBotAt(getX(), getY())){
			return;
	}
	if(checkBotsNearbyLessThan(3) && (rand() % 100) < 2){
		int health = m_isProducingAngryBots ? 8 : 5;
		KleptoBot *kleptoBot = new KleptoBot(getX(), getY(), health, m_isProducingAngryBots, getWorld(), right);
		getWorld()->addActor(kleptoBot);
	}
}

bool KleptoBotFactory::checkBotsNearbyLessThan(int count){
	int counter = 0;
	for(int i = -3; i < 4; i++){
		for(int j = -3; j < 4; j++){
			int toCheckX = getX() + i;
			int toCheckY = getY() + j;
			//Respect to the bounds
			if(toCheckX >= 0 && toCheckX < VIEW_WIDTH 
				&& toCheckY >= 0 && toCheckY < VIEW_HEIGHT){
					Actor *actor = getWorld()->getActorAt(toCheckX, toCheckY);
				if(actor != nullptr &&
					(actor->getType() == IID_KLEPTOBOT || actor->getType() == IID_ANGRY_KLEPTOBOT)){
						counter++;
						if(counter >= count){
							return false;
						}
				}
			}
		}
	}
	return true;
}
