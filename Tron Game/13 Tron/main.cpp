#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

#include "game.hpp"

int main()
{
	srand(time(0));
	game G;
	G.setupGame();
	G.startGame();

    return 0;
}
