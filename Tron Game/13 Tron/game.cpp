#include "game.hpp"

void game::setupGame()
{
    b = new board();
    p1 = new player(Color::Red);
    p2 = new player(Color::Green);
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
    t->clear();  t->draw(sBackground);
}

void game::startGame()
{
    bool Game=1;

    while (window->isOpen())
    {
        Event e;
        while (window->pollEvent(e))
        {
            if (e.type == Event::Closed)
                window->close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1->getDir()!=2) p1->setDir(1);
	    if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1->getDir()!=1)  p1->setDir(2);
	    if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1->getDir()!=0) p1->setDir(3);
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1->getDir()!=3) p1->setDir(0);

		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2->getDir()!=2) p2->setDir(1);
	    if (Keyboard::isKeyPressed(Keyboard::D)) if (p2->getDir()!=1)  p2->setDir(2);
	    if (Keyboard::isKeyPressed(Keyboard::W)) if (p2->getDir()!=0) p2->setDir(3);
		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2->getDir()!=3) p2->setDir(0);

		if (!Game)	continue;

		for(int i=0;i<b->getSpeed();i++)
		{
			p1->tick(); p2->tick();
			if (field[p1->getX()][p1->getY()]==1) Game=0; 
			if (field[p2->getX()][p2->getY()]==1) Game=0;
			field[p1->getX()][p1->getY()]=1; 
			field[p2->getX()][p2->getY()]=1;
	
			CircleShape c(3);
			c.setPosition(p1->getX(),p1->getY()); c.setFillColor(p1->getPColor());	t->draw(c);
			c.setPosition(p2->getX(),p2->getY()); c.setFillColor(p2->getPColor());	t->draw(c);
			t->display();	
		}

	   ////// draw  ///////
		window->clear();
		window->draw(*sprite);
 		window->display();
	}
}