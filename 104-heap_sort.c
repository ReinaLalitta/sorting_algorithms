#include "sort.h"

void heap_sort(int *array, size_t size);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers in the given array.
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
