#pragma once
#include "FinishCollider.h"

#include <SFML/Audio.hpp>

class GameObject;
class SphereCollider;
class Collider
{
private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
	protected:



	public:
		Collider( GameObject * aParent, float aRadius = 1.0f );
		virtual ~Collider();

		virtual bool collides( Collider * otherCollider );
		virtual bool collidesWithFinish( FinishCollider * otherCollider);
        float radius;
        GameObject * parent;
};
