#include "basic.h"

//--------------------------------------------------------------------------------------------------

// Rules:
// 52 cards per deck - use 6 decks - shufflle when 60 cards remain.
// As clode to 21, but not over!
// Ace can be one or 11


// 1  2  3  4  5  6  7  8  9  10 J  Q  K   A
// 1  2  3  4  5  6  7  8  9  10 10 10 10 1/11

// Bets before game

// players have 2 cards up, dealer have one up and one down 
// Black jack - A + 10'card - dealer looses and pays you 1.5x your bet.

// - stand: we do not want another card. (I have a sum too close to 21).
// - hit: we want another card to go closer to 21.
// - bust:
// - 

//--------------------------------------------------------------------------------------------------

typedef struct Card Card;
typedef struct CardDeck CardDeck;
typedef enum CardType CardType;

//--------------------------------------------------------------------------------------------------

#define CARD_COUNT 52
#define CARD_DECK_COUNT 1

//--------------------------------------------------------------------------------------------------

enum CardType {
  CardTypeSpaces,
  CardTypeClubs,
  CardTypeHearts,
  CardTypeDiamonds,
};

//--------------------------------------------------------------------------------------------------

struct Card {
  CardType type;
  int number;
};

//--------------------------------------------------------------------------------------------------

struct CardDeck {
  Card cards[CARD_COUNT];
  int top_card_index;
};

//--------------------------------------------------------------------------------------------------

void card_deck_init(CardDeck* deck) {
  deck->top_card_index = 0;
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      deck->cards[j + 13*i].number = j + 1;
      deck->cards[j + 13*i].type = i;
    }
  }
}

//--------------------------------------------------------------------------------------------------

int main() {
  CardDeck deck;
  card_deck_init(&deck);
  for (int i = 0; i < CARD_COUNT; i++) {
    print("card = %i-%i\n", deck.cards[i].type, deck.cards[i].number);
  }
  return 0;
}
