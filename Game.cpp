#include "Game.h"

namespace Pong
{
    void Game::update()
    {
        this->updateSFMLEvents();

        if (!this->states.empty())
        {
            if (this->window->hasFocus())
            {
                this->states.top()->update(this->dt);

                if (this->states.top()->getQuit())
                {
                    this->states.top()->endState();
                    delete this->states.top();
                    this->states.top() = NULL;
                    this->states.pop();
                }
            }
        }
        else
        {
            this->endGame();
            this->window->close();
        }
    }

    void Game::updateDt()
    {
        this->dt = this->dtClock.restart().asSeconds();
    }

    void Game::updateSFMLEvents()
    {
        while (this->window->pollEvent(this->sfEvent))
        {
            if (this->sfEvent.type == sf::Event::Closed)
            {
                this->window->close();
            }
        }
    }

    void Game::render()
    {
        this->window->clear();

        if (!this->states.empty())
        {
            this->states.top()->render();
        }

        this->window->display();
    }

    void Game::endGame()
    {
        std::cout << "End of game" << std::endl;
    }

    Game::Game()
    {
        this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML Pong");
        this->window->setKeyRepeatEnabled(false);

        this->stateData.window = this->window;
        this->stateData.states = &this->states;

        this->states.push(new MainMenuState(&this->stateData));

        this->dt = 0.f;
    }

    Game::~Game()
    {
        delete this->window;
        this->window = NULL;

        while (!this->states.empty())
        {
            delete this->states.top();
            this->states.top() = NULL;
            this->states.pop();
        }
    }

    void Game::run()
    {
        while (this->window->isOpen())
        {
            this->updateDt();
            this->update();
            this->render();
        }
    }
}
