#include "sort.h"

/**
 * merge_sr - Merges two sub-arrays into a single sorted array.
 * @buffer: Temporary array for merging sub-arrays
 * @array: Pointer to the original array.
 * @left: Pointer to the left sub-array.
 * @half: middle half of the array.
 * @right: Pointer to the right sub-array.
 */
void merge_sr(int *buffer, int *array, size_t left, size_t half, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, half  - left);
	printf("[right]: ");
	print_array(array + half, right - half);

	for (i = left, j = half; i < half && j < right; k++)
	{
		if (array[i] < array[j])
			buffer[k] = array[i++];
		else
			buffer[k] = array[j++];
	}

	while (i < half)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = buffer[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_recursive - Recursively divides and sorts
 * the array using merge sort.
 * @buffer: Temporary array for merging sub-arrays
 * @array: Pointer to the array to be sorted.
 * @left: left index of the sub-array.
 * @right: right index of the sub-array.
 */
void merge_recursive(int *buffer, int *array, size_t left, size_t right)
{
	size_t half;

	if (right - left > 1)
	{
		half = (right - left) / 2 + left;
		merge_recursive(buffer, array, left, half);
		merge_recursive(buffer, array, half, right);
		merge_sr(buffer, array, left, half, right);
	}
}


/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

	merge_recursive(buffer, array, 0, size);
	free(buffer);
}
