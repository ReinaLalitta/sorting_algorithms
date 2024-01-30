#include "sort.h"

void merge_sort_recurse(int *buff, int *sub_array, size_t left, size_t right);
void merge_subarray(int *buff, int *sub_array, size_t left, size_t mid, size_t right);
void merge_sort(int *array, size_t size);

/**
 * merge_sort_recurse -function for implementing merge sort algorithm through recursion.
 * @buff: a buffer for storing the sorted results.
 * @sub_array: the integer sub array to be sorted
 * @left: the left index of the sub array
 * @right: the right index of the sub array
 */

void merge_sort_recurse(int *buff, int *sub_array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recurse(buff, sub_array, left, mid);
		merge_sort_recurse(sub_array, buff, mid, right);
		merge_subarray(buff, sub_array, left, mid, right);
	}

}

/**
 * merge_subarray - function for sorting an integer sub array
 * @buff: the buffer for storing sorted sub array
 * @sub_array: an integer sub array
 * @left: the left index of the sub array
 * @mid: the middle index of the sub array
 * @right: the right index of the sub array
 */

void merge_subarray(int *buff, int *sub_array, size_t left, size_t mid, size_t right)
{
	size_t j, i, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + left, mid - left);

	printf("[right]: ");
	print_array(sub_array + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
		buff[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < mid; i++)
		buff[k++] = sub_array[i];
	for (; j < right; j++)
		buff[k++] = sub_array[j];
	for (i = left, k = 0; i < right; i++)
		sub_array[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub_array + left, right - left);
}

/**
 * merge_sort - function for sorting an integer
 * array in ascending array using merge sort algorithm
 * @array: the integer array
 * @size: the size of the array
 *
 * Description: implemenrs top-down merge sort alorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recurse(array, buff, 0, size);

	free(buff);
}
