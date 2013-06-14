#pragma once

#include <SFML/Window.hpp>
#include "../Behaviour.hpp"
#include <SFML/Audio.hpp>


class WASDBehaviour : public Behaviour
{
	private:
		sf::Window * window;
		sf::SoundBuffer soundBuffer;
        sf::Sound sound;

	public:
		WASDBehaviour( GameObject * aParent, sf::Window * aWindow );
		virtual ~WASDBehaviour();
        void playHonkSound();
		virtual void update( float step );
};
