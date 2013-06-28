#pragma once

#include <string>
#include "glm.hpp"

#include "GameObject.hpp"

class Tire : public GameObject
{
    private:
        glm::mat4 _angle;
    public:
        Tire(std::string name, glm::vec3 position, ShaderProgram* shaderProgram);
        void setAngle(float angle, glm::vec3 axis);
        void draw(Renderer* aRenderer, glm::mat4 parentTransform = glm::mat4(1));
};
