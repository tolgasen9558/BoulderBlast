#include "LivingEntity.h"
#include "StudentWorld.h"

bool LivingEntity::isDead(){
	return m_isdead;
}

void LivingEntity:: die(){
	m_current_health = 0;
	m_isdead = true;
}

void LivingEntity::fire(){
	int destinationX, destinationY;
	getDestinationCoordinates(getDirection(), destinationX, destinationY);
	Bullet *bullet = new Bullet(destinationX, destinationY, getDirection(), getWorld());
	getWorld()->addActor(bullet);
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


