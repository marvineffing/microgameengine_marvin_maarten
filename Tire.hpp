#pragma once

#include <string>
#include "glm.hpp"

#include "GameObject.hpp"

class Tire : public GameObject
{
    public:
        Tire(std::string name, glm::vec3 position, ShaderProgram* shaderProgram);
};
