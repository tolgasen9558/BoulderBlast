#include "LivingEntity.h"
#include "StudentWorld.h"

bool LivingEntity::isDead(){
	return m_isdead;
}

void LivingEntity:: die(){
	m_current_health = 0;
	m_isdead = true;
}

