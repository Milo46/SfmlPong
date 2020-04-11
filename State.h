#pragma once

#include "Button.h"

namespace Pong
{
    class State;

    class StateData
    {
    public:
        StateData() {};

        sf::RenderWindow* window;
        std::stack<State*>* states;
    };

    class State
    {
    private:

    protected:
        StateData* stateData;
        sf::RenderWindow* window;
        std::stack<State*>* states;
        bool quit;

    public:

        State(StateData* state_data);
        virtual ~State();

        const bool& getQuit() const;

        void endState();

        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderWindow* window = NULL) = 0;

    };
}
