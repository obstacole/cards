#include <stdlib.h>
#include <vector>

enum Suit {
    Spades,
    Clubs,
    Hearts,
    Diamonds
};

enum Value {
    Joker,
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

struct Card {
    Suit mSuit;
    Value mValue;

    Card(Suit aSuit, Value aValue) : mSuit(aSuit), mValue(aValue) {};
};

using Deck = std::vector<Card>;

Deck InitDeck(bool aHasJokers);