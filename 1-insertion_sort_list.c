#include "sort.h"

/**
 * insertion_sort_list - function that sorts doubly
 * linked list with insertion sort
 * @list: pointer to the head of listint_t linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *mover = NULL, *prevs = NULL, *place_hldr = NULL;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	prevs = (*list);
	if (prevs->next)
		mover = prevs->next;
	while (mover)
	{
		prevs = mover->prev;
		place_hldr = prevs;
		while (mover->n < prevs->n)
		{
			prevs->next = mover->next;
			mover->prev = prevs->prev;
			if (prevs->prev)
				prevs->prev->next = mover;
			if (mover->next)
				mover->next->prev = prevs;
			mover->next = prevs;
			prevs->prev = mover;
			if (mover->prev)
				prevs = mover->prev;
			else
			{
				(*list) = mover;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		if (mover->n < place_hldr->n)
			mover = place_hldr->next;
		else if (place_hldr->next)
			mover = place_hldr->next->next;
		else
			mover = place_hldr->next;
	}
}
