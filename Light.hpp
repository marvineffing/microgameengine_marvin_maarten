#pragma once
#include <string>
#include "GameObject.hpp"
#include "ShaderProgram.hpp"

class Renderer;
class Light : public GameObject
{
	public:
		Light( std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 2.0f, 10.0f, 5.0f ), ShaderProgram* shaderProgram = NULL);
		virtual ~Light();

		void draw( Renderer * renderer, glm::mat4 parentTransform = glm::mat4(1) );
};
