#include <cassert>
#include <iostream>

#include "Renderer.hpp"
#include "GameObject.hpp"
#include "Collider.hpp"
#include "Behaviour.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

GameObject::GameObject( std::string aName, glm::vec3 aPosition, ShaderProgram* shaderProgram)
:	name( aName ), transform( glm::translate( aPosition ) ), _shaderProgram(shaderProgram), collider( NULL ), behaviour( NULL ), mesh( NULL ), colorMap( NULL )
{
}

GameObject::~GameObject()
{
	//dtor
}

void GameObject::translate( glm::vec3 translation )
{
	transform = glm::translate( transform, translation );
}
void GameObject::rotate( float angle, glm::vec3 axis )
{
	transform = glm::rotate( transform, angle, axis);
}

void GameObject::scale(glm::vec3 detail)
{
    transform = glm::scale(transform, detail);
}

const std::string GameObject::getName()
{
	return name;
}

glm::vec3 GameObject::getLocation()
{
	return glm::vec3( transform[3][0], transform[3][1], transform[3][2] );
}

void GameObject::setLocation(glm::vec3 newLocation)
{
    transform[3][0] = newLocation.x;
    transform[3][1] = newLocation.y;
    transform[3][2] = newLocation.z;
}

bool GameObject::hasCollider()
{
	return collider != NULL;
}

bool GameObject::hasFinishCollider() {
    return finishCollider != NULL;
}

void GameObject::setBehaviour( Behaviour * aBehaviour )
{
	assert( aBehaviour != NULL );
	behaviour = aBehaviour;
}

void GameObject::setCollider( Collider * aCollider )
{
	assert( aCollider != NULL );
	collider = aCollider;
}

void GameObject::setFinishCollider( FinishCollider * aCollider ) {
    assert( aCollider != NULL );
    finishCollider = aCollider;
}

void GameObject::setMesh( Mesh * aMesh )
{
	assert( aMesh != NULL );
	mesh = aMesh;
}

void GameObject::setColorMap( Texture * aColorMap )
{
	assert( aColorMap != NULL );
	assert( aColorMap->getId() > 0 );
	colorMap = aColorMap;
}

void GameObject::update( float step )
{
	if ( behaviour ) {
		behaviour->update( step );
	}
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
		((GameObject * )*i)->update( step );
	}

}


bool GameObject::collides( GameObject * otherGameObject )
{
	assert( collider != NULL );
	assert( otherGameObject != NULL );
	assert( otherGameObject->collider != NULL );
	return collider->collides( otherGameObject->collider );
}

bool GameObject::collidesFinish(GameObject * otherGameObject) {
    assert ( collider != NULL);
    assert ( otherGameObject != NULL);
    assert ( otherGameObject->finishCollider != NULL);
    return collider->collidesWithFinish(otherGameObject->finishCollider);
}

void GameObject::onCollision(  GameObject * otherGameObject )
{
    if (otherGameObject->getName() == "START") {
        std::cout << "whoop whoop" << std::endl;
    }
}

void GameObject::onCollisionFinish( GameObject * otherGameObject) {
    if ( behaviour) {
        behaviour->onCollision(otherGameObject);
    }
}

void GameObject::draw( Renderer * aRenderer, glm::mat4 parentTransform )
{
	assert( aRenderer != NULL );

    aRenderer->use(_shaderProgram);

	if ( mesh ) { // if there is something to draw
		aRenderer->setModel( parentTransform * transform ); // combine parents transfor with own
		if ( colorMap ) { //is has a colormap
			aRenderer->setColorMap( colorMap );
		}
		mesh->draw( aRenderer );
	}
	// draw children
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
		((GameObject * )*i)->draw( aRenderer, parentTransform * transform );
	}
}

void GameObject::add( GameObject * child )
{
	assert( child != NULL );
	children.push_back( child );
}

ShaderProgram* GameObject::getShaderProgram()
{
    return _shaderProgram;
}

FinishCollider* GameObject::getFinishCollider() {
    return finishCollider;
}

// private functions

