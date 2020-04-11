#include "Paddle.h"

namespace Pong
{
    Paddle::Paddle()
    {
        this->paddleData = nullptr;

        this->side = PaddlePosition::Null;

        this->windowSize = sf::Vector2f(0.f, 0.f);
        this->shape = sf::RectangleShape();
        this->velocity = 0.f;
    }

	Paddle::Paddle(PaddleData* paddleData, const bool& debugFeatures)
	{
	    this->paddleData = paddleData;

	    this->keybinds = this->paddleData->keybinds;

        this->side = this->paddleData->side;
	    this->windowSize = this->paddleData->windowSize;

		this->shape = sf::RectangleShape(sf::Vector2f(8.f, this->paddleData->paddleHeight));
		this->shape.setOrigin(this->shape.getSize().x / 2, this->paddleData->paddleHeight / 2);

		if (this->side == PaddlePosition::Left)
        {
            this->shape.setPosition(sf::Vector2f(20, this->paddleData->windowSize.y / 2));
        }
        else if (this->side == PaddlePosition::Right)
        {
            this->shape.setPosition(sf::Vector2f(this->paddleData->windowSize.x - 20,
                                                 this->paddleData->windowSize.y / 2));
        }

		this->shape.setFillColor(sf::Color::Black);
		this->shape.setOutlineThickness(2.f);
		this->shape.setOutlineColor(sf::Color::White);

		this->velocity = this->paddleData->velocity;

		//Rainbow mode feature : DEBUG
		this->enable_debug_features = debugFeatures;
		this->rainbow_mode_enabled = false;
		this->debugFeaturesKeyHandler = false;
		this->rainbow_mode = std::vector<sf::Color>{};
		this->rainbow_iterator = 0;
        this->rainbow_mode.push_back(sf::Color::Red);
        this->rainbow_mode.push_back(sf::Color::Green);
        this->rainbow_mode.push_back(sf::Color::Blue);
        this->rainbow_mode.push_back(sf::Color::Yellow);
        this->rainbow_mode.push_back(sf::Color::White);
	}

	Paddle::~Paddle()
	{

	}

	sf::RectangleShape Paddle::getShape()
	{
	    return this->shape;
	}

	sf::Vector2f Paddle::getPosition()
	{
        return this->shape.getPosition();
	}

	sf::Vector2f Paddle::getSize()
	{
	    return this->shape.getSize();
	}

	sf::FloatRect Paddle::getGlobalBounds()
	{
        return this->shape.getGlobalBounds();
	}

	float Paddle::getOutlineThickness()
	{
	    return this->shape.getOutlineThickness();
	}

	bool Paddle::isOutFromUpperBorder()
	{
        if (this->shape.getPosition().y - this->shape.getSize().y / 2 - 2.f < 0)
        {
            return true;
        }
        return false;
	}

	bool Paddle::isOutFromBottomBorder()
	{
        if (this->shape.getPosition().y + this->shape.getSize().y / 2 + 2.f >
            this->windowSize.y)
        {
            return true;
        }
        return false;
	}

	void Paddle::update(const float& dt)
	{
	    //Move paddle
        if (sf::Keyboard::isKeyPressed(this->keybinds[PaddleKeybinds::Up]))
        {
            this->shape.move(sf::Vector2f(0, -this->velocity * dt));
        }
        if (sf::Keyboard::isKeyPressed(this->keybinds[PaddleKeybinds::Down]))
        {
            this->shape.move(sf::Vector2f(0, this->velocity * dt));
        }

        //Check is it out of border and correct it
        if (this->isOutFromUpperBorder())
        {
            float delta = (this->shape.getPosition().y - this->shape.getSize().y / 2 - 2.f);
            this->shape.move(sf::Vector2f(0, -delta));
        }
        if (this->isOutFromBottomBorder())
        {
            float delta = (this->shape.getPosition().y + this->shape.getSize().y / 2 + 2.f) - this->windowSize.y;
            this->shape.move(sf::Vector2f(0, -delta));
        }

        //Rainbow mode : DEBUG
        if (this->enable_debug_features)
        {
            if (sf::Keyboard::isKeyPressed(this->keybinds[PaddleKeybinds::DebugFeatures]))
            {
                if (this->debugFeaturesKeyHandler == false)
                {
                    this->rainbow_mode_enabled = this->rainbow_mode_enabled ? false : true;
                    if (this->rainbow_mode_enabled == false)
                    {
                        this->shape.setOutlineColor(sf::Color::White);
                    }
                    this->debugFeaturesKeyHandler = true;
                }
            }
            else
            {
                this->debugFeaturesKeyHandler = false;
            }

            if (this->rainbow_mode_enabled)
            {
                this->shape.setOutlineColor(this->rainbow_mode[this->rainbow_iterator]);
                if (++this->rainbow_iterator >= this->rainbow_mode.size())
                {
                    this->rainbow_iterator = 0;
                }
            }
        }
	}

	void Paddle::render(sf::RenderTarget* target)
	{
        if (this->side != PaddlePosition::Null)
        {
            target->draw(this->shape);
        }
	}
}
