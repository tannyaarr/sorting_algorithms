#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps two integers
 * @a: The first integers to swap
 * @b: The second integer to swap
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	int i, j, k, min_idx;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < (int)size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			printf("%d", array[0]);
			for (k = 1; k < (int)size; k++)
			{
				printf(", %d", array[k]);
			}
			printf("\n");
		}
	}
}
