#include "Tire.hpp"

Tire::Tire(std::string name, glm::vec3 position, ShaderProgram* shaderProgram) : GameObject(name, position, shaderProgram)
{
    //_angle = glm::translate(position);
}

void Tire::setAngle(float angle, glm::vec3 axis)
{
    _angle = glm::rotate(glm::translate(_angle[3][0], _angle[3][1], _angle[3][2]), angle, axis);
}

void Tire::draw(Renderer* aRenderer, glm::mat4 parentTransform)
{
    GameObject::draw(aRenderer, parentTransform*_angle);
}
