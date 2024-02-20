#include "sort.h"

/**
 * hoare_prtn - Performs partition using the Hoare scheme
 * @array: The array to be partitioned
 * @size: The size of the array
 * @left: left side of the partition
 * @right: right side of the partition
 * Return: The final position of the pivot
 */
int hoare_prtn(int *array, size_t size, int left, int right)
{
	int pivot, high, low, tmp;

	pivot = array[right];
	for (high = left - 1, low = right + 1; high < low;)
	{
		do {
			high++;
		} while (array[high] < pivot);
		do {
			low--;
		} while (array[low] > pivot);

		if (high < low)
		{
			tmp = array[high];
			array[high] = array[low];
			array[low] = tmp;
			print_array(array, size);
		}
	}

	return (high);
}

/**
 * qksrt_h - Perform Quick sort using Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 * @left: The left/lower index of the partition
 * @right: The right /higher index of the partition
 */
void qksrt_h(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_prtn(array, size, left, right);
		qksrt_h(array, size, left, part - 1);
		qksrt_h(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *         using Quick sort (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qksrt_h(array, size, 0, size - 1);
}
