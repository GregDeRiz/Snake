#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../inputs/direction.h"

class Player
{
private:
    sf::Vector2f _direction;
    float _moveSpeed;

    std::vector<sf::CircleShape> _body;

    void moveBody();

public:
    Player();
    virtual ~Player();

    void update();
    void fixedUpdate(float& dt);
    void render(sf::RenderWindow* window);

    void updateInput(Direction direction);
    void addBody();

    sf::CircleShape getSprite() { return _body[0]; }
};
