#pragma once

#include "State.h"

namespace Pong
{
    class GameState : public State
    {
    private:
        PaddleData left_paddleData;
        PaddleData right_paddleData;
        Paddle left_paddle;
        Paddle right_paddle;

        BallData ballData;
        Ball ball;

    public:
        GameState(StateData* state_data);
        virtual ~GameState();

        void update(const float& dt);
        void render(sf::RenderWindow* window = nullptr);

    };
}
