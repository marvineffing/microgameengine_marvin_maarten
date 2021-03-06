#pragma once

#include <SFML/Audio.hpp>

#include "GameObject.hpp"
#include "Tire.hpp"
#include "ShaderProgram.hpp"

class RaceCar : public GameObject
{
    private:
        sf::Sound sound;
        sf::SoundBuffer crashSoundBuffer;
        sf::SoundBuffer startSoundBuffer;

        static const float _speed_limit = 10.0f;
        static const float _speed_limit_reverse = -5.0f;
        static const float _acceleration = 0.005f;
        static const float _deceleration = 0.005f;
        static const float _fast_deceleration = 0.02f;
        static const float _steering = 50.0f;
        static const float _steering_limit = 150.0f;
        static const float _yrot_wheel_step = 50.0f;
        static const float _yrot_wheel_limit = 45.0f;

        float _xrot_wheel;
        float _yrot_wheel;
        float _speed;
        std::vector<Tire*> _tires;
        ShaderProgram * _shaderProgram;
        int _hitCounter;

        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;

        void correctSpeed();

    public:
        static const int LEFT = 0;
        static const int RIGHT = 1;
        static const int CENTER = 2;

        RaceCar(std::string name, glm::vec3 position, ShaderProgram* shaderProgram);

        void accelerate(float step);
        void decelerate(float step);
        void brake(float step);
        void stop();
        void reverseAccelerate(float step);
        void steerCar(float step, int direction);
        void rotateWheels(float step, int direction);
        void onCollision(GameObject * anObject);
        void crashCar();
        void completeLap();

        void playHorn();

        float getSpeed();
        void setSpeed(int speed);
        int getSpeedLimit();
};

