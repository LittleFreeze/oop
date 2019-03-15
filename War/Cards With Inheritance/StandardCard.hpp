#ifndef StandardCard_HPP_INCLUDED
#define StandardCard_HPP_INCLUDED

#include "deck.hpp"
#include "Card.hpp"

class StandardCard : public Card //Class to represent standard cards
{
private:
    Rank rank;
    Suit suit;
public:
    StandardCard(Rank a, Suit b) //Constructor function
    {
        rank = a;
        suit = b;
        setStandardCardColor(b);
        setKind(Standard);
    }

    void setStandardCardColor(Suit a) //Function to set color of the standard card using the inherited function setColor
    {
        if(a == Diamonds || a == Hearts)
        {
            setColor(Red);
        }
        else
        {
            setColor(Black);
        }
        
    }

    Rank getRank() //Function to get rank of standard card
    {
        return rank;
    }

    Suit getSuit() //Function to get suit of standard card
    {
        return suit;
    }

    void printCard() //Funciton to print the suit and rank of the standard card
    {
        std::cout << suit << " " << rank << std::endl;
    }

    
};

#endif