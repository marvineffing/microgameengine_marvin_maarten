#pragma once
#include "../Behaviour.hpp"

class RotatingBehaviour : public Behaviour
{
	public:
		RotatingBehaviour( GameObject * aParent );
		virtual ~RotatingBehaviour();

		virtual void update( float step );

};
