#include "deck.hpp"

Deck InitDeck(bool aHasJokers) {
    Deck d; 
    for(int suit = 0; suit < 4; suit++) {
        for(int value = 1; value < 13; value++) {
            Card c = Card(static_cast<Suit>(suit), static_cast<Value>(value));
            d.push_back(c);
        } 
    }
    if(aHasJokers) {
        // TODO: jokers shouldn't have suits
        Card joker = Card(Spades, Joker);
        d.push_back(joker);
        d.push_back(joker);
    }
    return d;
}