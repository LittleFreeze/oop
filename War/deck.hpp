#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <cstdlib>
#include <iostream>

class Deck
{
private:
    struct Card
    {
        unsigned char RAndS; //8 bit int to represent rank and suit
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
    int getRank(char); //Function to get rank of passed card
    int getSuit(char); //Function to get suit of passed card
    char intsToSAndR(int, int); //Funtion to convert two integers into character to represent rank and suit
    void pushTop(int, int); //Funtion to create a new card and add it to the top of the deck
    void addBottom(Card); //Function to add card to bottom of the deck
    Card pullTop(); //Function to pull off the top card of the deck
    Card removeCard(int, Card*); //Function to remove a card at passed position from a deck
    void GenerateDeck(); //Function to fill deck with 52 cards
    void ShuffleDeck(); //Function to shuffle deck
    int getCount(); //Function to return number of cards in deck
    Card* readTop(); //Function to return pointer to top card
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