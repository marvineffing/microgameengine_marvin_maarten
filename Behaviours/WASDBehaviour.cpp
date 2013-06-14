#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "WASDBehaviour.hpp"
#include "../glm.hpp"
#include "../GameObject.hpp"

WASDBehaviour::WASDBehaviour( GameObject * aParent, sf::Window * aWindow )
:	Behaviour( aParent ), window( aWindow )
{
    soundBuffer.loadFromFile("sounds/crash.wav");
}

WASDBehaviour::~WASDBehaviour()
{

}

void WASDBehaviour::update( float step )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W )) {
		parent->translate( glm::vec3(0.0f, 0.0f, step*10 ) );
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A )) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            parent->rotate(step*50,glm::vec3(0,1.0,0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            parent->rotate(-step*50,glm::vec3(0,1.0,0));
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S )) {
		parent->translate( glm::vec3(0.0f, 0.0f, -step*10 ) );
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D )) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            parent->rotate(-step*50, glm::vec3(0,1.0,0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            parent->rotate(step*50, glm::vec3(0,1.0,0));
	}

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::H)) {
        if (sound.getStatus() == sf::Sound::Stopped) {
            playHonkSound();
        }
    }

}

void WASDBehaviour::playHonkSound() {
    sound.setBuffer(soundBuffer);
    sound.play();
    std::cout << "found it" << std::endl;
}

	//std::cout << turnHorizontal << std::endl;

