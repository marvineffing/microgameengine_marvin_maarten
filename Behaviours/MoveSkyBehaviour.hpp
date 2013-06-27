#pragma once

#include "../Behaviour.hpp"
#include "../RaceCar.hpp"
#include "../GameObject.hpp"

class MoveSkyBehaviour : public Behaviour
{
    private:
        RaceCar * _raceCar;

    public:
        MoveSkyBehaviour(GameObject* parent, RaceCar* raceCar);

        virtual void update(float step);
};
