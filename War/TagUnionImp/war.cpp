#include "deck.hpp"
#include "war.hpp"

void War::setupWar() //Function to setup the game
{
    deck.GenerateDeck(); //Function to generate a deck of 52 cards

    for(int i = 0; i < 52; i++) //Loop to randomly divide the deck and give to the player and computer
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
}

void War::playerWin() //Function to declare that the player won the round
{
    std::cout << "Player Top " << pdeck.getRank(pdeck.readTop()->RAndS) << std::endl;
    std::cout << "Computer Top " << cdeck.getRank(cdeck.readTop()->RAndS) << std::endl;
    std::cout << "Player wins" << std::endl;
    pStoreDeck.addBottom(pdeck.pullTop()); // Pull the top card from each deck and give add it to the player's temporary storage
    pStoreDeck.addBottom(cdeck.pullTop());
    if(tempDeck.getCount()!=0) //If there are cards stored in the tempdeck from a draw, then add it to the player's deck
    {
        while(tempDeck.getCount() > 0)
            pStoreDeck.addBottom(tempDeck.pullTop());
    }
    playerWins++; //Add a win to the player's win counter
}

void War::computerWin() //Function to declare that the computer won the round
{
    std::cout << "Player Top " << pdeck.getRank(pdeck.readTop()->RAndS) << std::endl;
    std::cout << "Computer Top " << cdeck.getRank(cdeck.readTop()->RAndS) << std::endl;
    std::cout << "Computer wins" << std::endl;
    cStoreDeck.addBottom(pdeck.pullTop()); // Pull the top card from each deck and give add it to the computer's temporary storage
    cStoreDeck.addBottom(cdeck.pullTop());
    if(tempDeck.getCount()!=0) //If there are cards stored in the tempdeck from a draw, then add it to the computer's deck
    {
        while(tempDeck.getCount() > 0)
            cStoreDeck.addBottom(tempDeck.pullTop());
    }
    computerWins++; //Add a win to the computer's win counter
}

void War::draw() //Function to declare that the round was a draw
{
    std::cout << "Player Top " << pdeck.getRank(pdeck.readTop()->RAndS) << std::endl;
    std::cout << "Computer Top " << cdeck.getRank(cdeck.readTop()->RAndS) << std::endl;
    std::cout << "Draw" << std::endl;
    std::cout << "Placing down face down cards." << std::endl;
    tempDeck.addBottom(pdeck.pullTop()); //Put one face down card from each player into the temporary deck
    tempDeck.addBottom(cdeck.pullTop());
}

void War::runWar() //Function to run the game
{
    while((pdeck.getCount()+pStoreDeck.getCount()) != 0 && (cdeck.getCount()+cStoreDeck.getCount()) != 0 && roundCount != 0) //Run until a player runs out of cards or the round count reaches zero
    {
        while(pdeck.getCount() != 0 && cdeck.getCount() != 0 && roundCount != 0) //Run until a player runs out of cards in their current had or the number of rounds reaches zero
        {
            
            if(pdeck.getRank(pdeck.readTop()->RAndS) > cdeck.getRank(cdeck.readTop()->RAndS))
            {
                playerWin();
            }
            else if(pdeck.getRank(pdeck.readTop()->RAndS) < cdeck.getRank(cdeck.readTop()->RAndS))
            {
                computerWin();
            }
            else
            {
                draw();
            }
            roundCount = roundCount -1;
        }
        
        if(pdeck.getCount() == 0) //If the player runs out of cards from their current hand, get the cards that they won and use them as their hand
        {
            for(int i = 0; i<pStoreDeck.getCount();i++)
                pdeck.addBottom(pStoreDeck.pullTop());
            std::cout << "Computer's Card Count: " << (cdeck.getCount() + cStoreDeck.getCount()) << std::endl;
            std::cout << "Player's Card Count: " << (pdeck.getCount() + pStoreDeck.getCount()) <<std::endl;
        }
        if(cdeck.getCount() == 0) //If the computer runs out of cards from its current hand, get the cards that it won and use them as its hand
        {
            for(int i = 0; i<cStoreDeck.getCount();i++)
                cdeck.addBottom(cStoreDeck.pullTop());
            std::cout << "Computer's Card Count: " << (cdeck.getCount() + cStoreDeck.getCount()) << std::endl;
            std::cout << "Player's Card Count: " << (pdeck.getCount() + pStoreDeck.getCount()) <<std::endl;
        }
    }
}

void War::declareWinner() //Function to declare a winner of the game
{
    if(playerWins < computerWins)
        std::cout << "Computer Wins The Game!" <<  std::endl;
    else if(playerWins > computerWins)
        std::cout << "Player Wins the Game!" <<  std::endl;
    else
        std::cout << "Draw!" << std::endl;
    
}
