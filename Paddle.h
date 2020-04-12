#ifndef PADDLE_H
#define PADDLE_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <stack>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <map>

namespace Pong
{
	enum PaddlePosition
	{
		Null = 0, Left, Right
	};

	enum PaddleKeybinds
	{
        Up = 0, Down, DebugFeatures
	};

	class PaddleData
	{
    public:
        PaddleData() {};

        std::map<PaddleKeybinds, sf::Keyboard::Key> keybinds;

        PaddlePosition side;
        sf::Vector2f windowSize;
        float paddleHeight;
        float velocity;
	};

	class Paddle
	{
	private:
	    PaddleData* paddleData;

	    std::map<PaddleKeybinds, sf::Keyboard::Key> keybinds;

        PaddlePosition side;
	    sf::Vector2f windowSize;
		sf::RectangleShape shape;
		float velocity;

        //Rainbow mode feature : DEBUG
        bool enable_debug_features;
        bool rainbow_mode_enabled;
        bool debugFeaturesKeyHandler;
        std::vector<sf::Color> rainbow_mode;
        unsigned int rainbow_iterator;

	public:
	    Paddle();
		Paddle(PaddleData* paddleData, const bool& debugFeatures);
		virtual ~Paddle();

		sf::RectangleShape getShape();
		sf::Vector2f getPosition();
		sf::Vector2f getSize();
		sf::FloatRect getGlobalBounds();
		float getOutlineThickness();

		bool isOutFromUpperBorder();
		bool isOutFromBottomBorder();

		void update(const float& dt);
		void render(sf::RenderTarget* target);
	};
}

#endif
