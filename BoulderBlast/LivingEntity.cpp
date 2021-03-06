#include "LivingEntity.h"
#include "StudentWorld.h"

bool LivingEntity::isDead(){
	return m_isdead;
}

void LivingEntity::die(){
	m_current_health = 0;
	m_isdead = true;
	setActive(false);
}

void LivingEntity::fire(Actor *actor){
	int destinationX, destinationY;
	getDestinationCoordinates(getDirection(), destinationX, destinationY);
	Bullet *bullet = new Bullet(destinationX, destinationY, getDirection(), getWorld());
	getWorld()->addActor(bullet);
	int soundID;
	switch (actor->getType())
	{
	case IID_PLAYER:
		soundID = SOUND_PLAYER_FIRE;
		break;
	case IID_SNARLBOT:
	case IID_KLEPTOBOT:
	case IID_ANGRY_KLEPTOBOT:
		soundID = SOUND_ENEMY_FIRE;
		break;
	default:
		return;
	}
	getWorld()->playSound(soundID);

}

bool LivingEntity::isPlayerInSight(Direction dir){
	int currentX = getX();
	int currentY = getY();
	int traversingX = 0;
	int traversingY = 0;

	switch (dir)
	{
	case GraphObject::up:
		traversingY = 1;
		break;
	case GraphObject::down:
		traversingY = -1;
		break;
	case GraphObject::left:
		traversingX = -1;
		break;
	case GraphObject::right:
		traversingX = 1;
		break;
	}

	int iterations = 0;
	Actor *foundActor = nullptr;

	while(iterations < VIEW_HEIGHT || iterations < VIEW_WIDTH ){
		foundActor = getWorld()->getActorAt(currentX + traversingX, currentY + traversingY);

		if(foundActor != nullptr && (foundActor->getType() == IID_WALL 
		|| foundActor->getType() == IID_KLEPTOBOT
		|| foundActor->getType() == IID_SNARLBOT
		|| foundActor->getType() == IID_BOULDER
		|| foundActor->getType() == IID_ANGRY_KLEPTOBOT
		|| foundActor->getType() == IID_ROBOT_FACTORY)){
			return false;
		}

		if(foundActor != nullptr && foundActor->getType() == IID_PLAYER){
			return true;
		}
		
		iterations++;
		if(traversingX < 0) { traversingX -= 1;}
		else if(traversingX > 0) { traversingX += 1; }
		else if(traversingY < 0) { traversingY -= 1;}
		else if(traversingY > 0) { traversingY += 1; }
	}
	std::cerr << "IsPlayerInSight Algorithm Failed" << std::endl;
	return false;
}

 void LivingEntity::takeHit(int damage){
	m_current_health -= damage;
	if(m_current_health <= 0){
  		die();
	}
}

 int LivingEntity::getHealthPercent(){
	 float percent = (float) m_current_health / m_total_health;
	 return (int) (percent * 100);
 }

 void LivingEntity::restoreToFullHealth(){
	 m_current_health = m_total_health;
 }