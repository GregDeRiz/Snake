#include "game.h"

void Game::registerEvents()
{
    if (!_window->pollEvent(_event)) return;
    
    switch (_event.type)
    {
    case sf::Event::Closed:
        _window->close();
        break;
    }
}

void Game::spawnFruit()
{
    for (size_t i = 0; i < _fruits.size(); i++)
    {
        if (_fruits[i].wasEated(_player)) 
        {
            _fruits.erase(_fruits.begin() + i);
            _fruits.push_back(Fruit(sf::Vector2f(rand() % 600, rand() % 400)));
            _player.addBody();
        }
    }
}

void Game::registerInput() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) _direction = RIGHT;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) _direction = LEFT;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) _direction = DOWN;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) _direction = UP;
}

Game::Game()
{
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Snake");
    _window->setVerticalSyncEnabled(true);

    _player = Player();
    _fruits.push_back(Fruit(sf::Vector2f(rand() % 700, rand() % 500)));
    _direction = NONE;
}

Game::~Game()
{
    _fruits.clear();
    delete _window;
}

void Game::update()
{
    registerEvents();
    registerInput();

    _player.updateInput(_direction);
    _player.update();
    spawnFruit();
}

void Game::fixedUpdate(float dt)
{
    _player.fixedUpdate(dt);
}

void Game::render()
{
    _window->clear(sf::Color::Black);

    // render
    for (Fruit fruit : _fruits) fruit.render(_window);
    _player.render(_window);

    _window->display();
}
