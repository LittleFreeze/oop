#include <cstdlib>
#include <time.h>
#include <iostream>

#include "deck.hpp"

int main(void)
{
    srand(time(0));
    
    

    Card c;

    for(int i = 0; i < 52; i++)
    {
        if(i % 2 == 0)
        {
            pdeck.addBottom(deck.pullTop());
        }
        else
        {
            cdeck.addBottom(deck.pullTop());
        }
    }
  
    while((pdeck.getCount()+pStoreDeck.getCount()) != 0 && (cdeck.getCount()+cStoreDeck.getCount()) != 0)
    {
        while(pdeck.getCount() != 0 && cdeck.getCount() != 0)
        {
            
            if(pdeck.getRank(pdeck.readTop()->RAndS) > cdeck.getRank(cdeck.readTop()->RAndS))
            {
                std::cout << "Player Top " << pdeck.getRank(pdeck.readTop()->RAndS) << std::endl;
                std::cout << "Computer Top " << cdeck.getRank(cdeck.readTop()->RAndS) << std::endl;
                std::cout << "Player wins" << std::endl;
                pStoreDeck.addBottom(pdeck.pullTop());
                pStoreDeck.addBottom(cdeck.pullTop());
                if(tempDeck.getCount()!=0)
                {
                    while(tempDeck.getCount() > 0)
                        pStoreDeck.addBottom(tempDeck.pullTop());
                }
            }
            else if(pdeck.getRank(pdeck.readTop()->RAndS) < cdeck.getRank(cdeck.readTop()->RAndS))
            {
                std::cout << "Player Top " << pdeck.getRank(pdeck.readTop()->RAndS) << std::endl;
                std::cout << "Computer Top " << cdeck.getRank(cdeck.readTop()->RAndS) << std::endl;
                std::cout << "Computer wins" << std::endl;
                cStoreDeck.addBottom(pdeck.pullTop());
                cStoreDeck.addBottom(cdeck.pullTop());
                if(tempDeck.getCount()!=0)
                {
                    while(tempDeck.getCount() > 0)
                        cStoreDeck.addBottom(tempDeck.pullTop());
                }
            }
            else
            {
                std::cout << "Player Top " << pdeck.getRank(pdeck.readTop()->RAndS) << std::endl;
                std::cout << "Computer Top " << cdeck.getRank(cdeck.readTop()->RAndS) << std::endl;
                std::cout << "Draw" << std::endl;
                std::cout << "Placing down face down cards." << std::endl;
                tempDeck.addBottom(pdeck.pullTop());
                tempDeck.addBottom(cdeck.pullTop());  //  for non checked cards
            }
            
        }
        if(pdeck.getCount() == 0)
        {
            for(int i = 0; i<pStoreDeck.getCount();i++)
                pdeck.addBottom(pStoreDeck.pullTop());
            std::cout << "Computer's Card Count: " << (cdeck.getCount() + cStoreDeck.getCount()) << std::endl;
            std::cout << "Player's Card Count: " << (pdeck.getCount() + pStoreDeck.getCount()) <<std::endl;
        }
        if(cdeck.getCount() == 0)
        {
            for(int i = 0; i<cStoreDeck.getCount();i++)
                cdeck.addBottom(cStoreDeck.pullTop());
            std::cout << "Computer's Card Count: " << (cdeck.getCount() + cStoreDeck.getCount()) << std::endl;
            std::cout << "Player's Card Count: " << (pdeck.getCount() + pStoreDeck.getCount()) <<std::endl;
        }
    }
    if(pdeck.getCount() == 0)
        std::cout << "Computer Wins The Game!" << std::endl;
    else
        std::cout << "Player Wins the Game!" << std::endl;
    return 0;
}