#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort using the Knuth sequence
 * @size gap: the size of the gap
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for ( i = gap; i < size; i++)
			{
				temp = array[i];
				j = i;
				while (j >= gap && array[j - gap] >temp)
				{
					array[j] = array[j - gap];
					j -= gap;
				}
				array[j] = temp;
			}
		printf("\nArray at gap %lu: ", gap);
		print_array(array, size);
		gap /= 3;
	}
}
