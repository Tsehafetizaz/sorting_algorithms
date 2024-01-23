#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using insertion sort.
 * @list: Pointer to the head of the doubly linked list.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *prev_sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = iter->next)
	{
		insert = prev_sorted = iter->prev; 

		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list); 
			insert = insert->prev;
		}

		if (insert == prev_sorted || insert == NULL)
			continue;

		swap_nodes(list, &insert->next, iter);
		print_list((const listint_t *)*list); 
	}
}
