#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

enum Suit
{
    Hearts,
    Clubs,
    Spades,
    Diamonds
};

enum Rank
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

class Deck
{
private:
    struct Card
    {
        Rank r;
        Suit s;
        Card* nextCard;
    };

    Card* TopCard;

public:
    Deck()
    {
        TopCard = nullptr;
    }
    Rank IntToRank(int);
    Suit IntToSuit(int);
    void pushTop(int, int);
    void addBottom(int, int);
    Card pullTop();
    ~Deck();
};

#endif