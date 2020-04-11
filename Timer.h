#pragma once

namespace Pong
{
    enum TimerStatus
    {
        On = 0, Off
    };

    class Timer
    {
    private:
        TimerStatus timerStatus;

        float targetTime;
        float currentTime;

    public:
        Timer();
        Timer(const float& targetTime);
        virtual ~Timer();

        void start();
        TimerStatus status();

        bool isDone();

        void reset();

        void update(const float& dt);
    };
}
