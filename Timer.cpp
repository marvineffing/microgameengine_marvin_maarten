#include "Timer.hpp"
#include "Time.hpp"
#include <iostream>

sf::Clock Timer::clock;
float Timer::currentTime = 0.0f;
float Timer::lastLap = 0.0f;
float Timer::bestLap = 1000.0f;

void Timer::update()
{
    currentTime += Time::step();
}

float Timer::now()
{
	return currentTime;
}
float Timer::getLastLap() {
    return lastLap;
}
void Timer::reset(){
    //omdat de tijd andere na 0.00000xx seconden weer reset. Collision vindt plaatst op meer dan 1 tijdstip.
    if( currentTime > 5 ) {
        lastLap = currentTime;
        if (currentTime < bestLap) {
            bestLap = currentTime;
        }
    }
    currentTime = 0.0f;
}

float Timer::getBestLap() {
    return bestLap;
}

