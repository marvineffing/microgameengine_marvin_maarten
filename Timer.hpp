#ifndef TIMER_H
#define TIMER_H

#include <SFML/System.hpp>

class Timer
{
	private: // data members
		static sf::Clock clock;
		static float currentTime;
        static float lastLap;
        static float bestLap;

	private: // disable creation of time object
		Timer(){}
	public: // functons
		static void update();
		static float now();
		static float getLastLap();
		static void reset();
		static float getBestLap();

};

#endif // TIMER_H

