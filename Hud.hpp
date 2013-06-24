#pragma once

#include <SFML/Graphics.hpp>

class Hud
{
	private:
		sf::RenderWindow * window;
		sf::Font font;
	public:
		Hud( sf::RenderWindow * aWindow );
		virtual ~Hud();

		void draw( );
};
