#pragma once

#include <iostream>

namespace Pong
{
    class PointsCounter
    {
    private:
        int left, right;

    public:
        PointsCounter();
        virtual ~PointsCounter();

        void incrementLeft();
        void incrementRight();

        void reset();

        void render();
    };
}
