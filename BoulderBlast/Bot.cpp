#include "Bot.h"
#include "StudentWorld.h"


bool Bot::isAllowedToAct(){
	int currentLevelNum = getWorld()->getCurrentLevelNum();
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