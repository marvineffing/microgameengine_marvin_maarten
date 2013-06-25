#pragma once

#include <SFML/Audio.hpp>

#include "GameObject.hpp"
#include "Tire.hpp"

class RaceCar : public GameObject
{
    private:
        static const float _speed_limit = 10.0f;
        static const float _speed_limit_reverse = -5.0f;
        static const float _acceleration = 0.005f;
        static const float _deceleration = 0.005f;
        static const float _fast_deceleration = 0.02f;
        static const float _handeling = 5.0f;

        float _speed;
        float _steering_angle;
        float _wheel_rotatingAngle;

        std::vector<Tire*> _tires;

        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;

        void correctSpeed();

    public:
        static const int LEFT = 0;
        static const int RIGHT = 1;

        RaceCar(glm::vec3 position);

        void accelerate(float step);
        void decelerate(float step);
        void brake(float step);
        void reverseAccelerate(float step);
        void steerCar(float step, int direction);
        void steerWheels(float step, int direction);
        void resetSteerWheels();
        void rotateWheels(float step);

        void playHorn();

        int getSpeed();
        void setSpeed(int speed);
        int getSpeedLimit();
};

