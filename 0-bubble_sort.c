#include "sort.h"

/**
 * swap - swap two integers
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: print the array after each time you swap two elements
 * @size: size of the integer
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i;

	if (array == NULL || size < 2)
	{
		return;
	}
	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				swapped = 1;
			}
		}
	} while (swapped);
}
