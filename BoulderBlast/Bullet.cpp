#include "Bullet.h"


void Bullet::doSomething(){
	int destinationX, destinationY;
	getDestinationCoordinates(getDirection(), destinationX, destinationY);
	moveTo(destinationX, destinationY);
}