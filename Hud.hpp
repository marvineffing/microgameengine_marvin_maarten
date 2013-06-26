#pragma once

#include <SFML/Graphics.hpp>
#include "Gameplay.hpp"

class Hud
{
	private:
		sf::RenderWindow * _window;
		sf::Font _font;
		Gameplay * _gameplay;

		void drawFPS();
		void drawSpeed();
        void drawTime();

	public:
		Hud( sf::RenderWindow * aWindow, Gameplay * gameplay);
		virtual ~Hud();

		void draw( );
};
