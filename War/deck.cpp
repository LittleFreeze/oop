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
    count++;
    //std::cout << "pushing: " << r << " " << s << std::endl;
}

void Deck::addBottom(Card c)
{
    Card *cardPtr;
    Card *newCard;  // = & c;
    newCard = new Card;
    newCard->r = IntToRank(c.r);
    newCard->s = IntToSuit(c.s);
    newCard->nextCard = nullptr;
    
    if(!TopCard || count == 0)
    {
        //std::cout << "Here" << std::endl;
        //std::cout << c.r << std::endl;
        TopCard = newCard;
        //std::cout << TopCard->r << std::endl;
        TopCard->nextCard = nullptr;
    }
    else
    {
        cardPtr = TopCard;
        while(cardPtr->nextCard != nullptr)
        {
            cardPtr = cardPtr->nextCard;
        }
        cardPtr->nextCard = newCard;
    }
    count++;
}

Deck::Card Deck::pullTop()
{
    if(!TopCard)
    {
        std::cout << "No Cards to Pull from";
    }
    Card *cardPtr;
    cardPtr = TopCard;
    //std::cout << "TopCard Pointer Rank origional " << cardPtr->r << std::endl;
    TopCard = TopCard->nextCard;
    count--;
    //std::cout << ".TopCard Pointer Rank " << TopCard->r << std::endl;
    //std::cout << "TopCard Pointer Rank " << cardPtr->r << std::endl;
    return *cardPtr;
}

Deck::Card Deck::removeCard(int i, Card* c)
{
    if(i > count)
    {
        std::cerr <<"not enough cards";
    }
    else
    {
        Card *previousCardPtr;
        Card *cardPtr;
        Card *nextCardPtr;
        cardPtr = c;
        for(int j = 0; j < i; j++)
        {
            nextCardPtr = cardPtr->nextCard;
            previousCardPtr = cardPtr;
            cardPtr = nextCardPtr;
        }
        previousCardPtr->nextCard = nextCardPtr;
        count--;
        //std::cout << "Removing: " << cardPtr->r << " " << cardPtr->s << std::endl;
        return *cardPtr;
    }
    
}

void Deck::GenerateDeck()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            pushTop(j,i);
        }
    }
    ShuffleDeck();
}

void Deck::ShuffleDeck()
{
    
    int j = 0;
    if(!TopCard)
    {
        std::cerr << "no Cards";
    }
    else
    {
        Card *oldDeckTop;
        oldDeckTop = TopCard;
        TopCard = nullptr;
        for(int i = count; i > 0; i--)
        {
            j = rand() % i;
            std::cout << std::endl;
            Card c = removeCard(j, oldDeckTop);
            pushTop(c.r,c.s);
        }
    }
}

int Deck::getCount()
{
    return count;
}

Deck::Card* Deck::readTop()
{
    //std::cout << "TopCard " << TopCard->r << std::endl;
    return TopCard;
}