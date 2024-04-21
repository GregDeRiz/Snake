#include "game.h"

int main()
{
    sf::Clock clock;
    Game game;

    while (game.isGameOpen())
    {
        game.update();
        game.fixedUpdate(clock.restart().asSeconds());
        game.render();
    }

    return 0;
}
