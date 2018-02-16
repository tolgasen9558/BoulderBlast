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
#include <iomanip>
#include <sstream>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:

	StudentWorld(std::string assetDir) : GameWorld(assetDir){m_totalJewels = m_collectedJewels = 0;
	m_currentBonus = 1000; m_levelFinished = false;}

	virtual int init(){
		loadLevel();
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move();

	virtual void cleanUp();

	void addActor(Actor* actor);
	Actor* getActorAt(int posX, int posY);
	bool isThereKleptoBotAt(int posX, int posY);
	void increaseCollectedJewels();
	void increaseTotalJewels();
	int loadLevel();
	Player *getPlayer();
	void setPlayer(Player* player);
	void setDisplayText();
	std::string formatStatsText(long score, int level, int lives, int health, int ammo, int bonus);
	bool isLevelFinished();
	void setLevelFinished(bool isFinished);

private:
	std::vector<Actor*> m_actorList;
	Player *m_player;
	int m_totalJewels;
	int m_collectedJewels;
	int m_currentBonus;
	bool m_levelFinished;

	Exit* m_exit;
};

#endif // STUDENTWORLD_H_
