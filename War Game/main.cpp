#include <cstdlib>
#include <time.h>
#include <iostream>

#include "deck.hpp"

int main(void)
{
    srand(time(0));
    Deck deck;
    deck.GenerateDeck();

    Deck pdeck;
    Deck pStoreDeck;
    Deck cdeck;
    Deck cStoreDeck;
    Deck tempDeck;

    struct Card
    {
        Rank r;
        Suit s;
        Card* nextCard;
    };

    Card c;

    for(int i = 0; i < 52; i++)
    {
        if(i % 2 == 1)
        {
            pdeck.addBottom(deck.pullTop());
        }
        else
        {
            cdeck.addBottom(deck.pullTop());
        }
    }
    std::cout << "PDeck Top: " << pdeck.readTop().r;
    Card pCard;
    Card cCard;

    while(pdeck.getCount() != 0 && cdeck.getCount() != 0)
    {
        std::cout << pdeck.readTop().r << std::endl;
        std::cout << cdeck.readTop().r << std::endl;

        if(pdeck.readTop().r > cdeck.readTop().r)
        {
            std::cout << "Player wins" << std::endl;
            pStoreDeck.addBottom(pdeck.pullTop());
            pStoreDeck.addBottom(cdeck.pullTop());
        }
        else if(pdeck.readTop().r < cdeck.readTop().r)
        {
            std::cout << "Computer wins" << std::endl;
            cStoreDeck.addBottom(pdeck.pullTop());
            cStoreDeck.addBottom(cdeck.pullTop());
        }
        else
        {
            std::cout << "Draw" << std::endl;
            tempDeck.addBottom(pdeck.pullTop());
            tempDeck.addBottom(cdeck.pullTop());
        }
        
    }

    return 0;
}