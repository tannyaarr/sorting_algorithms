#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: the first integer to swap
 * @b: the second integer to swap
 * @temp: a temp integer
 */

void swap(int *a, int  *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partition the array using the lomuto  partition scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * Return: the index of the pivot element
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j, k;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			for (k = 0; k <= high; k++)
			{
				printf("%d, ", array[k]);
			}
			printf("\n");
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/** 
 * quick_sort_helper - Helper to the quick sort function
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index f the partition
 * @size: size of the array
 */

void quick_sort_helper(int *array, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high);

		quick_sort_helper(array, low, partition_index - 1);
		quick_sort_helper(array, partition_index + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using quick sort
 * @array: The array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
	
}
