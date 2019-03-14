#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <cstdlib>
#include <iostream>

#include "Card.hpp"
#include "JokerCard.hpp"
#include "StandardCard.hpp"

class Deck
{
private:
    Card c;

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
    Card* removeCard(int, Card*&); //Function to remove a card at passed position from a deck
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