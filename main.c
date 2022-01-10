#include "basic.h"
#include "time.h"
#include "stdlib.h"

//--------------------------------------------------------------------------------------------------

// Rules:
// 52 card_data per deck - use 6 decks - shufflle when 60 card_data remain.
// As clode to 21, but not over!
// Ace can be one or 11


// 1  2  3  4  5  6  7  8  9  10 J  Q  K   A
// 1  2  3  4  5  6  7  8  9  10 10 10 10 1/11

// Bets before game

// players have 2 card_data up, dealer have one up and one down 
// Black jack - A + 10'card - dealer looses and pays you 1.5x your bet.

// - stand: we do not want another card. (I have a sum too close to 21).
// - hit: we want another card to go closer to 21.
// - bust:
// - 

//--------------------------------------------------------------------------------------------------

typedef struct Card Card;
typedef struct Deck Deck;
typedef enum CardType CardType;

//--------------------------------------------------------------------------------------------------

#define CARD_DECK_COUNT 1

//--------------------------------------------------------------------------------------------------

enum CardType {
  CardTypeSpades,
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

struct Deck {
  Card* card_data;
  int card_count;
  int deck_count;
  int top_card_index;
};

//--------------------------------------------------------------------------------------------------

void deck_init(Deck* deck, int deck_count) {
  deck->top_card_index = 0;
  deck->deck_count = deck_count;
  deck->card_count = 52 * deck_count;

  deck->card_data = malloc(sizeof(Card) * deck->card_count);

  for (int k = 0; k < deck_count; k++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        deck->card_data[k*52 + i * 13 + j].number = j + 1;
        deck->card_data[k*52 + i * 13 + j].type = i;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void print_card(Card* card) {
  static char* card_type_symbol[] = {"♤", "♧", "♡", "♢"};
  static char* card_index_symbol[] = {"-", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  print("%s%s", card_index_symbol[card->number], card_type_symbol[card->type]);
}

//--------------------------------------------------------------------------------------------------

void print_deck(Deck* deck) {
  for (int j = 0; j < 52; j++) {
    for (int i = 0; i < deck->deck_count; i++) {
      print_card(&deck->card_data[52 * i + j]);
      print("\t");
    }
    print("\n");
  }

  return;

  for (int i = 0; i < deck->card_count; i++) {
    print_card(&deck->card_data[i]);
  }
}

void shuffle_deck(Deck* deck) {
  for (int i = 0; i < 1000000; i++) {
    int a = rand() % deck->card_count;
    int b = rand() % deck->card_count;
    
    Card card = deck->card_data[a];

    deck->card_data[a] = deck->card_data[b];
    deck->card_data[b] = card;
  }
}

//--------------------------------------------------------------------------------------------------

int main() {
  srand(time(0));

  Deck deck;
  deck_init(&deck, 4);

  shuffle_deck(&deck);
  print_deck(&deck);


  return 0;
}
