Program By Evan Von Duhn

The goal of this program is to simulate the card game War using abstractions.

First I had to be able to create the deck of cards that will be used in the game.
I used a full class to represent a deck of cards, and a struct to represent each individual card.
I kept the deck in order by using single linked list of the cards.
Each player then had their own deck that would be used to keep track of their cards.

Update:

I changed the Rank and Suit enums to a single char that is stored as 0b00rrrrss
I also added the war class and created functions using the code from the origional main funciton
This class represents the game of war and it keeps track of the number of rounds left along with the number of wins for each player along with the decks of cards used throughout the game

Update:

(Binary Jokers)
I added support for the joker cards in the deck.  I did this by storing the joker identifier and color in the most significant bits of the Rank and Suit char.
The char bits were 0bJC000000 for the joker cards.

(Tag Union Jokers)
I added a tag union class in the Card class.  This tag union class contained a joker card class and a standard card class.
I also modified the card class to now incorporate the tag union class.