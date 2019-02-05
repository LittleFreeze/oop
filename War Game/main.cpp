#include <cstdlib>
#include <time.h>

#include "deck.hpp"

int main(void)
{
    srand(time(0));
    Deck deck;
    deck.pushTop(5,2);
    
    return 0;
}