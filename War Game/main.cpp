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
    Deck cdeck;

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
        std::cout << "here";
    }
    std::cout << "HERE";
    return 0;
}