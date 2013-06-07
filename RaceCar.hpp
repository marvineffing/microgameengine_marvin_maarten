#pragma once


#include "GameObject.hpp"
#include "Tire.h"

class RaceCar : public GameObject
{
    private:
        int _speed;
        int _speed_limit;

    public:
        RaceCar(glm::vec3 position);

        int getSpeed();
        void setSpeed(int speed);
        int getSpeedLimit();
};
