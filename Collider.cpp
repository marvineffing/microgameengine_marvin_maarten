#include <iostream>
#include "Collider.hpp"
#include "GameObject.hpp"

Collider::Collider( GameObject * aParent, float aRadius )
:	parent(aParent), radius( aRadius )
{
	soundBuffer.loadFromFile("sounds/crash.wav");
}

Collider::~Collider()
{
	//dtor
}

bool Collider::collides( Collider * otherCollider )
{
	//std::cout << "Check CD for " << parent->getName() << std::endl;
	glm::vec3 location = parent->getLocation();
	glm::vec3 otherLocation = otherCollider->parent->getLocation();
	float distance = glm::distance( location, otherLocation );
	if ( distance < radius + otherCollider->radius ) { // in case of colliding
    //todo: stopping behaviour

        parent->onCollision(otherCollider->parent);
		std::cout << parent->getName() << " Hits " << otherCollider->parent->getName() << std::endl;
		return true;
	};
	return false;
}

/**
* Returns wether or not Object collides with finish line so that a lap may be registered.
* TODO: increase lap # when colliding in Gameplay
**/
bool Collider::collidesWithFinish(FinishCollider * otherCollider) {
    bool retVal = false;

    std::cout << "Collided with finish." << std::endl;
    return retVal;

}

