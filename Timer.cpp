#include "Timer.h"

namespace Pong
{
    Timer::Timer()
    {
        this->timerStatus = TimerStatus::Off;
        this->targetTime = 0.f;
        this->currentTime = 0.f;
    }

    Timer::Timer(const float& targetTime)
    {
        this->timerStatus = TimerStatus::On;
        this->targetTime = targetTime;
        this->currentTime = 0.f;
    }

    Timer::~Timer()
    {

    }

    void Timer::start()
    {
        this->timerStatus = TimerStatus::On;
    }

    TimerStatus Timer::status()
    {
        return this->timerStatus;
    }

    bool Timer::isDone()
    {
        if (this->currentTime >= this->targetTime)
        {
            return true;
        }
        return false;
    }

    void Timer::reset()
    {
        this->currentTime = 0.f;
        this->timerStatus = TimerStatus::Off;
    }

    void Timer::update(const float& dt)
    {
        if (!this->isDone())
        {
            this->currentTime += dt;
        }
        else
        {
            this->reset();
        }
    }
}
