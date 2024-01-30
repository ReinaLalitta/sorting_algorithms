#include "sort.h"

void swapping(listint_t **list, listint_t **shifter, listint_t **partner);

/**
 * cocktail_sort_list - function for sorting an integer
 * linked list with cocktail sort in ascending order
 * @list: pointer to head of listint_t doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int size = 0, count = 0;
	listint_t *partner = NULL, *shifter = NULL, *begin = NULL, *end = NULL;

	if (list == NULL)
		return;
	if ((*list) == NULL)
		return;
	shifter = (*list);
	begin = shifter;
	while (shifter)
	{
		size++;
		shifter = shifter->next;
	}
	shifter = begin;
	while (1)
	{
		while (shifter && shifter->next != end)
		{
			if (shifter == begin)
			{
				shifter = shifter->next;
				continue;
			}
			partner = shifter->prev;
			if (partner->n > shifter->n)
			{
				swapping(list, &shifter, &partner);
				shifter = shifter->next->next;
			}
			else
				shifter = shifter->next;
		}
		while (shifter->prev != NULL)
			shifter = shifter->prev;
		begin = shifter;
		while (shifter->next != NULL)
			shifter = shifter->next;
		end = shifter;
		while (shifter)
		{
			if (shifter->prev == NULL)
				break;
			partner = shifter->prev;
			if (partner->n > shifter->n)
				swapping(list, &shifter, &partner);
			else
				shifter = shifter->prev;
		}
		shifter = end;
		while (shifter->next != NULL)
			shifter = shifter->next;
		end = shifter;
		while (shifter->prev != NULL)
			shifter = shifter->prev;
		begin = shifter;
		count++;
		if (count >= size / 2)
			break;
	}

}

/**
 * swapping - swaps two nodes in doubly linked list
 * @list: pointer to head of full list
 * @shifter: pointer to shifter node to switch with partner
 * @partner: pointer to partner node to switch with shifter
 *
 */

void swapping(listint_t **list, listint_t **shifter, listint_t **partner)
{
	(*partner)->next = (*shifter)->next;
	(*shifter)->prev = (*partner)->prev;
	if ((*shifter)->next)
		(*shifter)->next->prev = (*partner);
	if ((*partner)->prev)
		(*partner)->prev->next = (*shifter);
	else
		(*list) = (*shifter);
	(*shifter)->next = (*partner);
	(*partner)->prev = (*shifter);
	print_list(*list);
}
