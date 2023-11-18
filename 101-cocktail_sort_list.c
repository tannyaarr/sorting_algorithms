#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the doubly linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp;
	
	if (*a != NULL)
	{
		if ((*a)->prev != NULL)
			(*a)->prev->next = *b;
		else
			*list = *b;
		temp = (*b)->next;
		(*b)->next = *a;
		(*b)->prev = (*a)->prev;
		(*a)->next = temp;
		(*a)->prev = *b;

		if (temp != NULL)
			temp->prev = *a;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the cocktail shaker sort aalgorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;;

	if (list == NULL || *list == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, &curr, &curr->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;
		swapped = 0;
		curr = curr->prev;

		for (; curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, &curr->prev, &curr);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
