#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
private:
    sf::Vector2f _direction;
    float _moveSpeed;

    std::vector<sf::RectangleShape> _body;

    void initInputs();
    void reposition();
    
    void moveBody(float& dt);

public:
    Player();
    virtual ~Player();

    void update();
    void fixedUpdate(float& dt);
    void render(sf::RenderWindow* window);

    void addBody();

    sf::RectangleShape getSprite() { return _body[0]; }
};
