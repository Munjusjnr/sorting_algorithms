#include "sort.h"

/**
 * swap - A swap funtion that swap nodes of a doubly linked list
 * @list: A double pointer to a doubly linked list
 * @a: A pointer operand to a node
 * @b: A pointer operand to a node
 * Return: void
 */

void swap(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL)
		return;

	if (a == b)
		return;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	if (a->prev != NULL)
		a->prev->next = b;
	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (a->next == b)
		a->next = b->next;
	if (b->prev == a)
		b->prev = a->prev;
	if (b->prev == NULL)
		*list = b;
}
/**
 * cocktail_sort_list - A sorting algorithm which sorts elements of a list
 * in a bidirectional manner extending the bubble sort algorithm
 * @list: A double pointer to a doubly linked list
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *first = *list, *last = NULL;
	int swp = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	while (swp)
	{
		swp = 0;
		while (first->next != last)
		{
			if (first->n > first->next->n)
			{
				swap(list, first, first->next);
				swp = 1;
				print_list(*list);
			}
			else
			{
				first = first->next;
			}
		}
		if (!swp)
			break;
		swp = 0;
		last = first;
		while (first->prev != NULL)
		{
			if (first->n < first->prev->n)
			{
				swap(list, first->prev, first);
				swp = 1;
				print_list(*list);
			}
			else
			{
				first = first->prev;
			}
		}
	}
}
