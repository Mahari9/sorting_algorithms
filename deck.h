#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Enumeration for different card suits
 * @SPADE: Represents the spade suit
 * @HEART: Represents the heart suit
 * @CLUB: Represents the club suit
 * @DIAMOND: Represents the diamond suit
 *
 * Description: Enumerates the possible suits for playing cards.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

#include <stdio.h>
#include <stdlib.h>
/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

int ma_strcmp(const char *str1, const char *str2);
deck_node_t *swap(deck_node_t *card, deck_node_t **deck);
int get_card_value(deck_node_t *node);
void insertion_sort_deck(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

#endif
