#include "fruit.h"

Fruit::Fruit(sf::Vector2f position) 
{
    _sprite = sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    _sprite.setOrigin(sf::Vector2f(15.f, 15.f));
    _sprite.setFillColor(sf::Color::Red);
    _sprite.setPosition(position);
}

void Fruit::render(sf::RenderWindow* window)
{
    window->draw(_sprite);
}
