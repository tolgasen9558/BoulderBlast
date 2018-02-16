#ifndef PLAYER_H_
#define PLAYER_H_
#include "LivingEntity.h"
class StudentWorld;
class Player :public LivingEntity{

public:
	//~Player(void);

	Player(int startX, int startY, int totalHealth, StudentWorld* world, Direction dir)
    :LivingEntity(IID_PLAYER, startX, startY, totalHealth, world, dir){ setVisible(true); m_ammo = 20;}
    
	void doSomething();
	void handleUserInput();
	bool tryToMove(Direction dir);

	virtual int getType(){return IID_PLAYER;}
	void increaseAmmo(int amount);
	void decreaseAmmo(int amount);
	int getAmmo();

private:
	int m_ammo;
};

#endif //PLAYER_H_
