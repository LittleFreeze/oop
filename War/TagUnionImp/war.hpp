#ifndef WAR_HPP_INCLUDED
#define WAR_HPP_INCLUDED

#include "deck.hpp"

class War
{
private:
    int playerWins; //Int to count rounds won by the player
    int computerWins; //Int to count the rounds won by the computer
    int roundCount; //Int to keep track of number of rounds left

    Deck pdeck; //Player's deck
    Deck pStoreDeck; //Temporary storage for player
    Deck cdeck; //Computer's deck
    Deck cStoreDeck; //Temporary storage for computer
    Deck tempDeck; //Temporary storage for draw rounds
    Deck deck; //Main deck

    struct Card
    {
        unsigned char RAndS; //8 bit int to represent rank and suit
        Card* nextCard; //Pointer to next card in linked list
    };

public:
    War() //Create class and set starting values
    {
        playerWins = 0;
        computerWins = 0;
        roundCount = 500;
    };
    void setupWar(); //Function to setup the game
    void playerWin(); //Function to declare that the player won the round
    void computerWin(); //Function to declare that the computer won the round
    void draw(); //Function to declare that the round was a draw
    void runWar(); //Function to run the game
    void declareWinner(); //Function to declare a winner of the game
};

#endif