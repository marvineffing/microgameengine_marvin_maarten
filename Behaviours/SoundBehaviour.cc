#include "SoundBehaviour.h"

SoundBehaviour::SoundBehaviour(GameObject * aParent, sf::Window * aWindow) : Behaviour( aParent), window(aWindow)
{
}


SoundBehaviour::~SoundBehaviour() {
}

void SoundBehaviour::update(float step) {
    sf::SoundBuffer* buffer;

    //if(!buffer.loadFromFile("sound/crash.wav")) {
        //error
    //}

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Y)) {

    }
}
