#include <iostream>

enum rank
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
    King,
};

enum suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades,
};

struct card
{
    rank r;
    suit s;
};

bool operator==(card a, card b)
{
    return (a.r == b.r);
}

bool operator>=(card a, card b)
{
    return (a.r >= b.r);
}

int main(void)
{
    card c;
    c.r = Ace;
    c.s = Hearts;

    card d;
    d.r = Ace;
    d.s = Diamonds;

    std::cout << (d == c);

    return 0;
}

