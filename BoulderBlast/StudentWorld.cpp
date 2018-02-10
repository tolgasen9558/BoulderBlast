#include "StudentWorld.h"

#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

int StudentWorld::move(){
	// This code is here merely to allow the game to build, run, and terminate after hitting enter a few times 

	//TODO: Update display text
	
	int numActors  = m_actorList.size();
	for(int i = 0; i < numActors; i++){
		m_actorList[i]->doSomething();
	}

	for (auto it = m_actorList.begin(); it != m_actorList.end(); ) {
        if ((*it)->isActive() == false) {
            delete *it;
            it = m_actorList.erase(it);
        }
        else{
            it++;
		}
    }


	//decLives();
	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::loadLevel(int levelNum){
	m_currentLevelNum = levelNum;
	//TODO: fix level num
	string levelFileName = "level00.dat";
	Level level(assetDirectory());
	Level::LoadResult result = level.loadLevel(levelFileName);

	if(result == Level::load_fail_file_not_found || result == Level::load_fail_bad_format){
		cerr << "Couldn't load the file";
		return -1;
	}
	

	for(int row = 0; row < VIEW_HEIGHT; row++){
		for(int col = 0; col < VIEW_WIDTH; col++){
			switch (level.getContentsOf(col,row))
			{
			case Level::player:
				m_actorList.push_back(new Player(col, row, 100, this, GraphObject::right));
				break;
			case Level::hole:
				m_actorList.push_back(new Hole(col, row, this));
				break;
			case Level::wall:
				m_actorList.push_back(new Wall(col, row, this));
				break;
			case Level::boulder:
				m_actorList.push_back(new Boulder(col, row, 10, this));
				break;
			case Level::jewel:
				m_actorList.push_back(new Jewel(col, row, this));
				break;
			case Level::ammo:
				m_actorList.push_back(new Ammo(col, row, this));
				break;
			case Level::extra_life:
				m_actorList.push_back(new ExtraLife(col, row, this));
				break;
			case Level::restore_health:
				m_actorList.push_back(new RestoreHealth(col, row, this));
				break;
			case Level::vert_snarlbot:
				m_actorList.push_back(new SnarlBot(col, row, 10, this, GraphObject::down));
				break;
			case Level::horiz_snarlbot:
				m_actorList.push_back(new SnarlBot(col, row, 10, this, GraphObject::right));
				break;
			}
		}
	}
	m_actorList.push_back(new KleptoBot(1, 1, 5, this, GraphObject::right));
	return 0;
}

Actor* StudentWorld::getActorAt(int posX, int posY){
	for(Actor* actor : m_actorList){
		if(actor->getX() == posX && actor->getY() == posY){
			return actor;
		}
	}
	return nullptr;
}

int StudentWorld::getCurrentLevelNum(){
	return m_currentLevelNum;
}

void StudentWorld::addActor(Actor *actor){
	m_actorList.push_back(actor);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
