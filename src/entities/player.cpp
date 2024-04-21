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
    for (auto &&body : _body)
    {
        if ((body.getPosition().x + (body.getScale().x / 2)) <= 0.f) body.setPosition(sf::Vector2f(800.f, body.getPosition().y));
        else if ((body.getPosition().x - (body.getScale().x / 2)) >= 800.f) body.setPosition(sf::Vector2f(0.f, body.getPosition().y));
        else if ((body.getPosition().y + (body.getScale().y / 2)) <= 0.f) body.setPosition(sf::Vector2f(body.getPosition().x, 600.f));
        else if ((body.getPosition().y - (body.getScale().y / 2)) >= 600.f) body.setPosition(sf::Vector2f(body.getPosition().x, 0.f));
    }
}

void Player::moveBody(float& dt)
{
    _moveTime += dt;
    if (_moveTime < .1f) return;

    for (size_t i = _body.size() - 1; i > 0; --i)
    {
        sf::Vector2f position = _body[i - 1].getPosition();
        sf::Vector2f size = _body[i - 1].getScale();
        _body[i].setPosition(position.x - (size.x * _direction.x), position.y - (size.y * _direction.y));
        _moveTime = 0.f;
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
    addBody();
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
    for (auto &&body : _body) window->draw(body);
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
