#·include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev_node = temp->prev;

			if (prev_node->prev != NULL)
				prev_node->prev->next = temp;
			else
				*list = temp;

			if (temp->next != NULL)
				temp->next->prev = prev_node;

			prev_node->next = temp->next;
			temp->prev = prev_node->prev;
			prev_node->prev = temp;
			temp->next = prev_node;

			print_list(*list);
		}
	}
}
