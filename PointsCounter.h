#ifndef POINTSCOUNTER_H
#define POINTSCOUNTER_H

#include "Button.h"

namespace Pong
{
    class PointsCounter
    {
    private:
        sf::Font font;
        Textbox textbox;

    public:
        PointsCounter();
        PointsCounter(const sf::Vector2f& windowSize);
        virtual ~PointsCounter();

        void render(sf::RenderTarget* target);
    };
}

#endif
