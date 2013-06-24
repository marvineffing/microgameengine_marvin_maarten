#pragma once

#include "../Behaviour.hpp"
#include "../glm.hpp"
#include "../GameObject.hpp"

class CameraBehaviour : public Behaviour
{
    public:
        CameraBehaviour(GameObject * aParent);
        void update(float step);
        void onCollision(GameObject * otherGameObject);
};
