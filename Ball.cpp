#include "Ball.h"

namespace Pong
{
    Ball::Ball()
    {
        this->ballData = nullptr;
        this->velocity = 0.f;
    }

    Ball::Ball(BallData* ballData)
    {
        this->ballData = ballData;

        this->windowSize = this->ballData->windowSize;

        this->velocity = this->ballData->velocity;
        this->shape = sf::RectangleShape(sf::Vector2f(this->ballData->sideSize, this->ballData->sideSize));
        this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
        this->shape.setPosition(sf::Vector2f(this->windowSize.x / 2, this->windowSize.y / 2));
        this->shape.setOutlineThickness(2.f);
        this->shape.setOutlineColor(sf::Color::White);
        this->shape.setFillColor(sf::Color::Black);

        srand(time(NULL));
        this->angle = (rand() % 360) * 2 * pi / 360;
        while (this->angle > 0.7f /*||  this->angle < 0.2f*/)
        {
            this->angle = (rand() % 360) * 2 * pi /360;
        }
        this->mltX = rand() % 2 == 0 ? 1 : -1;
        this->mltY = rand() % 2 == 0 ? 1 : -1;

        this->maxBounceAngle = this->ballData->maxBounceAngle;

        this->setup = true;
        this->timer = Timer(this->ballData->targetTimerTime);

        this->pointsCounter = PointsCounter();
        this->pointsCounter.render();
    }

    Ball::~Ball()
    {

    }

    sf::FloatRect Ball::getGlobalBounds()
    {
        return this->shape.getGlobalBounds();
    }

    void Ball::reset()
    {
        this->shape.setPosition(sf::Vector2f(this->windowSize.x / 2, this->windowSize.y / 2));
        this->angle = (rand() % 360) * 2 * pi / 360;
        while (this->angle > 0.7f /*|| this->angle < 0.2f*/)
        {
            this->angle = (rand() % 360) * 2 * pi /360;
        }
        this->mltX = rand() % 2 == 0 ? 1 : -1;
        this->mltY = rand() % 2 == 0 ? 1 : -1;
    }

    bool Ball::isOutFromUpperBorder()
    {
        if (this->shape.getPosition().y - this->shape.getSize().y / 2 - this->shape.getOutlineThickness() < 0)
        {
            return true;
        }
        return false;
    }

    bool Ball::isOutFromBottomBorder()
    {
        if (this->shape.getPosition().y + this->shape.getSize().y / 2 + this->shape.getOutlineThickness() > this->windowSize.y)
        {
            return true;
        }
        return false;
    }

    void Ball::update(const float& dt, Paddle& left, Paddle& right)
    {
        if (this->timer.status() == TimerStatus::Off)
        {
            float factor = this->velocity * dt;
            this->shape.move(sf::Vector2f(cos(this->angle) * factor * this->mltX, sin(this->angle) * factor * this->mltY));

            if (this->shape.getPosition().x <= left.getPosition().x - left.getSize().x / 2)
            {
                this->reset();
                this->setup = true;

                this->pointsCounter.incrementRight();
                this->pointsCounter.render();
            }

            if (this->shape.getPosition().x >= right.getPosition().x + right.getSize().x / 2)
            {
                this->reset();
                this->setup = true;

                this->pointsCounter.incrementLeft();
                this->pointsCounter.render();
            }

            if (this->isOutFromUpperBorder())
            {
                this->mltY *= -1;
                this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, this->shape.getSize().x / 2 + this->shape.getOutlineThickness() + 0.1f));
            }
            if (this->isOutFromBottomBorder())
            {
                this->mltY *= -1;
                this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, this->windowSize.y - this->shape.getSize().x / 2 - this->shape.getOutlineThickness() - 0.1f));
            }

            if (this->shape.getGlobalBounds().intersects(left.getGlobalBounds()))
            {
                this->mltX *= -1;

                float relativeIntersect = left.getPosition().y - this->shape.getPosition().y;
                float normalizedRelativeIntersect = relativeIntersect / (left.getSize().y / 2);

                if (normalizedRelativeIntersect > 1) normalizedRelativeIntersect = 1;
                else if (normalizedRelativeIntersect < -1) normalizedRelativeIntersect = -1;

                if (normalizedRelativeIntersect > 0)
                {
                    this->mltY = -1;
                    normalizedRelativeIntersect = std::abs(normalizedRelativeIntersect);
                }
                else if (normalizedRelativeIntersect < 0)
                {
                    this->mltY = 1;
                    normalizedRelativeIntersect = std::abs(normalizedRelativeIntersect);
                }

                this->angle = this->maxBounceAngle * normalizedRelativeIntersect;

                this->shape.setPosition(sf::Vector2f(left.getPosition().x + left.getSize().x / 2 + left.getOutlineThickness() + this->shape.getOutlineThickness() + this->shape.getSize().x / 2 + 1.f, this->shape.getPosition().y));
            }
            if (this->getGlobalBounds().intersects(right.getGlobalBounds()))
            {
                this->mltX *= -1;

                float relativeIntersect = right.getPosition().y - this->shape.getPosition().y;
                float normalizedRelativeIntersect = relativeIntersect / (right.getSize().y / 2);

                if (normalizedRelativeIntersect > 1) normalizedRelativeIntersect = 1;
                else if (normalizedRelativeIntersect < -1) normalizedRelativeIntersect = -1;

                if (normalizedRelativeIntersect > 0)
                {
                    this->mltY = -1;
                    normalizedRelativeIntersect = std::abs(normalizedRelativeIntersect);
                }
                else if (normalizedRelativeIntersect < 0)
                {
                    this->mltY = 1;
                    normalizedRelativeIntersect = std::abs(normalizedRelativeIntersect);
                }

                this->angle = this->maxBounceAngle * normalizedRelativeIntersect;

                this->shape.setPosition(sf::Vector2f(right.getPosition().x - right.getSize().x / 2 - right.getOutlineThickness() - this->shape.getOutlineThickness() - this->shape.getSize().x / 2 - 1.f, this->shape.getPosition().y));
            }
        }
        else
        {
            this->timer.update(dt);
        }

        if (this->setup == true)
        {
            this->timer.start();
            this->setup = false;
        }
    }

    void Ball::render(sf::RenderTarget* target)
    {
        target->draw(this->shape);
    }
}
