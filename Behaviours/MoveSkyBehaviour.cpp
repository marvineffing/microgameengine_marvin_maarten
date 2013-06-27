#include "MoveSkyBehaviour.hpp"

MoveSkyBehaviour::MoveSkyBehaviour(GameObject* parent, RaceCar* raceCar) : Behaviour(parent), _raceCar(raceCar)
{

}

void MoveSkyBehaviour::update(float step)
{
    parent->setLocation(_raceCar->getLocation());
}
