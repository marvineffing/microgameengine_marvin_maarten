#ifndef TIMER_H
#define TIMER_H

#include <SFML/System.hpp>

class Timer
{
	private: // data members
		static sf::Clock clock;
		static float currentTime;
        static float lastLap;

	private: // disable creation of time object
		Timer(){}
	public: // functons
		static void update();
		static float now();
		static float getLastLap();
		static void reset();

};

#endif // TIMER_H

