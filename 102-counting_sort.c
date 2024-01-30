#include "sort.h"

/**
 * counting_sort - sorts an integer array in acending
 * @array: the array to be sorted
 * @size: the size of the given array
 * Return: returns nothing
 */

void counting_sort(int *array, size_t size)
{
	size_t counter = 0, tmp = 0, i = 0;
	int max = 0, *output = NULL, j = 0, *ct_arr = NULL;

	output = malloc(sizeof(int) * size);
	if (array == NULL || output == NULL)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	ct_arr = malloc(sizeof(int) * (max + 1));
	if (ct_arr == NULL)
	{
		free(output);
		return;
	}

	for (j = 0; j <= max; j++)
		/* setting zeroes in the array */
		ct_arr[j] = 0;
	for (i = 0; i < size; i++)
		/* storing count each element in index */
		ct_arr[array[i]]++;
	for (j = 0; j < max + 1; j++)
		/* storing the count */
	{
		tmp = ct_arr[j];
		ct_arr[j] += counter;
		counter += tmp;
	}
	print_array(ct_arr, max + 1);
	for (i = size - 1; i < size; i--)
		/* finding indexes in ct_arr, set in the output array */
	{
		output[ct_arr[array[i]] - 1] = array[i];
		ct_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		/* copying back to the array */
		array[i] = output[i];
	free(ct_arr);
	free(output);

}
