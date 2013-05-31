#pragma once

#include <SFML/System.hpp>

class Time
{
	private: // data members
		static sf::Clock clock;
		static float currentTime;
		static float deltaTime;

	private: // disable creation of time object
		Time(){}

	public: // functons
		static void update();
		static float now();
		static float step();

};
