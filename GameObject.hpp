#pragma once

#include <vector>
#include <string>
#include "glm.hpp"

#include "Collider.hpp"
#include "Renderer.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Behaviour.hpp"

class GameObject
{
	protected:
		std::string name;
		Collider * collider;
		Behaviour * behaviour;

		Mesh * mesh;
		Texture * colorMap;


		std::vector< GameObject * > children;

	public:
		GameObject( std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 0.0f, 0.0f, 0.0f ) );
		virtual ~GameObject();

		void translate( glm::vec3 translation );
		void rotate( float angle, glm::vec3 axis );
		void scale(glm::vec3 detail);

		const std::string getName();
		glm::vec3 getLocation();
		void setLocation(glm::vec3 newLocation);
		bool hasCollider();

		glm::mat4 transform;

		void setBehaviour( Behaviour * aBehaviour );
		void setCollider( Collider * aCollider );
		void setMesh( Mesh * aMesh );
		void setColorMap( Texture * aColorMap );

		virtual void update( float step );
		virtual bool collides( GameObject * otherGameObject );
		virtual void onCollision(  GameObject * otherGameObject );
		virtual void draw( Renderer * renderer, glm::mat4 parentTransform = glm::mat4(1) );


		void add( GameObject * child );

	protected:

};
