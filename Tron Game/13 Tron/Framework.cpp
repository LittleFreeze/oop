#include "Framework.hpp"

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
        keyPressed = false;
        switch(event.type)
        {
        case Event::Closed:
            endGame();
            window->close();
            return false;
        case Event::KeyPressed:
            keyPressed = true;
            break;
        }
    }
    return true;
}
