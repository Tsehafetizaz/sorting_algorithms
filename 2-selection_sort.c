#include "sort.h"

/* Function prototype for swap_ints */
void swap_ints(int *a, int *b);

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap_ints(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}

/**
 * swap_ints - Swap two integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

