#pragma once

#include "Paddle.h"
#include "Timer.h"
#include "PointsCounter.h"

namespace Pong
{
    const float pi = 3.14159f;

    class BallData
    {
    public:
        BallData() {};

        sf::Vector2f windowSize;
        float sideSize;
        float velocity;
        float maxBounceAngle;

        float targetTimerTime;
    };

    class Ball
    {
    private:
        BallData* ballData;

        sf::Vector2f windowSize;

        sf::RectangleShape shape;
        float angle;
        float maxBounceAngle;
        float velocity;

        int mltX, mltY;

        bool setup;
        Timer timer;

        PointsCounter pointsCounter;

    public:
        Ball();
        Ball(BallData* ballData);
        virtual ~Ball();

        sf::FloatRect getGlobalBounds();

        void reset();

        bool isOutFromUpperBorder();
        bool isOutFromBottomBorder();

        //bool isScore(Paddle& left, Paddle& right);

        void update(const float& dt, Paddle& left, Paddle& right);
        void render(sf::RenderTarget* target);
    };
}
