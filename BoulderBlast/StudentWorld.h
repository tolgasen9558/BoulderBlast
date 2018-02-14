#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include "Actor.h"
#include "Wall.h"
#include "Player.h"
#include "Boulder.h"
#include "Hole.h"
#include "Goodie.h"
#include "SnarlBot.h"
#include "Bullet.h"
#include "KleptoBot.h"
#include "KleptoBotFactory.h"
#include "Exit.h"

#include <vector>
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:

	StudentWorld(std::string assetDir) : GameWorld(assetDir){m_totalJewels = m_collectedJewels = 0;}

	virtual int init(){
		loadLevel(0);
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move();

	virtual void cleanUp(){}

	void addActor(Actor* actor);
	Actor* getActorAt(int posX, int posY);
	bool isThereKleptoBotAt(int posX, int posY);
	int getCurrentLevelNum();
	void increaseCollectedJewels();
	void increaseTotalJewels();
private:
	std::vector<Actor*> m_actorList;
	int m_currentLevelNum;
	int loadLevel(int levelNum);
	int m_totalJewels;
	int m_collectedJewels;
	Exit* m_exit;
};

#endif // STUDENTWORLD_H_
