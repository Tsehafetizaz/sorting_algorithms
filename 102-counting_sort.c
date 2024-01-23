#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the Counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array;
	int k = 0;
	size_t i, j;

	/* Check for null array or size less than 2 */
	if (!array || size < 2)
		return;

	/* Find the maximum value in the array to determine the size of count_array */
	for (i = 0; i < size; i++) {
		if (array[i] > k)
			k = array[i];
	}

	/* Allocate memory for the counting array */
	count_array = malloc((k + 1) * sizeof(int));
	if (!count_array)
		return;

	/* Initialize count_array to zero */
	for (i = 0; i <= (size_t)k; i++)
		count_array[i] = 0;

	/* Count the occurrences of each value */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Accumulate the counts */
	for (i = 1; i <= (size_t)k; i++)
		count_array[i] += count_array[i - 1];

	/* Print the count_array */
	print_array(count_array, k + 1);

	/* Sort the original array using count_array */
	for (j = size; j > 0; j--) {
		array[count_array[array[j - 1]] - 1] = array[j - 1];
		count_array[array[j - 1]]--;
	}

	/* Free the allocated memory */
	free(count_array);
}
