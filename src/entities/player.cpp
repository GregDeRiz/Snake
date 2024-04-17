#include "player.h"

void Player::initInputs() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) _direction = sf::Vector2f(1.f, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) _direction = sf::Vector2f(-1.f, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) _direction = sf::Vector2f(0.f, 1.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) _direction = sf::Vector2f(0.f, -1.f);
}

void Player::reposition()
{
    if ((_body[0].getPosition().x + (_body[0].getSize().x / 2)) <= 0.f) _body[0].setPosition(sf::Vector2f(800.f, _body[0].getPosition().y));
    else if ((_body[0].getPosition().x - (_body[0].getSize().x / 2)) >= 800.f) _body[0].setPosition(sf::Vector2f(0.f, _body[0].getPosition().y));
    else if ((_body[0].getPosition().y + (_body[0].getSize().y / 2)) <= 0.f) _body[0].setPosition(sf::Vector2f(_body[0].getPosition().x, 600.f));
    else if ((_body[0].getPosition().y - (_body[0].getSize().y / 2)) >= 600.f) _body[0].setPosition(sf::Vector2f(_body[0].getPosition().x, 0.f));
}

void Player::moveBody(float& dt)
{
    sf::Vector2f direction;
    sf::Vector2f position;

    for (size_t i = 1; i < _body.size(); i++)
    {
        if (direction.x != _direction.x) 
        {
            position = sf::Vector2f((_body[i - 1].getPosition().x - _body[i - 1].getSize().x) * _direction.x, 0.f);
            direction.x = _direction.x;
        } 
        else if (direction.y != _direction.y)
        {
            position = sf::Vector2f(0.f, (_body[i - 1].getPosition().y - _body[i - 1].getSize().y) * _direction.y);
            direction.y = _direction.y;
        }

        _body[i].move(position * dt);
    }
}

Player::Player()
{
    sf::RectangleShape head = sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    head.setOrigin(sf::Vector2f(15.f, 15.f));
    head.setPosition(sf::Vector2f(400.f, 300.f));
    head.setFillColor(sf::Color::Green);

    _moveSpeed = 100.f;
    _direction = sf::Vector2f();
    _body.push_back(head);
}

Player::~Player()
{
    _body.clear();
}

void Player::update()
{
    initInputs();
    reposition();
}

void Player::fixedUpdate(float& dt)
{
    _body[0].move(_direction * dt * _moveSpeed);
    moveBody(dt);
}

void Player::render(sf::RenderWindow* window)
{
    for (sf::RectangleShape body : _body) window->draw(body);
}

void Player::addBody()
{
    sf::RectangleShape body = sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    body.setOrigin(sf::Vector2f(15.f, 15.f));
    body.setPosition(_body[_body.size() - 1].getPosition());
    body.setFillColor(sf::Color::Green);
    _body.push_back(body);
}
