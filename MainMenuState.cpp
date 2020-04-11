#include "MainMenuState.h"

namespace Pong
{
    MainMenuState::MainMenuState(StateData* state_data)
        :State(state_data)
    {
        this->mousePosition = sf::Vector2i(0, 0);

        this->font = new sf::Font();
        this->font->loadFromFile("resources/OpenSans-Bold.ttf");

        ButtonColors temp(sf::Color(40.f, 40.f, 40.f),
                          sf::Color(100.f, 100.f, 100.f),
                          sf::Color(160.f, 160.f, 160.f));

        this->title = Textbox(sf::Vector2f(0, 100),
                              sf::Vector2f(this->stateData->window->getSize().x, 60.f),
                              this->font, "Pong", 100, sf::Color::Black);

        this->buttons["Start"] = new Button(sf::Vector2f(300.f, 180.f),
                                            sf::Vector2f(200.f, 40.f),
                                            this->font, "Start", 26, temp);
        this->buttons["Exit"] = new Button(sf::Vector2f(300.f, 240.f),
                                           sf::Vector2f(200.f, 40.f),
                                           this->font, "Exit", 26, temp);
    }

    MainMenuState::~MainMenuState()
    {
        delete this->font;
        this->font = NULL;

        for (auto& it : this->buttons)
        {
            delete it.second;
            it.second = NULL;
        }

        this->buttons.clear();
    }

    void MainMenuState::update(const float& dt)
    {
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            this->endState();
        }*/

        this->mousePosition = sf::Mouse::getPosition(*this->window);

        //this->buttons["Start"]->update(this->window->mapPixelToCoords(this->mousePosition));
        //this->buttons["Exit"]->update(this->window->mapPixelToCoords(this->mousePosition));

        for (const auto& it : this->buttons)
        {
            it.second->update(this->window->mapPixelToCoords(this->mousePosition));
        }

        if (this->buttons["Start"]->isPressed())
        {
            this->states->push(new GameState(this->stateData));
        }

        if (this->buttons["Exit"]->isPressed())
        {
            this->endState();
        }
    }

    void MainMenuState::render(sf::RenderWindow* window)
    {
        this->title.render(this->stateData->window);
        for (const auto& it : this->buttons)
        {
            it.second->render(this->stateData->window);
        }
    }
}
