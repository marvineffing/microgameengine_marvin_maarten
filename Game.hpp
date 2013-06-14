#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Hud.hpp"
#include "Renderer.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Gameplay.hpp"

class Game
{
	private: // data members
		sf::RenderWindow * window;
		Hud * hud;
		Renderer * renderer;
		Gameplay * gameplay;

		bool running;
		sf::Music music;

	public: // functions
		Game();
		virtual ~Game();

		void build();
		void run();
		void stop();

		void playMusic();
		void pauseMusic();

	private:
		void control();
		void update( float step );
		void draw();
		bool checkCollisions();

};
