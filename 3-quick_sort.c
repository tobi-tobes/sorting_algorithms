#include "sort.h"

/**
 * sorted - checks if an array is already sorted
 * @array: array to check
 * @lower: lower bound of the array
 * @upper: upper bound of the array
 *
 * Return: 1 if array is sorted or 0 if not
 */
int sorted(int *array, int lower, int upper)
{
	int i, is_sorted = 1;
	(void)lower;

	for (i = 1; i < upper + 1; i++)
	{
		if (array[i] < array[i - 1])
		{
			is_sorted = 0;
			break;
		}
	}
	return (is_sorted);
}

/**
 * lomuto - implements quick sort algorithm using Lomuto partitioning
 * @array: array to be sorted
 * @lower: lower bound of the array
 * @upper: upper bound of the array
 * @size: size of the array
 *
 * Return: nothing
 */
void lomuto(int *array, int lower, int upper, size_t size)
{
	int i, j, pivot, temp;

	if (lower >= upper)
		return;

	pivot = array[upper];
	j = lower;
	for (i = lower; i < upper; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			j++;
		}
	}
	temp = array[upper];
	array[upper] = array[j];
	array[j] = temp;
	print_array(array, size);
	lomuto(array, lower, j - 1, size);
	lomuto(array, j + 1, upper, size);
}

/**
 * quick_sort - sorts an array of integers using Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int upper, lower;

	if (array == NULL || size < 2)
		return;

	upper = size - 1;
	lower = 0;
	lomuto(array, lower, upper, size);
}
