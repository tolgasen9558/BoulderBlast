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
	if(getWorld()->countKleptoBots(getX(), getY(), 3) < 3 && (rand() % 100) < 2){
		int health = m_isProducingAngryBots ? 8 : 5;
		KleptoBot *kleptoBot = new KleptoBot(getX(), getY(), health, m_isProducingAngryBots, getWorld(), right);
		getWorld()->addActor(kleptoBot);
		getWorld()->playSound(SOUND_ROBOT_BORN);
	}
}
