#pragma once

#include "MainMenuState.h"

namespace Pong
{
    class Game
    {
    private:
        StateData stateData;
        sf::RenderWindow* window;
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;

        std::stack<State*> states;

        void update();
        void updateDt();
        void updateSFMLEvents();
        void render();

        void endGame();

    public:
        Game();
        virtual ~Game();

        void run();

    };
}
