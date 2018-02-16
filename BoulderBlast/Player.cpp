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
			getWorld()->setLevelFinished(true);
			//TODO: Release this
			//die();
			break;
		case KEY_PRESS_SPACE:
			if(getAmmo() > 0){
				fire(this);
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
					getWorld()->playSound(SOUND_GOT_GOODIE);
				}
			}
			break;
		case IID_EXIT:
			if(actorAtDestination->isVisible()){
				getWorld()->setLevelFinished(true);
				getWorld()->playSound(SOUND_FINISHED_LEVEL);
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

void Player::takeHit(int damage){
	getWorld()->playSound(SOUND_PLAYER_IMPACT);
	LivingEntity::takeHit(damage);
}

void Player::die(){
	getWorld()->playSound(SOUND_PLAYER_DIE);
	LivingEntity::die();
}