#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "board.hpp"
#include "player.hpp"
#include "eventFramework.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class game
{
private:
    board *b;
    player *p1, *p2;
    RenderWindow *window;
    Sprite *sprite;
    RenderTexture *t;
    Color colorList [4] = {Color::Red,Color::Blue,Color::Green,Color::Yellow};

    eventFramework *eventF;

    void drawFrame();
public:
    void setupGame();
    void startGame();

};

#endif
