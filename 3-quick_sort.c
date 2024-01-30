#include "sort.h"

/**
 * quick_sort - function for sorting integer
 * array in ascending order using quick sort
 * @array: array of integers to be sorted
 * @size: size of array to sort
 */

void quick_sort(int *array, size_t size)
{
	quick_sorting(array, size, array, size);
}

/**
 * quick_sorting - sorts array with quick sort
 * @array: array or subarray to sort
 * @size: size of array to sort
 * @full_array: full array for printing
 * @full_size: size of full array for printing
 */

void quick_sorting(int *array, size_t size, int *full_array, size_t full_size)
{
	size_t index = 0, pivot = size - 1, placeholdr = 0;
	int tmp = 0;

	if (size < 2 || array == NULL)
		return;
	for (index = 0; index < pivot; index++)
	{
		if (array[index] < array[pivot] && index == placeholdr)
			placeholdr++;
		else if (array[index] < array[pivot] && index != placeholdr)
		{
			tmp = array[index];
			array[index] = array[placeholdr];
			array[placeholdr] = tmp;
			placeholdr++;
			print_array(full_array, full_size);
		}
	}
	if (array[pivot] != array[placeholdr])
	{
		tmp = array[pivot];
		array[pivot] = array[placeholdr];
		array[placeholdr] = tmp;
		print_array(full_array, full_size);
	}

	/* lft side */
	quick_sorting(array, placeholdr, full_array, full_size);
	/* rght side */
	placeholdr += 1;
	quick_sorting(&array[placeholdr], size - placeholdr, full_array, full_size);
}
