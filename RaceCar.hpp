#pragma once


#include "GameObject.hpp"
#include "Tire.hpp"

class RaceCar : public GameObject
{
    private:
        float _speed;
        static const float _speed_limit = 10.0f;
        static const float _speed_limit_reverse = -5.0f;
        static const float _acceleration = 0.005f;
        static const float _handeling = 5.0f;

    public:
        static const int LEFT = 0;
        static const int RIGHT = 1;

        RaceCar(glm::vec3 position);

        void accelerate(float step);
        void decelerate(float step);
        void brake(float step);
        void reverseAccelerate(float step);
        void steer(float step, int direction);

        int getSpeed();
        void setSpeed(int speed);
        int getSpeedLimit();
};

