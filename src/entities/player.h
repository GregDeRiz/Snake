#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
private:
    sf::Vector2f _direction;
    float _moveSpeed;

    std::vector<sf::CircleShape> _body;
    float _moveTime;

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

    sf::CircleShape getSprite() { return _body[0]; }
};
