#include "sort.h"

/**
 * counting_sort - sorts an array of integers using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int max, k, *count_arr, *output;
	size_t i, j;

	if (array == NULL || size == 0)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_arr = malloc(sizeof(int) * (max + 1));
	if (count_arr == NULL)
		return;
	for (k = 0; k < max + 1; k++)
		count_arr[k] = 0;
	for (j = 0; j < size; j++)
		count_arr[array[j]]++;
	for (k = 1; k < max + 1; k++)
		count_arr[k] += count_arr[k - 1];
	print_array(count_arr, max + 1);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count_arr);
	free(output);
}
