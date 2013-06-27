#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "ShaderProgram.hpp"

World::World( std::string aName, ShaderProgram* shaderProgram )
:	GameObject( aName, glm::vec3(0,0,0), shaderProgram )
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
                    //als gameobject finish lijn is
					result = result || ((GameObject * )*collider)->collides( (GameObject *)*collidee );
					//laat racecar stoppen

				}
			}
		}
	}
	return result; // any collision
}

bool World::checkFinishCollisions() {
    bool result = false;

    //voor alle game objecten
    for (std::vector<GameObject*>::iterator collider = children.begin(); collider!=children.end(); ++collider) {

        if ( ((GameObject*)*collider)->hasCollider() ) { //als gameobject een collider heeft

            for ( std::vector<GameObject*>::iterator finishCollider = children.begin(); finishCollider!=children.end(); ++finishCollider) {

                if ( ((GameObject*)*finishCollider)->hasFinishCollider() ) { //en ander object heeft finishCollider
                    result = result || ( (GameObject*) *collider )->collidesFinish( (GameObject*)*finishCollider );
                }

            }

        }

    }

    return result;
}
