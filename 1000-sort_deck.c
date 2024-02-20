#include "deck.h"
#include <stdio.h>

/**
 * ma_strcmp -  function that compares two strings.
 * @str1: string one
 * @str2: string two
 * Return: 0 on success
 */

int ma_strcmp(const char *str1, const char *str2)
{
	int result = 0;

	while (*str1 == *str2 && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	if (str1 != str2)
		result = *str1 - *str2;

	return (result);
}

/**
 * get_card_value - Get the position value of a card in a deck
 * @node: Pointer to the deck node containing the card
 * Return: The position value of the card.
 */
int get_card_value(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (ma_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (ma_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (ma_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (ma_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (ma_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}

/**
 * swap - Swap a card with its previous card in a deck
 * @card: Pointer to the card node to be swapped
 * @deck: Pointer to the deck containing the cards
 * Return: The current card node
 */
deck_node_t *swap(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *curr = card;

	back->next = curr->next;
	if (curr->next)
		curr->next->prev = back;
	curr->next = back;
	curr->prev = back->prev;
	back->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*deck = curr;
	return (curr);
}

/**
 * insertion_sort_deck - Sort a deck using the insertion sort algorithm
 * @deck: Pointer to pointer to the deck of cards to be sorted
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int value_prev, value_curr;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			value_prev = get_card_value((node->prev));
			value_curr = get_card_value(node);
		}
		while ((node->prev) && (value_prev > value_curr))
		{
			value_prev = get_card_value((node->prev));
			value_curr = get_card_value(node);
			node = swap(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - Sort a deck using the insertion sort algorithm
 * @deck: Pointer to pointer to the deck of cards to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
