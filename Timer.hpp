#pragma once

class Timer
{
    private:
        float _passedTime;
        bool _running;
    public:
        Timer();

        void startTimer();
        float stopTimer();
        void resetTimer();
        void updateTimer();
};
