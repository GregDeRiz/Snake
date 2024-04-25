#include "player.h"

void Player::moveBody()
{
    for (size_t i = _body.size() - 1; i > 0; --i)
    {
        _body[i].setPosition(_body[i - 1].getPosition());
    }
}

Player::Player()
{
    sf::CircleShape head = sf::CircleShape(15.f);
    head.setOrigin(sf::Vector2f(7.5f, 7.5f));
    head.setPosition(sf::Vector2f(400.f, 300.f));
    head.setFillColor(sf::Color::Green);

    _moveSpeed = 150.f;
    _body.push_back(head);

    for (size_t i = 0; i < 20; i++) addBody();
}

Player::~Player()
{
    _body.clear();
}

void Player::update()
{
    for (auto &&body : _body)
    {
        if ((body.getPosition().x + (body.getScale().x / 2)) <= 0.f) body.setPosition(sf::Vector2f(800.f, body.getPosition().y));
        else if ((body.getPosition().x - (body.getScale().x / 2)) >= 800.f) body.setPosition(sf::Vector2f(0.f, body.getPosition().y));
        else if ((body.getPosition().y + (body.getScale().y / 2)) <= 0.f) body.setPosition(sf::Vector2f(body.getPosition().x, 600.f));
        else if ((body.getPosition().y - (body.getScale().y / 2)) >= 600.f) body.setPosition(sf::Vector2f(body.getPosition().x, 0.f));
    }
}

void Player::fixedUpdate(float& dt)
{
    _body[0].move(_direction * dt * _moveSpeed);
    moveBody();
}

void Player::render(sf::RenderWindow* window)
{
    for (auto &&body : _body) window->draw(body);
}

void Player::updateInput(Direction direction)
{
    switch (direction)
    {
    case RIGHT:
        _direction = sf::Vector2f(1.f, 0.f);
        break;
    
    case LEFT:
        _direction = sf::Vector2f(-1.f, 0.f);
        break;

    case DOWN:
        _direction = sf::Vector2f(0.f, 1.f);
        break;

    case UP:
        _direction = sf::Vector2f(0.f, -1.f);
        break;

    case NONE:
        _direction = sf::Vector2f(-1.f, 0.f);
        break;
    } 
}

void Player::addBody()
{
    sf::CircleShape body = sf::CircleShape(15.f);
    body.setOrigin(sf::Vector2f(7.5f, 7.5f));

    sf::Vector2f position = _body[_body.size() - 1].getPosition();
    sf::Vector2f size = _body[_body.size() - 1].getScale();

    body.setPosition(position.x - (size.x * _direction.x), position.y - (size.y * _direction.y));
    body.setFillColor(sf::Color::Green);
    _body.push_back(body);
}
