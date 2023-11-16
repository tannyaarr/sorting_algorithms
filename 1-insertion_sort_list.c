#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: the neede to be swap
 * @node1: The first node
 * @node2: The second node
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: a pointer to a pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp, *print_node;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insert  = current;
		temp = insert->prev;
		while (temp != NULL && temp->n > insert->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = insert;
			if (insert->next != NULL)
				insert->next->prev = temp;
			temp->next = insert->next;
			insert->prev = temp->prev;
			insert->next = temp;
			temp->prev = insert;

			if (insert->prev == NULL)
				*list = insert;
			print_node = *list;
			while (print_node != NULL)
			{
				printf("%d", print_node->n);
				if (print_node->next != NULL)
					printf(", ");
				print_node = print_node->next;
			}
			printf("\n");
			temp = insert->prev;
		}

		current = current->next;
	}
}
