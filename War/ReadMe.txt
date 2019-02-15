Program By Evan Von Duhn

The goal of this program is to simulate the card game War using abstractions.

First I had to be able to create the deck of cards that will be used in the game.
I used a full class to represent a deck of cards, and a struct to represent each individual card.
I kept the deck in order by using single linked list of the cards.
Each player then had their own deck that would be used to keep track of their cards.

Update:

I changed the Rank and Suit enums to a single char that is stored as 0b00rrrrss
I also added the war class and created functions using the code from the origional main funciton
This class represents the game of war and keeps track of the number of rounds left along with the number of wins for each player
