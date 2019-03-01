#include "deck.hpp"

char Deck::intsToSAndR(int r, int s) //Funtion to convert two integers into character to represent rank and suit
{
    char RAndS;

    RAndS = r;
    RAndS = RAndS << 2;
    RAndS = RAndS + s; //Store rank and suit as 0b00rrrrss

    return RAndS;
}

char Deck::intToJAndC(int c)
{
    char RAndS;

    RAndS = 10 + c;
    RAndS = RAndS << 6;
    return RAndS;
}

void Deck::pushTop(Rank r, Suit s) //Funtion to create a new card and add it to the top of the deck
{
    Card *newCard; 
    newCard = new Card;
    newCard->setData(r,s);
    newCard->nextCard = TopCard;
    TopCard = newCard;
    count++;
}

void Deck::pushJTop(Color c)
{
    Card *newCard; 
    newCard = new Card;
    newCard->setData(c);
    newCard->nextCard = TopCard;
    TopCard = newCard;
    count++;
}

void Deck::addBottom(Card c) //Function to add card to bottom of the deck
{
    Card *cardPtr;
    Card *newCard;  
    newCard = new Card;
    
    if(!(c.isJoker()))
    {
        newCard->setData(c.data->c);
    }
    else
    {
        newCard->setData(c.data->r,c.data->s);
    }
    
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

Deck::Card Deck::removeCard(int i, Card*& c) //Function to remove a card at passed position from a deck
{
    Card *previousCardPtr = c;
    Card *cardPtr;
    Card *nextCardPtr;
    cardPtr = c;
    int count = getNumberOfCards(c);
    if(i > count)
    {
        std::cerr << "not enough cards" <<std::endl;
        cardPtr = NULL;
    }
    else
    {
        if(i == 1)
        {
            if(count == 1)
            {
                return *c;
            }
            else
            {
                cardPtr = c;
                c = cardPtr->nextCard;            
            }
        }
        else
        {
            for(int j = 0; j < i-1; j++)
            {
                previousCardPtr = cardPtr;
                std::cout << getRank(cardPtr->RAndS) << " " << getSuit(cardPtr->RAndS) << std::endl;
                cardPtr = cardPtr->nextCard;
                nextCardPtr = cardPtr->nextCard;
            }
            previousCardPtr->nextCard = nextCardPtr;
        }
        count--;
        cardPtr->nextCard = NULL;
    }
    return *cardPtr;
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
    std::cout << "Here 1" << std::endl;
}

void Deck::GenerateDeckWithJokers()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            pushTop(j,i);
        }
    }
    pushJTop(0);
    pushJTop(1);
    //ShuffleDeck();
}

void Deck::ShuffleDeck() //Function to shuffle deck
{
    
    int j = 0;
    if(!TopCard)
    {
        std::cerr << "no Cards" << std::endl;
    }
    else
    {
        Card *oldDeckTop;
        oldDeckTop = TopCard;
        TopCard = nullptr;
        std::cout << "Here 2" << std::endl;
        for(int i = count; i > 0; i--)
        {
            j = rand() % i +1;
            Card c = removeCard(j, oldDeckTop);
            pushTop(getRank(c.RAndS),getSuit(c.RAndS));     
        }
    }
}

int Deck::getNumberOfCards(Card* c)
{
    int count = 0;
    Card* currentCard = c;
    while(currentCard)
    {
        count++;
        currentCard = currentCard->nextCard;
    }
    return count;
}

int Deck::getCount() //Function to return number of cards in deck
{
    return count;
}

Deck::Card* Deck::readTop() //Function to return pointer to top card
{
    return TopCard;
}

void Deck::printDeck()
{
    Card* currentCard = TopCard;
    while(currentCard != nullptr)
    {
        if(getJoker(currentCard->RAndS) == 0)
        {
            std::cout << "Rank: " << getRank(currentCard->RAndS);
            std::cout << " Suit: " << getSuit(currentCard->RAndS) << std::endl;
        }
        else
        {
            std::cout << "Joker: " << getJoker(currentCard->RAndS);
            std::cout << " Color: " << getColor(currentCard->RAndS) << std::endl;
        }
        currentCard = currentCard->nextCard;
    }
}