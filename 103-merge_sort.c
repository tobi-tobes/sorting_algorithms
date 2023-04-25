#include "sort.h"

/**
 * print_output - prints output for merge_sorted function
 * @left_array: left subarray
 * @right_array: right subarray
 * @left_size: size of the left subarray
 * @right_size: size of the right subarray
 *
 * Return: nothing
 */
void print_output(int *left_array, int *right_array, size_t left_size,
		  size_t right_size)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left_size);
	printf("[right]: ");
	print_array(right_array, right_size);
}

/**
 * merge_sorted - merges the sorted subarrays
 * @array: array to be sorted
 * @lower: lower bound of the array
 * @midpoint: midpoint of the array
 * @upper: upper bound of the array
 *
 * Return: nothing
 */
void merge_sorted(int *array, int lower, int midpoint, int upper)
{
	size_t left_len, right_len, i, j;
	int right[200], left[200], k;

	left_len = (midpoint - lower) + 1;
	right_len = upper - midpoint;

	for (i = 0; i < left_len; i++)
		left[i] = array[lower + i];
	for (i = 0; i < right_len; i++)
		right[i] = array[midpoint + 1 + i];

	print_output(left, right, left_len, right_len);
	printf("[Done]: ");
	for (i = 0, j = 0, k = lower; k <= upper; k++)
	{
		if (i < left_len && (j >= right_len || left[i] <= right[j]))
		{
			array[k] = left[i];
			if (k == upper)
				printf("%d\n", array[k]);
			else
				printf("%d, ", array[k]);
			i++;
		}
		else
		{
			array[k] = right[j];
			if (k == upper)
				printf("%d\n", array[k]);
			else
				printf("%d, ", array[k]);
			j++;
		}
	}
}

/**
 * rec_merge_sort - implements merge sort algorithm recursively
 * @array: array to be sorted
 * @lower: lower bound of the array
 * @upper: upper bound of the array
 *
 * Return: nothing
 */
void rec_merge_sort(int *array, int lower, int upper)
{
	int mid;

	if (lower >= upper)
		return;

	mid = (lower + (upper - 1)) / 2;
	rec_merge_sort(array, lower, mid);
	rec_merge_sort(array, mid + 1, upper);
	merge_sorted(array, lower, mid, upper);
}

/**
 * merge_sort - sorts an array of integers using Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int l, u;

	if (array == NULL || size < 2)
		return;
	u = size - 1;
	l = 0;
	rec_merge_sort(array, l, u);
}
