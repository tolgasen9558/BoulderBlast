#include "Player.h"
#include "StudentWorld.h"

void Player::doSomething(){
	if(isDead()){ return;}
	handleUserInput();
	
}

void Player::handleUserInput(){
	int pressed_key;
	if(getWorld()->getKey(pressed_key)){
		switch (pressed_key)
		{
		case KEY_PRESS_RIGHT:
			tryToMove(right);
			break;
		case KEY_PRESS_LEFT:
			tryToMove(left);
			break;
		case KEY_PRESS_UP:
			tryToMove(up);
			break;
		case KEY_PRESS_DOWN:
			tryToMove(down);
			break;
		case KEY_PRESS_ESCAPE:
			//TODO: Restart 
			break;
		case KEY_PRESS_SPACE:
			if(getAmmo() > 0){
				fire();
				decreaseAmmo(1);
			}
			break;
		}
	}
}

bool Player::tryToMove(Direction dir){
	int destinationX, destinationY;
	getDestinationCoordinates(dir, destinationX, destinationY);

	setDirection(dir);

	Actor* actorAtDestination = getWorld()->getActorAt(destinationX, destinationY);
	bool canMove = false;

	if(actorAtDestination != nullptr){
		switch (actorAtDestination->getType())
		{
		case IID_WALL:
		case IID_HOLE:
		case IID_SNARLBOT:
			canMove = false;
			break;
		case IID_BOULDER:
			{
				bool boulderMoved = ((Boulder*) actorAtDestination)->tryToMove(dir);
				canMove = boulderMoved;
			}
			break;
		case IID_JEWEL:
		case IID_EXTRA_LIFE:
		case IID_AMMO:
		case IID_RESTORE_HEALTH:
			{
				canMove = true;
				Goodie *goodie = (Goodie*) actorAtDestination;
				if(goodie->isCollectable()){
					goodie->applyEffect();
					goodie->setCollectable(false);
					goodie->setActive(false);
				}
			}
			break;
		case IID_EXIT:
			if(actorAtDestination->isVisible()){
				std::cout << "Level Finished" << std::endl;
			}
			canMove = true;
			break;
		}

	}
	if(canMove || actorAtDestination == nullptr){
		moveTo(destinationX, destinationY);
		return true;
	}
	return false;
}

void Player::increaseAmmo(int amount){
	m_ammo += amount;
}

void Player::decreaseAmmo(int amount){
	m_ammo -= amount;
}

int Player::getAmmo(){
	return m_ammo;
}