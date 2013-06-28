#include "Timer.hpp"
#include "Time.hpp"
#include <iostream>

sf::Clock Timer::clock;
float Timer::currentTime = 0.0f;
float Timer::bestLap = 0.0f;
bool started = false;

void Timer::update()
{
    if (started)
        currentTime += Time::step();
}

float Timer::now()
{
	return currentTime;
}

float Timer::start()
{
    started = true;
}

void Timer::reset()
{
    if (currentTime < bestLap) {
        bestLap = currentTime;
    }
    currentTime = 0.0f;
}

float Timer::getBestLap()
{
    return bestLap;
}

void Timer::setBestTime(float time)
{
    bestLap = time;
}

