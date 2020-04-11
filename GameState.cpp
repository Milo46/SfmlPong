#include "GameState.h"

namespace Pong
{
    GameState::GameState(StateData* state_data)
        :State(state_data)
    {
        this->left_paddleData = PaddleData();
        this->left_paddleData.windowSize = static_cast<sf::Vector2f>(this->stateData->window->getSize());
        this->left_paddleData.paddleHeight = 40.f;
        this->left_paddleData.velocity = 1000.f;
        this->left_paddleData.side = PaddlePosition::Left;
        std::map<PaddleKeybinds, sf::Keyboard::Key> left_keybinds;
        left_keybinds[PaddleKeybinds::Up] = sf::Keyboard::Q;
        left_keybinds[PaddleKeybinds::Down] = sf::Keyboard::A;
        left_keybinds[PaddleKeybinds::DebugFeatures] = sf::Keyboard::Z;
        this->left_paddleData.keybinds = left_keybinds;

        this->right_paddleData = PaddleData();
        this->right_paddleData.windowSize = static_cast<sf::Vector2f>(this->stateData->window->getSize());
        this->right_paddleData.paddleHeight = 40.f;
        this->right_paddleData.velocity = 1000.f;
        this->right_paddleData.side = PaddlePosition::Right;
        std::map<PaddleKeybinds, sf::Keyboard::Key> right_keybinds;
        right_keybinds[PaddleKeybinds::Up] = sf::Keyboard::Up;
        right_keybinds[PaddleKeybinds::Down] = sf::Keyboard::Down;
        right_keybinds[PaddleKeybinds::DebugFeatures] = sf::Keyboard::Unknown;
        this->right_paddleData.keybinds = right_keybinds;

        this->left_paddle = Paddle(&this->left_paddleData, true);
        this->right_paddle = Paddle(&this->right_paddleData, false);

        this->ballData = BallData();
        this->ballData.sideSize = 4.f;
        this->ballData.velocity = 500.f;
        this->ballData.maxBounceAngle = (50 * pi) / 180;
        this->ballData.windowSize = static_cast<sf::Vector2f>(this->stateData->window->getSize());
        this->ballData.targetTimerTime = 2.f;

        this->ball = Ball(&this->ballData);
    }

    GameState::~GameState()
    {

    }

    void GameState::update(const float& dt)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            this->endState();
        }
        this->left_paddle.update(dt);
        this->right_paddle.update(dt);
        this->ball.update(dt, this->left_paddle, this->right_paddle);
    }

    void GameState::render(sf::RenderWindow* window)
    {
        this->left_paddle.render(this->stateData->window);
        this->right_paddle.render(this->stateData->window);
        this->ball.render(this->stateData->window);
    }
}
