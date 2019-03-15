#ifndef JokerCard_HPP_INCLUDED
#define JokerCard_HPP_INCLUDED

#include "deck.hpp"
#include "Card.hpp"

class JokerCard : public Card //Class to represent joker cards
{
private:

public:
    JokerCard(Color color) //Constructor function
    {
        setColor(color);
        setKind(Joker);
    }

    void printCard() //Function to print the color of the joker card
    {
        std::cout << "Joker " << getColor() << std::endl;
    }
};

#endif