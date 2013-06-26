#include "RaceCarBehaviour.hpp"

RaceCarBehaviour::RaceCarBehaviour(RaceCar* raceCar) : Behaviour(raceCar), _raceCar(raceCar)
{

}

void RaceCarBehaviour::update(float step)
{
    // forward and backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->accelerate(step);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->reverseAccelerate(step);
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->decelerate(step);
    }

    // brakeing
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->brake(step);
    }

    // steering
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _raceCar->steerCar(step, _raceCar->LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _raceCar->steerCar(step, _raceCar->RIGHT);
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _raceCar->resetSteerWheels(step);
    }

    _raceCar->rotateWheels(step);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        _raceCar->playHorn();
    }
}
