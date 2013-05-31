#pragma once

class GameObject;
class SphereCollider;
class Collider
{
	protected:
		GameObject * parent;
		float radius;

	public:
		Collider( GameObject * aParent, float aRadius = 1.0f );
		virtual ~Collider();

		virtual bool collides( Collider * otherCollider );

};
