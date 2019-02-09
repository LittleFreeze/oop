#include "deck.hpp"

int Deck::getRank(char RAndS)
{
    return RAndS >> 2;
}

int Deck::getSuit(char RAndS)
{
    char temp = 0b00000011;
    char Suit = RAndS & temp;
    return Suit;
}

char Deck::intsToSAndR(int r, int s)
{
    char RAndS;

    RAndS = r;
    RAndS = RAndS << 2;
    RAndS = RAndS + s;

    return RAndS;
}

void Deck::pushTop(int r, int s)
{
    Card *newCard;
    newCard = new Card;
    newCard->RAndS = intsToSAndR(r,s);
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
    newCard->RAndS = intsToSAndR(getRank(c.RAndS),getSuit(c.RAndS));
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
            pushTop(getRank(c.RAndS),getSuit(c.RAndS));
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