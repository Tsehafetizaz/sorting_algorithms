#include "sort.h"

void swap_ints(int *a, int *b);
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high);
void quicksort(int *array, size_t size, ssize_t low, ssize_t high);

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - Lomuto partition scheme.
 * @array: The array to sort.
 * @size: Size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The final partition index.
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Applies the quicksort algorithm recursively.
 * @array: The array to sort.
 * @size: Size of the array.
 * @low: The starting index of the array or sub-array.
 * @high: The ending index of the array or sub-array.
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t partition_idx = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, partition_idx - 1);
		quicksort(array, size, partition_idx + 1, high);
	}
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
