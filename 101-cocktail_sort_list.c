#include "sort.h"

/**
 * swap_next_node - swaps the next node
 * @list: list to change
 * @tail: pointer to end of the list
 * @head: pointer to the beginning of the list
 *
 * Return: nothing
 */
void swap_next_node(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *temp = (*head)->next;

	if ((*head)->prev != NULL)
		(*head)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*head)->prev;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *head;
	else
		*tail = *head;
	(*head)->prev = temp;
	temp->next = *head;
	*head = temp;
}

/**
 * swap_prev_node - swaps the previous node
 * @list: list to change
 * @tail: pointer to end of the list
 * @head: pointer to the beginning of the list
 *
 * Return: nothing
 */
void swap_prev_node(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *temp = (*head)->prev;

	if ((*head)->next != NULL)
		(*head)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*head)->next;
	(*head)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *head;
	else
		*list = *head;
	(*head)->next = temp;
	temp->prev = *head;
	*head = temp;
}

/**
 * cocktail_sort_list - sorts an array of integers using Cocktail sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swapped == 0)
	{
		swapped = 1;
		head = *list;
		while (head != tail)
		{
			if (head->n > head->next->n)
			{
				swap_next_node(list, &tail, &head);
				print_list(*list);
				swapped = 0;
			}
			head = head->next;
		}
		head = head->prev;
		while (head != *list)
		{
			if (head->n < head->prev->n)
			{
				swap_prev_node(list, &tail, &head);
				print_list(*list);
				swapped = 0;
			}
			head = head->prev;
		}
	}
}
