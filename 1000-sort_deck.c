#include "deck.h"

/**
 * ma_strcmp - Compares two strings.
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0 on success
 */
int ma_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * get_card_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_card_value(deck_node_t *card)
{
	if (ma_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (ma_strcmp(card->card->value, "1") == 0)
		return (1);
	if (ma_strcmp(card->card->value, "2") == 0)
		return (2);
	if (ma_strcmp(card->card->value, "3") == 0)
		return (3);
	if (ma_strcmp(card->card->value, "4") == 0)
		return (4);
	if (ma_strcmp(card->card->value, "5") == 0)
		return (5);
	if (ma_strcmp(card->card->value, "6") == 0)
		return (6);
	if (ma_strcmp(card->card->value, "7") == 0)
		return (7);
	if (ma_strcmp(card->card->value, "8") == 0)
		return (8);
	if (ma_strcmp(card->card->value, "9") == 0)
		return (9);
	if (ma_strcmp(card->card->value, "10") == 0)
		return (10);
	if (ma_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (ma_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck- Sort a deck of cards from spades to diamonds
 * @deck: A pointer to pointer to the head of a deck_node_t doubly-linked list
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *node, *insert, *tmp;

	for (node = (*deck)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		insert = node->prev;
		while (insert != NULL && insert->card->kind > node->card->kind)
		{
			insert->next = node->next;
			if (node->next != NULL)
				node->next->prev = insert;
			node->prev = insert->prev;
			node->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = node;
			else
				*deck = node;
			insert->prev = node;
			insert = node->prev;
		}
	}
}

/**
 * insertion_sort_value - Sort a deck of cards sorted from
 * spades to diamonds and from ace to king
 * @deck: A pointer to pointer to the head of a doubly-linked list
 */
void insertion_sort_value(deck_node_t **deck)
{
	deck_node_t *node, *insert, *tmp;

	for (node = (*deck)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		insert = node->prev;
		while (insert != NULL &&
		       insert->card->kind == node->card->kind &&
		       get_card_value(insert) > get_card_value(node))
		{
			insert->next = node->next;
			if (node->next != NULL)
				node->next->prev = insert;
			node->prev = insert->prev;
			node->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = node;
			else
				*deck = node;
			insert->prev = node;
			insert = node->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds
 * @deck: A pointer to pointer to the head of a doubly-linked list
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck(deck);
	insertion_sort_value(deck);
}
