#include "Player.h"
#include "StudentWorld.h"

void Player::doSomething(){
	if(isDead()){ return;}
	handleUserInput();
	
}

void Player::handleUserInput(){
	int pressed_key;
	if(getWorld()->getKey(pressed_key)){
		Direction finalDirection;
		switch (pressed_key)
		{
		case KEY_PRESS_RIGHT:
			finalDirection = right;
			break;
		case KEY_PRESS_LEFT:
			finalDirection = left;
			break;
		case KEY_PRESS_UP:
			finalDirection = up;
			break;
		case KEY_PRESS_DOWN:
			finalDirection = down;
			break;
		case KEY_PRESS_ESCAPE:
			//TODO: Restart 
			break;
		case KEY_PRESS_SPACE:
			//TODO: Fire!!!
			break;
		}
		tryToMove(finalDirection);
	}
}

bool Player::tryToMove(Direction dir){
	int destinationX = getX();
	int destinationY = getY();
	switch (dir)
	{
	case GraphObject::up:
		destinationY++;
		break;
	case GraphObject::down:
		destinationY--;
		break;
	case GraphObject::left:
		destinationX--;
		break;
	case GraphObject::right:
		destinationX++;
		break;
	}
	setDirection(dir);

	Actor* actorAtDestination = getWorld()->getActorAt(destinationX, destinationY);
	bool canMove = false;

	if(actorAtDestination != nullptr){
		switch (actorAtDestination->getType())
		{
		case IID_WALL:
			canMove = false;
			break;
		case IID_BOULDER:
			bool boulderMoved = actorAtDestination->tryToMove(dir);
			canMove = boulderMoved;
			break;
		}
	}
	if(canMove || actorAtDestination == nullptr){
		moveTo(destinationX, destinationY);
		return true;
	}
	return false;
}