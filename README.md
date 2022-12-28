# Command Line Card Games

Requirements:
- Turn-based
- Any number of players
- No extra knowledge, just decision making
    - Includes the state of the game (FOR NOW, THIS WILL CHANGE)
    - I'd like for this to be a way to figure out the best decisions for each game


Ideas for games:
- 3 13
- Solitaire
   - Spider solitaire
- Hand & Foot
- Golf
   - Skyjo
- Cribbage
- Rummy
- Spades
- Poker
- Skip-Bo

## Classes
Provide data structures for creating games

### Cards
- Pile
   - Owns a stack data structure of cards
   - Draw() - returns card at the top of the stack

- Deck
   - Inherits from Pile
   - Override constructor to create different decks for different games
   - Shuffle() - reorders the stack of cards
   - Return() - given a list of cards, returns these cards to the deck and calls Shuffle()

- DiscardPile
   - Inherits from Pile
   - Check() - returns the CardValue of the card at the top of the stack
   - Reload() - returns all cards in the stack except for the top card, which remains in the pile
   - ReloadAll() - returns all cards in the stack

- Card
   - Unique instance of CardValue
   - GetValue() - returns card value
   - Types of cards
      - Standard 52
      - Standard 54
      - SkipBo

- CardValue
   - Card value
   - Card color/suit

### Player
- Hand
   - Viewable list of cards
   - Owns unique instances of cards
   - Add() - appends list of cards to owned cards
   - Pick() - given an index, returns instance of card
   - Count() - returns number of cards in hand

- Player
   - Per-game interface
   - Owns PlayerGameState
   - Owns Hand
   - TakeTurn() - virtual function that takes a reference to a TurnController object and GameState as argument

- AI
   - Implements Player interface
   - Implements TakeTurn()
      - Reads game state
      - Reads own played cards
      - Makes decisions

- RealPlayer
   - Implements Player interface
   - Implements TakeTurn()
      - Prompts user for input on what move to make

### Game
- TurnController
   - Interface containing all options a player can take during their turn
   - Enforces turn rules
   - EndTurn() - signals

- GameController
   - Owns all players
   - Owns GameState
   - Owns TurnController implementation
   - Runs game on a loop, passing TurnController to each player
   - Checks & determines when game ends

- GameState
   - Owns deck
   - Owns central discard pile
   - Owns list of references to PlayerGameStates
   - Deal() - takes cards from the deck and adds them to each hand with PlayerGameState::Hand.Add()

- PlayerGameState
   - Implemented per-game
   - Owns reference to Hand
   - Owns visible played cards on the table
   - Tracks scores
