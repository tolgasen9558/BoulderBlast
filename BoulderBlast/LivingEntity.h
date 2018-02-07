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
	void die();

private:
	int m_total_health;
	int m_current_health;
	bool m_isdead;
};



#endif //LIVINGENTITY_H_