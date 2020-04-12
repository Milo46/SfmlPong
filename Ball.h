#ifndef BALL_H
#define BALL_H

#include "Timer.h"

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

    public:
        Ball();
        Ball(BallData* ballData);
        virtual ~Ball();

        sf::FloatRect getGlobalBounds();

        void reset();

        bool isOutFromUpperBorder();
        bool isOutFromBottomBorder();

        //bool isScore(Paddle& left, Paddle& right);

        /* Ball::update() returns one of these values: {-1, 0, 1}, which means:
            (-1): left paddle gained point in this frame
            (0): nobody gained point in this frame
            (1): right paddle gained point in this frame
        */
        int update(const float& dt, Paddle& left, Paddle& right);
        void render(sf::RenderTarget* target);
    };
}

#endif
