#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @head: A double pointer to the head of the list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 *
 * Description: This function swaps two adjacent nodes in a doubly linked list
 * and updates the head of the list if necessary.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*head = node2;
}

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending
 * @list: A double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
	}
}
