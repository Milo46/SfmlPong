#pragma once

#include "Textbox.h"

namespace Pong
{
    enum ButtonStates {
        BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE
    };

    struct ButtonColors
    {
        sf::Color idle, hover, active;

        ButtonColors();
        ButtonColors(const sf::Color& idle, const sf::Color& hover, const sf::Color& active);
    };

    class Button : public Textbox
    {
    private:
        short unsigned buttonState;

        ButtonColors buttonColors;

    public:
        Button(const sf::Vector2f& pos = sf::Vector2f(), const sf::Vector2f& size = sf::Vector2f(), sf::Font* font = NULL,
            const std::string& text = "", const unsigned& textSize = 26, const ButtonColors& buttonColors = ButtonColors());
        virtual ~Button();

        bool isPressed();

        void changeText(const std::string& text);

        void update(const sf::Vector2f& mousePos);
    };
}
