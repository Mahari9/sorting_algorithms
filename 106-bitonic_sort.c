#include "sort.h"

/**
 * merge_bitonic - Merges two halves of an array in a Bitonic manner
 * @array: Array to be merged
 * @left: left side
 * @right: right side
 * @drxn: The sorting drxnection
 */
void merge_bitonic(int *array, int left, int right, int drxn)
{
	int i, tmp, jump = (left + right) / 2, half = (right - left + 1) / 2;

	if (right - left >= 1)
	{
		for (i = left; i < left + half; i++)
		{
			if (drxn == (array[i] > array[i + half]))
			{
				tmp = array[i + half];
				array[i + half] = array[i];
				array[i] = tmp;
			}
		}
		merge_bitonic(array, left, jump, drxn);
		merge_bitonic(array, jump + 1, right, drxn);
	}
}


/**
 * recursive_bitonic - Recursively performs Bitonic sort on an array
 * @array: Array to be sorted
 * @left: left side
 * @right: right side
 * @drxn: The sorting drxnection
 * @size: The size of the chunk being sorted
 */
void recursive_bitonic(int *array, int left, int right, int drxn, size_t size)
{
	int jump;

	if (right - left >= 1)
	{
		jump = (right + left) / 2;
		printf("Merging [%d/%lu] ", right - left + 1, size);
		if (drxn)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
		recursive_bitonic(array, left, jump, 1, size);
		recursive_bitonic(array, jump + 1, right, 0, size);
		merge_bitonic(array, left, right, drxn);
		printf("Result [%d/%lu] ", right - left + 1, size);
		if (drxn)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
	}
}

/**
 * bitonic_sort - Sorts an array of ints in ascending order using Bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursive_bitonic(array, 0, size - 1, 1, size);
}
