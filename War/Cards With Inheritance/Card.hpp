#ifndef Card_HPP_INCLUDED
#define Card_HPP_INCLUDED

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

class Card //Class to represent cards
    {
    private:

        Color cardColor;
        PlayingCardKind cardKind;

    public:
        virtual void printCard() {}; //Inherited virtual function to print the card

        void setColor(Color color) //Inherited function to set the color of the card
        {
            cardColor = color;
        }

        Color getColor() //Inherited function to get the color of the card
        {
            return cardColor;
        }

        void setKind(PlayingCardKind kind) //Inherited function to set the type of card (Standard or Joker)
        {
            cardKind = kind;
        }

        PlayingCardKind getKind() //Inherited function to get the type of card
        {
            return cardKind;
        }

        Card* nextCard; //Pointer to next card in linked list
        
    };

#endif