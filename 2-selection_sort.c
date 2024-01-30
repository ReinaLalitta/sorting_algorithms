#include "sort.h"

/**
 * selection_sort - function for sorting an integer
 * array in ascending order
 * @array: The array to be sorted
 * @size: size of the given array
 * Return: returns nothing
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, temp, holdr = 0;

	for (i = 0; i < size; i++)
	{
		temp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
			}
		}
		if (temp != i)
		{
			holdr = array[i];
			array[i] = array[temp];
			array[temp] = holdr;
			print_array(array, size);
		}
	}
}
