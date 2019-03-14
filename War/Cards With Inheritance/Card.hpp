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

class Card
    {
    private:

        Color cardColor;
        PlayingCardKind cardKind;

    public:
        virtual void printCard() {};

        void setColor(Color color)
        {
            cardColor = color;
        }

        Color getColor()
        {
            return cardColor;
        }

        void setKind(PlayingCardKind kind)
        {
            cardKind = kind;
        }

        PlayingCardKind getKind()
        {
            return cardKind;
        }

        Card* nextCard; //Pointer to next card in linked list
        
    };

#endif