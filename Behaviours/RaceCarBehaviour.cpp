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

    // braking
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->brake(step);
    }

    // steering
    int direction = _raceCar->CENTER;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction = _raceCar->LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction = _raceCar->RIGHT;
    }

    _raceCar->rotateWheels(step, direction);
    _raceCar->steerCar(step, direction);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        _raceCar->playHorn();
    }
}
