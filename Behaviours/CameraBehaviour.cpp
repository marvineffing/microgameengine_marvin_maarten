#include "CameraBehaviour.hpp"

CameraBehaviour::CameraBehaviour(GameObject * aParent) : Behaviour(aParent)
{
//    parent->transform =
//    glm::mat4 at = glm::translate(parent->transform, glm::vec3(0,10,2));
//    parent->transform = glm::inverse( glm::lookAt(glm::vec3(at[3][0],at[3][1],at[3][2]),
//                                              glm::vec3(parent->transform[3][0], parent->transform[3][1], parent->transform[3][2]),
//                                              glm::vec3(0.0f, 1.0f, 0.0f)));
//    parent->rotate(180, glm::vec3(0,1,0));
}

void CameraBehaviour::update(float step)
{

}

void CameraBehaviour::onCollision(GameObject * otherGameObject)
{

}
