#ifndef LIVINGENTITY_H_
#define LIVINGENTITY_H_

#include "Actor.h"

class LivingEntity : public Actor
{
public:
	LivingEntity(int imageID, int startX, int startY, int totalHealth, StudentWorld *world, Direction dir = none)
		: Actor(imageID, startX, startY, world, dir) {m_total_health = m_current_health = totalHealth; m_isdead = false;}
	//~LivingEntity();

	bool isDead();
	virtual void die();
	bool isPlayerInSight(Direction dir);	//Use the function for Bots
	void fire();
	void takeHit(int damage);
	int getHealthPercent();
private:
	int m_total_health;
	int m_current_health;
	bool m_isdead;
};



#endif //LIVINGENTITY_H_