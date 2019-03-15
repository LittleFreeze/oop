Program By Evan Von Duhn

The goal of this program is to simulate the card game War using abstractions.

First I had to be able to create the deck of cards that will be used in the game.
I used a full class to represent a deck of cards, and a struct to represent each individual card.
I kept the deck in order by using single linked list of the cards.
Each player then had their own deck that would be used to keep track of their cards.

Update (3/14/19):

I moddified the card, joker card, and standard card classes to allow for inheritance.
I gave the card class the color and kind variables which are inherited by the standard card and joker card classes.
I also added various functions that are inherited and used by the standard card and joker card classes.

Update:

I changed the Rank and Suit enums to a single char that is stored as 0b00rrrrss
I also added the war class and created functions using the code from the origional main funciton
This class represents the game of war and it keeps track of the number of rounds left along with the number of wins for each player along with the decks of cards used throughout the game
