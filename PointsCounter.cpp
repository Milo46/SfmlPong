#include "PointsCounter.h"

namespace Pong
{
    PointsCounter::PointsCounter()
    {
        this->font = sf::Font();
        this->textbox = Textbox();
    }

    PointsCounter::PointsCounter(const sf::Vector2f& windowSize)
    {
        this->font = sf::Font();
        this->font.loadFromFile("resources/OpenSans-Bold.ttf");
        this->textbox = Textbox(sf::Vector2f(0, 0), sf::Vector2f(windowSize.x, 100),
                                &this->font, "Example", 40, sf::Color::Black);
    }

    PointsCounter::~PointsCounter()
    {

    }

    void PointsCounter::render(sf::RenderTarget* target)
    {
        this->textbox.render(target);
    }
}
