#include "Bot.h"
#include "StudentWorld.h"


bool Bot::isAllowedToAct(){
	int currentLevelNum = getWorld()->getLevel();
	int movementPeriod = (28 - currentLevelNum) / 4;
	if(movementPeriod < 3){movementPeriod = 3;}

	//Rest
	if(m_tickCounter < movementPeriod){
		m_tickCounter++;
		return false;
	}
	m_tickCounter = 0;
	return true;
}

void Bot::takeHit(int damage){
	getWorld()->playSound(SOUND_ROBOT_IMPACT);
	LivingEntity::takeHit(damage);
}

void Bot::die(){
	getWorld()->playSound(SOUND_ROBOT_DIE);
	LivingEntity::die();
}