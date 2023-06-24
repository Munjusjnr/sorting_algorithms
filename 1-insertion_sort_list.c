#include "sort.h"

/**
 * insertion_sort_list - A sorting algorithm for sorting a doubly linked list
 * @list: A double pointer to the list to be arranged
 * Return: void if failure or list if successful
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		ptr = current->prev;
		while (ptr && ptr->n > current->n)
		{
			if (ptr->prev)
				ptr->prev->next = current;

			current->prev = ptr->prev;
			ptr->prev = current;
			ptr->next = current->next;

			if (current->next)
				current->next->prev = ptr;
			current->next = ptr;

			if (ptr == *list)
				*list = current;

			ptr = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
