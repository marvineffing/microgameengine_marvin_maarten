#include "Light.hpp"

#include "Renderer.hpp"

Light::Light( std::string aName, glm::vec3 aPosition, ShaderProgram* shaderProgram )
:	GameObject( aName, aPosition, shaderProgram)
{
}

Light::~Light()
{
	//dtor
}

void Light::draw( Renderer * aRenderer, glm::mat4 parentTransform )
{
	aRenderer->setLight( getLocation() );
}
