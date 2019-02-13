#include "deck.hpp"

class War
{
private:
    int playerWins;
    int computerWins;
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
    };
    void setupWar();
}