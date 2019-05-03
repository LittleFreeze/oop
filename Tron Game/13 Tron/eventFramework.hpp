#ifndef EVENTFRAMEWORK_HPP_INCLUDED
#define EVENTFRAMEWORK_HPP_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;

class eventFramework
{
private:
    bool running = false;
    bool keyPressed = false;
    Event event;

    int key;

public:
    bool isRunning();
    bool isKeyPressed();
    void startGame();
    void endGame();
    bool pollWindow(RenderWindow *window);
    int getKey();
};

#endif // EVENTFRAMEWORK_HPP_INCLUDED
