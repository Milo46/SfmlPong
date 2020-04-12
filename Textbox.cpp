#include "Textbox.h"

namespace Pong
{
    Textbox::Textbox(const sf::Vector2f& position, const sf::Vector2f& size, sf::Font* font, const std::string& text, const unsigned& textSize, const sf::Color& color)
    {
        this->shape = sf::RectangleShape(size);
        this->shape.setPosition(position);
        this->shape.setFillColor(sf::Color(color.r, color.g, color.b, 0));

        this->font = font;
        this->text.setFont(*this->font);
        this->text.setFillColor(sf::Color(255, 255, 255));

        this->text.setCharacterSize(textSize);
        this->text.setScale(sf::Vector2f(0.5f, 0.5f));

        this->setText(text);
    }

    Textbox::~Textbox()
    {

    }

    sf::RectangleShape Textbox::getShape()
    {
        return this->shape;
    }

    void Textbox::setText(const std::string& text)
    {
        this->text.setString(text);

        this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
        );
    }

    void Textbox::setFillColor(const sf::Color& color)
    {
        this->shape.setFillColor(color);
    }

    void Textbox::render(sf::RenderTarget* target)
    {
        target->draw(this->shape);
        target->draw(this->text);
    }
}
