#include "sort.h"

/**
 * count_srt - Perform counting sort on LSD for Radix sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @curr_digit: The current digit place value (1, 10, 100, ...).
 */
void count_srt(int *array, size_t size, int curr_digit)
{
	const int base = 10;
	int i, *result = malloc(sizeof(int) * size), *counter;
	size_t j;

	counter = malloc(sizeof(int) * base);
	if (result == NULL || counter == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < base; i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[(array[j] / curr_digit) % base]++;
	for (i = 1; i < base; i++)
		counter[i] += counter[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		result[counter[(array[i] / curr_digit) % base] - 1] = array[i];
		counter[(array[i] / curr_digit) % base]--;
	}
	for (j = 0; j < size; j++)
		array[j] = result[j];

	free(result);
	free(counter);
}
/**
 * radix_sort - Sorts an array of integers using LSD Radix sort algorithm
 * @array: The array to be ordered.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_num, curr_digit;
	size_t i;

	if (size < 2)
		return;
	max_num = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	for (curr_digit = 1; max_num / curr_digit > 0; curr_digit *= 10)
	{
		count_srt(array, size, curr_digit);
		print_array(array, size);
	}
}
