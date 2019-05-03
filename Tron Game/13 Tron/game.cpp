#include "game.hpp"

void game::setupGame()
{
    int p1c = rand()%4;
    int p2c = rand()%4;
    while(p1c == p2c)
    {
        p2c = rand()%4;
    }
    b = new board();
    p1 = new player(colorList[p1c],b->getBoardWidth(),b->getBoardHeight());
    p2 = new player(colorList[p2c],b->getBoardWidth(),b->getBoardHeight());
    p1->setBoardWidth(b->getBoardWidth());
    p2->setBoardWidth(b->getBoardWidth());
    p1->setBoardHeight(b->getBoardHeight());
    p2->setBoardHeight(b->getBoardHeight());

    window = new RenderWindow (VideoMode(b->getBoardWidth(), b->getBoardHeight()), "The Tron Game!");
    window->setFramerateLimit(60);

    Texture texture;
    texture.loadFromFile("background.jpg");
    Sprite sBackground(texture);

    sprite = new Sprite;
    t = new RenderTexture;
    t->create(b->getBoardWidth(), b->getBoardHeight());
    t->setSmooth(true);
    sprite->setTexture(t->getTexture());
    t->clear();
    t->draw(sBackground);
    eventF = new eventFramework();
}

void game::startGame()
{
    eventF->startGame();
    int key;
    while (eventF->pollWindow(window))
    {
        while(eventF->isRunning())
        {
            eventF->pollWindow(window);
            if(eventF->isKeyPressed())
            {
                key = eventF->getKey();

                if (key == Keyboard::Left) if (p1->getDir()!=2) p1->setDir(1);
                if (key == Keyboard::Right) if (p1->getDir()!=1)  p1->setDir(2);
                if (key == Keyboard::Up) if (p1->getDir()!=0) p1->setDir(3);
                if (key == Keyboard::Down) if (p1->getDir()!=3) p1->setDir(0);
                if (key == Keyboard::Numpad0) if (p1->getJump()!=true) p1->PJump();

                if (key == Keyboard::A) if (p2->getDir()!=2) p2->setDir(1);
                if (key == Keyboard::D) if (p2->getDir()!=1)  p2->setDir(2);
                if (key == Keyboard::W) if (p2->getDir()!=0) p2->setDir(3);
                if (key == Keyboard::S) if (p2->getDir()!=3) p2->setDir(0);
                if (key == Keyboard::Space) if (p2->getJump()!=true) p2->PJump();

            }
            drawFrame();
        }

    }
}

void game::drawFrame()
{
    for(int i=0; i<b->getSpeed(); i++)
    {
        p1->tick();
        p2->tick();
        if(p1->getJump() != true)
        {
            if (b->checkFieldPosition(p1->getX(), p1->getY())) eventF->endGame();

            b->setFieldPosition(p1->getX(),p1->getY(),1);
        }
        if(p2->getJump() != true)
        {
            if (b->checkFieldPosition(p2->getX(), p2->getY())) eventF->endGame();
            b->setFieldPosition(p2->getX(),p2->getY(),1);
        }

        CircleShape c(3);
        if(p1->getJump() != true)
        {
            c.setPosition(p1->getX(),p1->getY());
            c.setFillColor(p1->getPColor());
            t->draw(c);
            t->display();
        }
        if(p2->getJump() != true)
        {
            c.setPosition(p2->getX(),p2->getY());
            c.setFillColor(p2->getPColor());
            t->draw(c);
            t->display();
        }
    }

    ////// draw  ///////
    window->clear();
    window->draw(*sprite);
    window->display();
}

