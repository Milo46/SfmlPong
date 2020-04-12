#ifndef GAMESTATE_H
#define GAMESTATE_H

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

        //Group of variables which are scoreboard,
        //it's not a one class because I'm having an issue
        sf::Font font;
        Textbox scoreboard;
        int left_points, right_points;

    public:
        GameState(StateData* state_data);
        virtual ~GameState();

        void update(const float& dt);
        void render();

    };
}

#endif
