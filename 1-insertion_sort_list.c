#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			/* detach current */
			insert->next = current->next;
			if (current->next)
				current->next->prev = insert;

			/* move current before insert */
			current->prev = insert->prev;
			current->next = insert;

			if (insert->prev)
				insert->prev->next = current;
			else
				*list = current;

			insert->prev = current;

			print_list(*list);

			insert = current->prev;
		}
		current = next;
	}
}
