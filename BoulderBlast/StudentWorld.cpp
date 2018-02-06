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
	
	for(Actor *actor : m_actorList){
		actor->doSomething();
	}


	//decLives();
	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::loadLevel(int levelNum){
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
			{
				Player *player = new Player(col, row, 100, this, GraphObject::right);
				m_actorList.push_back(player);
				break;
			}
			case Level::hole:
				//cout << "Hole is at (" << row << ", " << col << ")" << endl;
				break;
			case Level::wall:
			{
				Wall *newWall = new Wall(col, row, this);
				newWall->setVisible(true);
				m_actorList.push_back(newWall);
				break;
			}
			default:
				break;
			}
		}
	}
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


// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
