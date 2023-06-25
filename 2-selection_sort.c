#include "sort.h"

/**
 * selection_sort - A selection sort algorithm to sort an array
 * @array: A pointer to an array of integers
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, maximum;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		maximum = 0;
		for (j = 1; j < size - i; j++)
		{
			if (array[j] > array[maximum])
				maximum = j;
		}
		temp = array[size - 1 - i];
		array[size - 1 - i] = array[maximum];
		array[maximum] = temp;
		print_array(array, size);
	}
}
