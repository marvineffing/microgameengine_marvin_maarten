#pragma once

#include "../Behaviour.hpp"
#include "../RaceCar.hpp"

class RaceCarBehaviour : public Behaviour
{
    private:
        RaceCar * _raceCar;


    public:
        RaceCarBehaviour(RaceCar* raceCar);

        virtual void update(float step);
};
