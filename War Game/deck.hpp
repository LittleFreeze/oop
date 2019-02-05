#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <cstdlib>
#include <iostream>


enum Suit
{
    Hearts,
    Clubs,
    Spades,
    Diamonds
};

enum Rank
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

class Deck
{
private:
    struct Card
    {
        Rank r;
        Suit s;
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
    Rank IntToRank(int);
    Suit IntToSuit(int);
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
        std::cout << TopCard;

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