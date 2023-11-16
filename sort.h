#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insert_sorted(listint_t **head, listint_t **new_node);
listint_t *create_node(int n, listint_t *prev, listint_t *next);
int lomuto_partition(int *array, int low, int high);
void swap(int *a, int *b);
void quick_sort_recursive(int *array, int low, int hight);
void quick_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void shell_sort(int *array, size_t size);

#endif
