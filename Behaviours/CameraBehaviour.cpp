#include "CameraBehaviour.hpp"

CameraBehaviour::CameraBehaviour(GameObject * aParent, GameObject * aCar) : Behaviour(aParent), car(aCar)
{

}

void CameraBehaviour::update(float step)
{
    glm::mat4 at = glm::translate(car->transform, glm::vec3(1,0.85, -1.5));
    parent->transform = glm::inverse( glm::lookAt(glm::vec3(at[3][0],at[3][1],at[3][2]),
                                                  glm::vec3(car->transform[3][0], car->transform[3][1], car->transform[3][2]),
                                                  glm::vec3(0.0f, 1.0f, 0.0f)));
    parent->rotate(20, glm::vec3(1.0f,0,0));
}

void CameraBehaviour::onCollision(GameObject * otherGameObject)
{

}
