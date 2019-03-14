#ifndef StandardCard_HPP_INCLUDED
#define StandardCard_HPP_INCLUDED

#include "deck.hpp"
#include "Card.hpp"

class StandardCard : public Card
{
private:
    Rank rank;
    Suit suit;
public:
    StandardCard(Rank a, Suit b)
    {
        rank = a;
        suit = b;
        setStandardCardColor(b);
        setKind(Standard);
    }

    void setStandardCardColor(Suit a)
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

    void printCard()
    {
        std::cout << suit << " " << rank << std::endl;
    }

    
};

#endif