#include "Goodie.h"
#include "StudentWorld.h"

bool Goodie::isCollectable(){
	return m_isCollectable;
}

void Goodie::setCollectable(bool isCollectable){
	m_isCollectable = isCollectable;
}

void Ammo::applyEffect(){
	getWorld()->increaseScore(BONUS_POINTS_AMMO);
	getWorld()->getPlayer()->increaseAmmo(20);
}

void Jewel::applyEffect(){
	getWorld()->increaseScore(BONUS_POINTS_JEWEL);
	getWorld()->increaseCollectedJewels();
}

void RestoreHealth::applyEffect(){
	getWorld()->increaseScore(BONUS_POINTS_RESTORE_HEALTH);
	getWorld()->getPlayer()->restoreToFullHealth();
}

void ExtraLife::applyEffect(){
	getWorld()->increaseScore(BONUS_POINTS_EXTRA_LIFE);
	getWorld()->incLives();
}
