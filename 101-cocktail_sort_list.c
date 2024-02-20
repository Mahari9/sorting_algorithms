#include "sort.h"

/**
 * swap - Swap two nodes in a doubly linked list
 * @list: Pointer to pointer to the head of the list
 * @node: Pointer to pointer the node to be swapped
 * return: Nothing
 */
void swap(listint_t **list, listint_t **node)
{
	listint_t *one, *two, *three, *four;

	one = (*node)->prev;
	two = *node;
	three = (*node)->next;
	four = (*node)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*node = three;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * using the Cocktail Shaker Sort
 * @list: Pointer to pointer to the head of the list
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int ordered = 0;

	if (!list || !*list || !(*list)->next)
		return;
	curr = *list;
	while (!ordered)
	{
		ordered = 1;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				ordered = 0;
				swap(list, &curr);
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (ordered)
			break;
		curr = curr->prev;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				ordered = 0;
				curr = curr->prev;
				swap(list, &curr);
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
