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
				increaseTotalJewels();
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
			case Level::kleptobot_factory:
				m_actorList.push_back(new KleptoBotFactory(col, row, false, this));
				break;
			case Level::angry_kleptobot_factory:
				m_actorList.push_back(new KleptoBotFactory(col, row, true, this));
				break;
			case Level::exit:
				Exit *exit = new Exit(col, row, this);
				m_actorList.push_back(exit);
				m_exit = exit;
				break;
			}
		}
	}
	return 0;
}

Actor* StudentWorld::getActorAt(int posX, int posY){
	Actor *actor1 = nullptr;
	Actor *actor2 = nullptr;
	for(Actor* actor : m_actorList){
		if(actor->getX() == posX && actor->getY() == posY){
			if(actor1 == nullptr){
				actor1 = actor;
			}
			else {
				actor2 = actor;
				break;
			}
		}
	}
	if(actor1 == nullptr){
		return nullptr;
	}
	if(actor2 == nullptr){
		return actor1;
	}
	switch (actor1->getType()) {
		case IID_AMMO:
        case IID_RESTORE_HEALTH:
        case IID_EXTRA_LIFE:
        case IID_BULLET: 
        case IID_HOLE:
        case IID_EXIT:
			return actor2;
        case IID_ROBOT_FACTORY:
		{
			if (actor2->getType() == IID_BULLET){
                return actor1;
			}
			else{
				return actor2;
			}
        }
	}
	return actor1;
}

bool StudentWorld::isThereKleptoBotAt(int posX, int posY){
	for(Actor* actor : m_actorList){
		if(actor->getX() == posX && actor->getY() == posY){
			int typeID = actor->getType();
			if(typeID == IID_KLEPTOBOT || typeID == IID_ANGRY_KLEPTOBOT){
				return true;
			}
		}
	}
	return false;
}

int StudentWorld::getCurrentLevelNum(){
	return m_currentLevelNum;
}

void StudentWorld::addActor(Actor *actor){
	m_actorList.push_back(actor);
}

void StudentWorld::increaseCollectedJewels(){
	m_collectedJewels++;
	if(m_collectedJewels >= m_totalJewels){
		m_exit->setVisible(true);
	}
}

void StudentWorld::increaseTotalJewels(){
	m_totalJewels++;
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
