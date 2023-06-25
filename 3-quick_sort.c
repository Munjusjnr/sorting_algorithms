#include "sort.h"

/**
 * swap - A swap function for my partition function
 * @x: A pointer to value x
 * @y: A pointer to value y
 * Return: void
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - A partition function based on the lomuto partition scheme
 * @array: A pointer to an array of integers
 * @first: first interger
 * @last: last integer
 * @size: size of the array
 * Return: void
 */

int partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last], y;
	int x = first;

	for (y = first; y < last; y++)
	{
		if (array[y] <= pivot)
		{
			swap(&array[x], &array[y]);
			if (x != y)
				print_array(array, size);
			x++;
		}
	}
	swap(&array[x], &array[y]);
	if (x != y)
		print_array(array, size);
	return (x);
}

/**
 * sortutil - A sorting function that would sort based on a pivot provided
 * @array: A pointer to an array of integers
 * @first: first integer of the array
 * @last: last integer of the array
 * @size: size of the array
 * Return: void
 */

void sortutil(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		sortutil(array, first, pivot - 1, size);
		sortutil(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - A quick sort algorithm for sorting array integers
 * @array: A pointer to an array of integers
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sortutil(array, 0, size - 1, size);
}
