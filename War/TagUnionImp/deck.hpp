#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <cstdlib>
#include <iostream>

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

enum Suit
{
    Hearts,
    Diamonds,
    Spades,
    Clubs
};

enum Color
{
    Red,
    Black
};

enum PlayingCardKind
{
    Standard, 
    Joker
};

class StandardCard
{
private:
    Rank r;
    Suit s;
public:
    StandardCard(Rank a, Suit b)
    {
        r = a;
        s = b;
    }
    Rank getRank() //Function to get rank of standard card
    {
        return r;
    }
    Suit getSuit() //Function to get suit of standard card
    {
        return s;
    }
};

class JokerCard
{
private:
    Color c;
public:
    JokerCard(Color a)
    {
        c = a;
    }
    Color getColor() //Function to get color of joker card
    {
        return c;
    }
};

class Deck
{
private:
    class Card
    {
    private:
        union PlayingCardData //Union class to hold standard and joker class
        {
            PlayingCardData(Rank r, Suit s) 
                : sc(r,s)
            {}

            PlayingCardData(Color c)
                : jc(c)
            {}

            StandardCard sc;
            JokerCard jc;
        };

        PlayingCardData *data;
        PlayingCardKind tag;
    public:
        void setData(Rank a, Suit b) //Function to get data of card
        {
            data = new PlayingCardData(a,b);
            tag = Standard;
        }
        void setData(Color a) //Funciton to set data of card
        {
            data = new PlayingCardData(a);
            tag = Joker;
        }
        bool isJoker() //Function to check if card is a joker
        {
            return tag == Joker;
        }
        PlayingCardData* getData()
        {
            return data;
        }
        Card* nextCard; //Pointer to next card in linked list
        
    };

    Card* TopCard; //Pointer to the top card of the deck
    int count; //Counter for number of cards in the deck

public:
    Deck()
    {
        TopCard = nullptr;
        count = 0;
    }
    Rank IntToRank(int); //Funciton to convert int to Rank
    Suit IntToSuit(int); //Function to convert int to Suit
    Color IntToColor(int); //Function to convert int to Color
    void pushTop(Rank, Suit); //Funtion to create a new card and add it to the top of the deck
    void pushJTop(Color); //Function to create a new joker card integer equals 1 for red, 0 for black
    void addBottom(Card); //Function to add card to bottom of the deck
    Card pullTop(); //Function to pull off the top card of the deck
    Card removeCard(int, Card*&); //Function to remove a card at passed position from a deck
    void GenerateDeck(); //Function to fill deck with 52 cards
    void GenerateDeckWithJokers();  //Function to fill deck with 54 cards
    void ShuffleDeck(); //Function to shuffle deck
    int getNumberOfCards(Card*); //Function to count the number of cards in deck
    int getCount(); //Function to return number of cards in deck
    Card* readTop(); //Function to return pointer to top card
    void printDeck(); //Funtion to print every card of the deck
    ~Deck()
    {
        Card *cardPtr;
        Card *nextCardPtr;

        cardPtr = TopCard;

        while(cardPtr)
        {
            nextCardPtr = cardPtr->nextCard;
            delete cardPtr;
            cardPtr = nextCardPtr;
        }
    }
};

#endif