#pragma once

#include <string>
#include "GameObject.hpp"

class Renderer;

class Camera : public GameObject
{
	private: //members
		glm::mat4 projection;

	public:
		Camera( std::string aName, glm::vec3 aPosition);
		virtual ~Camera();

		void draw( Renderer * renderer, glm::mat4 parentTransform = glm::mat4(1) );

};
