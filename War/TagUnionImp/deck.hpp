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
    Rank getRank() //Function to get rank of passed card
    {
        return r;
    }
    Suit getSuit() //Function to get suit of passed card
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
    Color getColor()
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
        union PlayingCardData
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
        void setData(Rank a, Suit b)
        {
            data = new PlayingCardData(a,b);
            tag = Standard;
        }
        void setData(Color a)
        {
            data = new PlayingCardData(a);
            tag = Joker;
        }
        bool isJoker()
        {
            return tag == Joker;
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
    
    char intsToSAndR(int, int); //Funtion to convert two integers into character to represent rank and suit
    char intToJAndC(int); //Function to convert integer into char that represents joker and color
    void pushTop(Rank, Suit); //Funtion to create a new card and add it to the top of the deck
    void pushJTop(Color); //Function to create a new joker card integer equals 1 for red, 0 for black
    void addBottom(Card); //Function to add card to bottom of the deck
    Card pullTop(); //Function to pull off the top card of the deck
    Card removeCard(int, Card*&); //Function to remove a card at passed position from a deck
    void GenerateDeck(); //Function to fill deck with 52 cards
    void GenerateDeckWithJokers();  //Function to fill deck with 54 cards
    void ShuffleDeck(); //Function to shuffle deck
    int getNumberOfCards(Card*);
    int getCount(); //Function to return number of cards in deck
    Card* readTop(); //Function to return pointer to top card
    void printDeck(); //Funtion to print every card of the deck
    ~Deck()
    {
        Card *cardPtr;
        Card *nextCardPtr;

        cardPtr = TopCard;

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