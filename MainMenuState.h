#pragma once

#include "GameState.h"

namespace Pong
{
    class MainMenuState : public State
    {
    private:
        sf::Vector2i mousePosition;

        sf::Font* font;

        Textbox title;
        std::map<std::string, Button*> buttons;

    public:
        MainMenuState(StateData* state_data);
        virtual ~MainMenuState();

        void update(const float& dt);
        void render(sf::RenderWindow* window = NULL);
    };
}
