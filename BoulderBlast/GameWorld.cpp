#include "GameWorld.h"
#include "GameController.h"
#include <string>
#include <cstdlib>
using namespace std;

bool GameWorld::getKey(int& value)
{
	if(m_controller == NULL){
		cout << "Controller NULL" << endl;
	}
	bool gotKey = m_controller->getLastKey(value);

	if (gotKey && (value == 'q' || value == '\x03'))  // CTRL-C
			exit(0);

	return gotKey;
}

void GameWorld::playSound(int soundID)
{
	m_controller->playSound(soundID);
}

void GameWorld::setGameStatText(string text)
{
	m_controller->setGameStatText(text);
}
