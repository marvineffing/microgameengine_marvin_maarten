#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"

World::World( std::string aName )
:	GameObject( aName )
{
	//ctor
	soundBuffer.loadFromFile("sounds/crash.wav");
}

World::~World()
{
	//dtor
}

void World::update( float step )
{
	//camera->update( step );
	GameObject::update( step );
}

void World::draw( Renderer * renderer )
{
	assert( renderer != NULL );
	GameObject::draw( renderer ); // draw children Game Objects
}

bool World::checkCollisions()
{
	bool result = false;
	for ( std::vector< GameObject * >::iterator collider = children.begin(); collider != children.end(); ++collider ) {
		if ( ((GameObject * )*collider)->hasCollider() ) {
			for ( std::vector< GameObject * >::iterator collidee = collider+1; collidee != children.end(); ++collidee ) {
				if ( ((GameObject * )*collidee)->hasCollider() ) {

					result = result || ((GameObject * )*collider)->collides( (GameObject *)*collidee );
					//laat racecar stoppen

				}
			}
		}
	}
	return result; // any collision
}

