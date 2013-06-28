#include "Checkpoint.h"

#include "Timer.hpp"
Checkpoint::Checkpoint(std::string aName, glm::vec3 aPosition, ShaderProgram* shaderProgram )
:	GameObject(aName, aPosition, shaderProgram )
{
}

Checkpoint::~Checkpoint()
{
    //dtor
}

void Checkpoint::onCollision(GameObject * otherGameObject) {
}
