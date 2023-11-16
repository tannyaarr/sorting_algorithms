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
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/** 
 * quick_sort_recursive - Recursive funstion to sort an array using
 * Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index f the partition
 * @size: size of the array
 */

void quick_sort_recursive(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);

		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
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
	if (array == NULL || size <= 1)

	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1);
}
