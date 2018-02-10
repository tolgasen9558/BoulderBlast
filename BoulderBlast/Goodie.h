#pragma once
#include "actor.h"

class Goodie : public Actor{
public:
	Goodie(int imageID, int startX, int startY, StudentWorld* world)
		: Actor(imageID, startX, startY, world){ setVisible(true); setCollectable(true);}

	virtual void applyEffect() = 0;
	void doSomething(){};
	bool isCollectable();
	void setCollectable(bool isCollectable);

private:
	bool m_isCollectable;
};

class Ammo : public Goodie{
public:
	Ammo(int startX, int startY, StudentWorld* world)
    : Goodie(IID_AMMO, startX, startY, world){}
    
	void applyEffect();
	virtual int getType(){ return IID_AMMO;}
};

class ExtraLife : public Goodie{
public:
	ExtraLife(int startX, int startY, StudentWorld* world)
		: Goodie(IID_EXTRA_LIFE, startX, startY, world){}
    
	void applyEffect();
	virtual int getType(){ return IID_EXTRA_LIFE;}
};

class Jewel : public Goodie{
public:
	Jewel(int startX, int startY, StudentWorld* world)
    : Goodie(IID_JEWEL, startX, startY, world){}
    
	void applyEffect();
	virtual int getType(){ return IID_JEWEL;}

};

class RestoreHealth : public Goodie{
public:
	RestoreHealth(int startX, int startY, StudentWorld* world)
		: Goodie(IID_RESTORE_HEALTH, startX, startY, world){}
    
	void applyEffect();
	virtual int getType(){ return IID_RESTORE_HEALTH;}

};
