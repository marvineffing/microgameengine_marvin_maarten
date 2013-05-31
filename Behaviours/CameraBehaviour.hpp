#pragma once

#include "../Behaviour.hpp"
#include "../glm.hpp"
#include "../GameObject.hpp"

class CameraBehaviour : public Behaviour
{
    private:
        GameObject * car;
    public:
        CameraBehaviour(GameObject * aParent, GameObject * aCar);
        void update(float step);
        void onCollision(GameObject * otherGameObject);
};
