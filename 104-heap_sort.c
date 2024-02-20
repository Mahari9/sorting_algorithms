#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @i: The first integer to be swaped.
 * @j: The second integer to be swaped.
 */
void swap_int(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @b: The index of the base row of the tree.
 * @r: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t b, size_t r)
{
	size_t left, right, max;

	left = 2 * r + 1;
	right = 2 * r + 2;
	max = r;

	if (left < b && array[left] > array[max])
		max = left;
	if (right < b && array[right] > array[max])
		max = right;

	if (max != r)
	{
		swap_int(array + r, array + max);
		print_array(array, size);
		heapify(array, size, b, max);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
