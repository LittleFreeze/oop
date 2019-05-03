#include "eventFramework.hpp"

bool eventFramework::isRunning()
{
    return running;
}

bool eventFramework::isKeyPressed()
{
    return keyPressed;
}

void eventFramework::startGame()
{
    running = true;
}

void eventFramework::endGame()
{
    running = false;
}

bool eventFramework::pollWindow(RenderWindow *window)
{
    while(window->pollEvent(event))
    {

        switch(event.type)
        {
        case Event::Closed:
            endGame();
            window->close();
            return false;
        case Event::KeyReleased:
        case Event::KeyPressed:
            keyPressed = true;
            key = event.key.code;
            break;
        }
    }
    return true;
}

int eventFramework::getKey()
{
    keyPressed = false;
    return key;
}
