#include "RaceCarBehaviour.hpp"

RaceCarBehaviour::RaceCarBehaviour(RaceCar* raceCar) : Behaviour(raceCar), _raceCar(raceCar)
{

}

void RaceCarBehaviour::update(float step)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->brake(step);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _raceCar->steer(step, _raceCar->LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _raceCar->steer(step, _raceCar->RIGHT);
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->accelerate(step);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _raceCar->reverseAccelerate(step);
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _raceCar->decelerate(step);
    }

    _raceCar->rotateWheels(step);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        _raceCar->playHorn();
    }
}
