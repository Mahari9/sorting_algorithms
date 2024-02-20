#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_lomuto(int *array, int left, int right, size_t size);
int lomuto_partition(int *array, int left, int right, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap(listint_t **list, listint_t **node);
void counting_sort(int *array, size_t size);
void merge_sr(int *buffer, int *array, size_t left, size_t half, size_t right);
void merge_recursive(int *buffer, int *array, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void swap_int(int *i, int *j);
void heapify(int *array, size_t size, size_t b, size_t r);
void heap_sort(int *array, size_t size);


#endif
