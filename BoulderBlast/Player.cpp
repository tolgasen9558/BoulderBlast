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
			fire();
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
		{
			canMove = true;
			actorAtDestination->setActive(false);
			//TODO:Increase Score
			std::cout << "Jewel gained, increase score" << std::endl;
		}
		break;
		case IID_EXTRA_LIFE:
		{
			canMove = true;
			actorAtDestination->setActive(false);
			//TODO:Add one life Score
			std::cout << "Extra Life gained,  add one life" << std::endl;
		}
		break;
		case IID_AMMO:
		{
			canMove = true;
			actorAtDestination->setActive(false);
			//TODO:Add ammo
			std::cout << "Ammo gained,  add ammo" << std::endl;
		}
		break;
		case IID_RESTORE_HEALTH:
		{
			canMove = true;
			actorAtDestination->setActive(false);
			//TODO:Restore Health
			std::cout << "Restore Health" << std::endl;
		}
		break;
		}
	}
	if(canMove || actorAtDestination == nullptr){
		moveTo(destinationX, destinationY);
		return true;
	}
	return false;
}