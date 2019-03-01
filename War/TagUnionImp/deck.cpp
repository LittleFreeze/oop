#include "deck.hpp"

Rank Deck::IntToRank(int i)
{
    Rank rtdata;
    switch(i)
    {
        case 0 : rtdata = Ace;
            break;
        case 1 : rtdata = Two;
            break;
        case 2 : rtdata = Three;
            break;
        case 3 : rtdata = Four;
            break; 
        case 4 : rtdata = Five;
            break;
        case 5 : rtdata = Six;
            break;
        case 6 : rtdata = Seven;
            break;
        case 7 : rtdata = Eight;
            break;
        case 8 : rtdata = Nine;
            break;
        case 9 : rtdata = Ten;
            break;
        case 10 : rtdata = Jack;
            break;
        case 11 : rtdata = Queen;
            break;
        case 12 : rtdata = King;
            break;
    }
    return rtdata;
}

Suit Deck::IntToSuit(int i)
{
    Suit rtdata;
    switch(i)
    {
        case 0 : rtdata = Hearts;
            break;
        case 1 : rtdata = Diamonds;
            break;
        case 2 : rtdata = Spades;
            break;
        case 3 : rtdata = Clubs;
            break;
    }
    return rtdata;
}

Color Deck::IntToColor(int i)
{
    if(i == 0)
        return Red;
    else
    {
        return Black;
    }
    
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
        newCard->setData(c.getData()->jc.getColor());
    }
    else
    {
        newCard->setData(c.getData()->sc.getRank(),c.getData()->sc.getSuit());
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
            pushTop(IntToRank(j),IntToSuit(i));
        }
    }
    ShuffleDeck();
}

void Deck::GenerateDeckWithJokers()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            pushTop(IntToRank(j),IntToSuit(i));
        }
    }
    pushJTop(Black);
    pushJTop(Red);
    ShuffleDeck();
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
        for(int i = count; i > 0; i--)
        {
            j = rand() % i +1;
            Card c = removeCard(j, oldDeckTop);
            if(!(c.isJoker()))
                pushTop(c.getData()->sc.getRank(),c.getData()->sc.getSuit()); 
            else
                pushJTop(c.getData()->jc.getColor());
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
        if(!(currentCard->isJoker()))
        {
            std::cout << "Rank: " << IntToRank(currentCard->getData()->sc.getRank());
            std::cout << " Suit: " << IntToSuit(currentCard->getData()->sc.getSuit()) << std::endl;
        }
        else
        {
            std::cout << "Rank: Joker";
            std::cout << " Color: " << IntToColor(currentCard->getData()->jc.getColor()) << std::endl;
        }
        currentCard = currentCard->nextCard;
    }
}