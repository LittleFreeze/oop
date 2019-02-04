#include "deck.hpp"

Rank Deck::IntToRank(int i)
{
    switch(i)
    {
        case 0 : return Ace;
            break;
        case 1 : return Two;
            break;
        case 2 : return Three;
            break;
        case 3 : return Four;
            break;
        case 4 : return Five;
            break;
        case 5 : return Six;
            break;
        case 6 : return Seven;
            break;
        case 7 : return Eight;
            break;
        case 8 : return Nine;
            break;
        case 9 : return Ten;
            break;
        case 10 : return Jack;
            break;
        case 11 : return Queen;
            break;
        case 12 : return King;
            break;
    }
}

Suit Deck::IntToSuit(int i)
{
    switch(i)
    {
        case 0 : return Hearts;
            break;
        case 1 : return Clubs;
            break;
        case 2 : return Spades;
            break;
        case 3 : return Diamonds;
            break;
    }
}

void Deck::pushTop(int r, int s)
{
    Card *newCard;
    newCard = new Card;
    newCard->r = IntToRank(r);
    newCard->s = IntToSuit(s);
    newCard->nextCard = TopCard;
    TopCard = newCard;
}

void Deck::addBottom(int r, int s)
{
    Card *newCard;
    newCard = new Card;
    newCard->r = IntToRank(r);
    newCard->s = IntToSuit(s);
    newCard->nextCard = nullptr;
    if(!TopCard)
    {
        TopCard = newCard;
    }
    
}