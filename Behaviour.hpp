#pragma once

class GameObject;
class Behaviour
{
	protected:
		GameObject * parent;

	public:
		Behaviour( GameObject * aParent );
		virtual ~Behaviour();

		virtual void update( float step );
		virtual void onCollision( GameObject * otherGameObject );

};
