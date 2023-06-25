#include "sort.h"

/**
 * selection_sort - A selection sort algorithm to sort an array
 * @array: A pointer to an array of integers
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, minimum;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		minimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
				minimum = j;
		}
		if (minimum != i)
		{
			temp = array[i];
			array[i] = array[minimum];
			array[minimum] = temp;
			print_array(array, size);
		}
	}
}
