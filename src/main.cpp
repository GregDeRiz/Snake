#include "game.h"

int main()
{
    sf::Clock clock = sf::Clock();
    Game game = Game();

    while (game.isGameOpen())
    {
        game.update();
        game.fixedUpdate(clock.restart().asSeconds());
        game.render();
    }

    return 0;
}
