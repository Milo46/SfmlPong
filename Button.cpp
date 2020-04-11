#include "Button.h"

namespace Pong
{
    ButtonColors::ButtonColors()
    {
        this->idle = sf::Color();
        this->hover = sf::Color();
        this->active = sf::Color();
    }

    ButtonColors::ButtonColors(const sf::Color& idle, const sf::Color& hover, const sf::Color& active)
    {
        this->idle = idle;
        this->hover = hover;
        this->active = active;
    }

    Button::Button(const sf::Vector2f& pos, const sf::Vector2f& size, sf::Font* font, const std::string& text, const unsigned& textSize, const ButtonColors& buttonColors)
        :Textbox(pos, size, font, text, textSize, buttonColors.idle)
    {
        this->buttonState = BTN_IDLE;

        this->buttonColors = buttonColors;
    }

    Button::~Button()
    {

    }

    bool Button::isPressed()
    {
        if (this->buttonState == BTN_ACTIVE)
            return true;
        return false;
    }

    void Button::changeText(const std::string& text)
    {
        this->setText(text);
    }

    void Button::update(const sf::Vector2f& mousePos)
    {
        this->buttonState = BTN_IDLE;

        if (this->getShape().getGlobalBounds().contains(mousePos))
        {
            this->buttonState = BTN_HOVER;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->buttonState = BTN_ACTIVE;
            }
        }

        switch (this->buttonState)
        {
        case BTN_IDLE:
            this->setFillColor(this->buttonColors.idle);
            break;

        case BTN_HOVER:
            this->setFillColor(this->buttonColors.hover);
            break;

        case BTN_ACTIVE:
            this->setFillColor(this->buttonColors.active);
            break;
        }
    }
}
