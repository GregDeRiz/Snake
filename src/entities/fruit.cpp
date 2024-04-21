#include "fruit.h"

Fruit::Fruit(sf::Vector2f position) 
{
    _sprite = sf::CircleShape(15.f);
    _sprite.setOrigin(sf::Vector2f(7.5f, 7.5f));
    _sprite.setFillColor(sf::Color::Red);
    _sprite.setPosition(position);
}

void Fruit::render(sf::RenderWindow* window)
{
    window->draw(_sprite);
}
