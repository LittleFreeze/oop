#ifndef WAR_HPP_INCLUDED
#define WAR_HPP_INCLUDED

#include "deck.hpp"

class War
{
private:
    int playerWins;
    int computerWins;
    int roundCount;
    Deck pdeck;
    Deck pStoreDeck;
    Deck cdeck;
    Deck cStoreDeck;
    Deck tempDeck;
    Deck deck;

    struct Card
    {
        char RAndS;
        Card* nextCard;
    };

public:
    War()
    {
        playerWins = 0;
        computerWins = 0;
        roundCount = 500;
    };
    void setupWar();
    void playerWin();
    void computerWin();
    void draw();
    void runWar();
    void declareWinner();
};

#endif