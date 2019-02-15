#include "deck.hpp"

int Deck::getRank(char RAndS) //Function to get rank of passed card
{
    return RAndS >> 2;
}

int Deck::getSuit(char RAndS) //Function to get suit of passed card
{
    char temp = 0b00000011;
    char Suit = RAndS & temp;
    return Suit;
}

char Deck::intsToSAndR(int r, int s) //Funtion to convert two integers into character to represent rank and suit
{
    char RAndS;

    RAndS = r;
    RAndS = RAndS << 2;
    RAndS = RAndS + s; //Store rank and suit as 0b00rrrrss

    return RAndS;
}

void Deck::pushTop(int r, int s) //Funtion to create a new card and add it to the top of the deck
{
    Card *newCard; 
    newCard = new Card;
    newCard->RAndS = intsToSAndR(r,s);
    newCard->nextCard = TopCard;
    TopCard = newCard;
    count++;
}

void Deck::addBottom(Card c) //Function to add card to bottom of the deck
{
    Card *cardPtr;
    Card *newCard;  
    newCard = new Card;
    newCard->RAndS = intsToSAndR(getRank(c.RAndS),getSuit(c.RAndS));
    newCard->nextCard = nullptr;
    
    if(!TopCard || count == 0)
    {
        TopCard = newCard;
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

Deck::Card Deck::pullTop() //Function to pull off the top card of the deck
{
    if(!TopCard)
    {
        std::cout << "No Cards to Pull from";
    }
    Card *cardPtr;
    cardPtr = TopCard;
    TopCard = TopCard->nextCard;
    count--;

    return *cardPtr;
}

Deck::Card Deck::removeCard(int i, Card* c) //Function to remove a card at passed position from a deck
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
        return *cardPtr;
    }
    
}

void Deck::GenerateDeck() //Function to fill deck with 52 cards
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

void Deck::ShuffleDeck() //Function to shuffle deck
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

int Deck::getCount() //Function to return number of cards in deck
{
    return count;
}

Deck::Card* Deck::readTop() //Function to return pointer to top card
{
    return TopCard;
}