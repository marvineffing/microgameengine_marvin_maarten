#pragma once

#include <SFML/Audio.hpp>
#include "../Behaviour.hpp"
#include <SFML/Window.hpp>

class SoundBehaviour : public Behaviour {

private:
    sf::Window * window;

public:
    SoundBehaviour(GameObject * aParent, sf::Window * aWindow);
    virtual ~SoundBehaviour();
    virtual void update(float step);
};
