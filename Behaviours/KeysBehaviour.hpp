#pragma once

#include "../Behaviour.hpp"


class KeysBehaviour : public Behaviour
{
	public:
		KeysBehaviour( GameObject * aParent );
		virtual ~KeysBehaviour();

		virtual void update( float step );
};
