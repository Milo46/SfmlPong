#include "State.h"

namespace Pong
{
    State::State(StateData* state_data)
    {
        this->stateData = state_data;

        this->window = this->stateData->window;
        this->states = this->stateData->states;

        this->quit = false;
    }

    State::~State()
    {

    }

    const bool& State::getQuit() const
    {
        return this->quit;
    }

    void State::endState()
    {
        this->quit = true;
    }
}
