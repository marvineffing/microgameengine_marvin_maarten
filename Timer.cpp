#include "Timer.hpp"
#include "Time.hpp"

Timer::Timer() : _passedTime(0)
{

}

void Timer::startTimer()
{
    _running = true;
}

float Timer::stopTimer()
{
    _running = false;
    return _passedTime;
}

void Timer::updateTimer()
{
    if (_running) {
        _passedTime += Time::step();
    }
}

void Timer::resetTimer()
{
    _running = false;
    _passedTime = 0;
}
