#include "Goodie.h"
#include "StudentWorld.h"

bool Goodie::isCollectable(){
	return m_isCollectable;
}

void Goodie::setCollectable(bool isCollectable){
	m_isCollectable = isCollectable;
}

void Ammo::applyEffect(){
	//TODO:Implement the effect
	getWorld()->getPlayer()->increaseAmmo(10);
}

void Jewel::applyEffect(){
	//TODO:Implement the effect
	getWorld()->increaseCollectedJewels();
}

void RestoreHealth::applyEffect(){
	//TODO:Implement the effect
	std::cout << "RestoreHealth taken, apply effect" << std::endl;
}

void ExtraLife::applyEffect(){
	//TODO:Implement the effect
	std::cout << "ExtraLife taken, apply effect" << std::endl;
}
