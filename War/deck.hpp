#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <cstdlib>
#include <iostream>

class Deck
{
private:
    struct Card
    {
        char RAndS;
        Card* nextCard;
    };

    Card* TopCard;
    int count;

public:
    Deck()
    {
        TopCard = nullptr;
        count = 0;
    }
    int getRank(char);
    int getSuit(char);
    char intsToSAndR(int, int);
    void pushTop(int, int);
    void addBottom(Card);
    Card pullTop();
    Card removeCard(int, Card*);
    void GenerateDeck();
    void ShuffleDeck();
    int getCount();
    Card* readTop();
    ~Deck()
    {
        Card *cardPtr;
        Card *nextCardPtr;

        cardPtr = TopCard;
        //std::cout << TopCard;

        while(count > 0)
        {
            nextCardPtr = cardPtr->nextCard;
            delete cardPtr;
            cardPtr = nextCardPtr;
            count--;
        }
    }
};

#endif