#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Data structure for doubly linked list */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */
