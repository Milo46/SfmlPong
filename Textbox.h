#pragma once

#include "Ball.h"

namespace Pong
{
    class Textbox
    {
    private:
        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

    public:
        Textbox(const sf::Vector2f& pos = sf::Vector2f(), const sf::Vector2f& size = sf::Vector2f(),
                sf::Font* font = NULL, const std::string& text = "", const unsigned& textSize = 26,
                const sf::Color& color = sf::Color());
        virtual ~Textbox();

        sf::RectangleShape getShape();

        void setText(const std::string& text);
        void setFillColor(const sf::Color& color);

        void render(sf::RenderWindow* window);

    };
}
