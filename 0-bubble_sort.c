#include "sort.h"
/**
 * bubble_sort - function for bubble sorting an array of integers
 * @array: The given array to sort
 * @size: The size of the array to sort
 */
void bubble_sort(int *array, size_t size)
{
	int chk = 1, temp = 0;
	unsigned int i = 0;

	while (chk)
	{
		chk = 0;
		for (i = 0; i < size; i++)
		{
			if (i == 0)
				continue;
			if (array[i] < array[i - 1])
			{
				chk = 1;
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				print_array(array, size);
			}
		}
	}
}
