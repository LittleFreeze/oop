#ifndef JokerCard_HPP_INCLUDED
#define JokerCard_HPP_INCLUDED

#include "deck.hpp"
#include "Card.hpp"

class JokerCard : public Card
{
private:

public:
    JokerCard(Color color)
    {
        setColor(color);
        setKind(Joker);
    }

    void printCard()
    {
        std::cout << "Joker " << getColor() << std::endl;
    }
};

#endif