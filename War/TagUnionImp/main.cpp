#include <cstdlib>
#include <time.h>
#include <iostream>

#include "deck.hpp"
#include "war.hpp"

int main(void)
{
    srand(time(0)); //Seed Random
/*
    War w; //Create War Class
    w.setupWar(); //Run a function to setup the game
    w.runWar(); //Run a function to start the game
    w.declareWinner(); //Run a function to declare the winner of the game
*/

    Deck d;
    d.GenerateDeckWithJokers();
    //d.GenerateDeck();
    d.printDeck();

    std::cout << "Main Complete";
    
    return 0;
}