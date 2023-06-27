#include "sort.h"

/**
 * maxnum - A function that finds the largest number of an array given size
 * @array: A pointer to the array
 * @size: size of the array
 * Return: maximum number if successful
 */

int maxnum(int *array, size_t size)
{
	int max_number = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_number)
			max_number = array[i];
	}
	return (max_number);
}

/**
 * counting_sort - An algorithm for the sorting of an array using count sort
 * @array: A pointer to the array
 * @size: the size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	size_t max = maxnum(array, size);
	int *count;
	size_t i;
	int ind = 0;

	if (size < 2)
		return;

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	for (i = 0; i <= max; i++)
	{
		printf("%d, ", count[i]);
	}
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[ind] = i;
			count[i]--;
			ind++;
		}
	}
	free(count);
	print_array(array, size);
}
