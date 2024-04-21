#pragma once

#include <SFML/Graphics.hpp>

#include "player.h"

class Fruit
{
private:
    sf::CircleShape _sprite;

public:
    Fruit(sf::Vector2f position);

    void render(sf::RenderWindow* window);

    bool wasEated(Player& player) { return _sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()); }
    sf::CircleShape getSprite() { return _sprite; }
};
