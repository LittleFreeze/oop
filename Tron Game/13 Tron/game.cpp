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
    
    RenderWindow window(VideoMode(W, H), "The Tron Game!");
    window.setFramerateLimit(60);

	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sBackground(texture);

    

	Sprite sprite;
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
    t.clear();  t.draw(sBackground);
}

void game::startGame()
{
    bool Game=1;

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir!=2) p1.dir=1;
	    if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir!=1)  p1.dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir!=0) p1.dir=3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir!=3) p1.dir=0;

		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir!=2) p2.dir=1;
	    if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir!=1)  p2.dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir!=0) p2.dir=3;
		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir!=3) p2.dir=0;

		if (!Game)	continue;

		for(int i=0;i<speed;i++)
		{
			p1.tick(); p2.tick();
			if (field[p1.x][p1.y]==1) Game=0; 
			if (field[p2.x][p2.y]==1) Game=0;
			field[p1.x][p1.y]=1; 
			field[p2.x][p2.y]=1;
	
			CircleShape c(3);
			c.setPosition(p1.x,p1.y); c.setFillColor(p1.color);	t.draw(c);
			c.setPosition(p2.x,p2.y); c.setFillColor(p2.color);	t.draw(c);
			t.display();	
		}

	   ////// draw  ///////
		window.clear();
		window.draw(sprite);
 		window.display();
	}
}