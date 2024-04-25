#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "entities/player.h"
#include "entities/fruit.h"
#include "inputs/direction.h"

class Game
{
private:
    sf::RenderWindow* _window;
    sf::Event _event;
    
    Player _player;
    std::vector<Fruit> _fruits;
    Direction _direction;

    void registerEvents();
    void spawnFruit();
    void registerInput();

public:
    Game();
    virtual ~Game();

    void update();
    void fixedUpdate(float dt);
    void render();

    const bool isGameOpen() { return _window->isOpen(); }
};
