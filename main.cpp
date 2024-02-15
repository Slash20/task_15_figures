#include <SFML/Graphics.hpp>
#include <Game.hpp>


int main()
{
    mt::Game game(1500, 1000, "Game");

    game.Setup(10);

    game.LifeCycle();

    return 0;
}