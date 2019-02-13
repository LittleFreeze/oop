#include <cstdlib>
#include <time.h>
#include <iostream>

#include "deck.hpp"
#include "war.hpp"

int main(void)
{
    srand(time(0));

    War w;
    w.setupWar();
    w.runWar();
    w.declareWinner();
  
    
    return 0;
}