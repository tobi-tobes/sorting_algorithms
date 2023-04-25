#include "sort.h"

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sigf: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 *
 * Return: Nothing
 */
void radix_counting_sort(int *array, size_t size, int sigf, int *buffer)
{
	int count[10] = {0};
	int j;
	size_t i;

	for (i = 0; i < size; ++i)
		count[(array[i] / sigf) % 10]++;

	for (i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	for (j = size - 1; j >= 0; --j)
		buffer[--count[(array[j] / sigf) % 10]] = array[j];

	for (i = 0; i < size; ++i)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, sigf, *buffer;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	sigf = 1;
	while (max / sigf > 0)
	{
		radix_counting_sort(array, size, sigf, buffer);
		print_array(array, size);
		sigf *= 10;
	}
	free(buffer);
}
