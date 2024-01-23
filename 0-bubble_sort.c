#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Implements an optimized
 * version of the bubble sort algorithm that stops when no swaps are needed.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int is_sorted = 0;

	if (array == NULL || size < 2)
		return;

	while (is_sorted == 0)
	{
		is_sorted = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(&array[i], &array[i + 1]);
				print_array(array, size);
				is_sorted = 0;
			}
		}
		len--;
	}
}
