#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * using the Quick sort algorithm
 * @array: Array to be partitioned
 * @left: Leftmost index of the partition
 * @right: Rightmost index of the partition
 * @size: Size of the array
 * Return: Partition index
 */

int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right], i = left, j, tmp;

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (right != i)
	{
		array[right] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_lomuto - Recursive function for Quick sort with Lomuto
 * partition scheme
 * @array: Array to be sorted
 * @left: left index of the partition
 * @right: Right index of the partition
 * @size: Size of the array
 * Return: Nothing
 */
void quicksort_lomuto(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = lomuto_partition(array, left, right, size);
		quicksort_lomuto(array, left, pivot_index - 1, size);
		quicksort_lomuto(array, pivot_index + 1, right, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_lomuto(array, 0, size - 1, size);
}
