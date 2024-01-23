#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node with the node ahead of it in the list.
 * @list: Double pointer to the head of the list.
 * @tail: Double pointer to the tail of the list.
 * @shaker: Double pointer to the current node.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;

	if (tmp->next)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;

	(*shaker)->next = tmp->next;
	tmp->prev = (*shaker)->prev;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node with the node behind it in the list.
 * @list: Double pointer to the head of the list.
 * @tail: Double pointer to the tail of the list.
 * @shaker: Double pointer to the current node.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if (tmp->prev)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;

	if ((*shaker)->next)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;

	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	tmp->prev = *shaker;
	(*shaker)->next = tmp;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a doubly linked list of integers in ascending
 * @list: A double pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1; /* Use int instead of bool */
	listint_t *tail = NULL, *shaker;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Finding the tail of the list */
	for (tail = *list; tail && tail->next; tail = tail->next)
	{
	while (swapped)
	{
		swapped = 0; /* Use 0 instead of false */

		/* Forward pass */
		for (shaker = *list; shaker && shaker->next; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list(*list);
				swapped = 1; /* Use 1 instead of true */
			}
		}

		if (!swapped)
			break;

		swapped = 0; /* Reset swapped for backward pass */

		/* Backward pass */
		for (shaker = tail; shaker && shaker->prev; shaker = shaker->prev)
		{
			if (shaker->prev->n > shaker->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list(*list);
				swapped = 1; /* Use 1 instead of true */
			}
		}
	}
}
}
