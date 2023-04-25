#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers using Insertion sort
 * @list: list to be sorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *swap, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = temp)
	{
		temp = curr->next;
		swap = curr->prev;
		while (swap != NULL && curr->n < swap->n)
		{
			swap->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = swap;
			curr->prev = swap->prev;
			curr->next = swap;
			if (swap->prev != NULL)
				swap->prev->next = curr;
			else
				*list = curr;
			swap->prev = curr;
			swap = curr->prev;
			print_list(*list);
		}
	}
}
