#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size);
void merge_sort_recursive(int *array, size_t size, int *temp_array);

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (!array || size < 2)
		return;

	temp_array = malloc(size * sizeof(int));
	if (!temp_array)
		return;

	merge_sort_recursive(array, size, temp_array);
	free(temp_array);
}
/**
 * merge_sort_recursive - Helper function for merge_sort. It recursively
 * @array: The array to sort.
 * @size: The size of the current segment of the array.
 * @temp_array: A temporary array used for merging.
 */

void merge_sort_recursive(int *array, size_t size, int *temp_array)
{
	size_t mid = size / 2;
	size_t i;

	if (size < 2)
		return;

	merge_sort_recursive(array, mid, temp_array);
	merge_sort_recursive(array + mid, size - mid, temp_array);

	merge(array, temp_array, mid, array + mid, size - mid);

	for (i = 0; i < size; i++)
		array[i] = temp_array[i];
}
/**
 * merge - Merges two sorted halves of an array.
 * @array: The array to merge.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

while (i < left_size && j < right_size)
{
if (left[i] < right[j])
{
array[k] = left[i];
i++;
}
else
{
array[k] = right[j];
j++;
}
k++;
}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];
}
